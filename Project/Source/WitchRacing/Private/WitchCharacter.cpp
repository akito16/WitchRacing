// Fill out your copyright notice in the Description page of Project Settings.


#include "WitchCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "UI/InGameMainHUD.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AWitchCharacter::AWitchCharacter()
{
	//Character Mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharaMesh(TEXT("/Game/Mannequin/Character/Mesh/SK_Mannequin_Female.SK_Mannequin_Female"));
	GetMesh()->SetSkeletalMesh(CharaMesh.Object);
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	static ConstructorHelpers::FClassFinder<UObject> AnimBPClass(TEXT("/Game/Mannequin/Animations/ThirdPerson_AnimBP"));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetAnimInstanceClass(AnimBPClass.Class);

	//Character Movement Setting
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->MaxWalkSpeed = 900.0f;
	GetCharacterMovement()->MaxFlySpeed = 1500.0f;
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 1.0f;

	//Main Camera Setting
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(GetMesh());

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(GetMesh());
	SpringArmComp->SetRelativeLocation(FVector(0.0f, 0.0f, 130.0f));

	CameraComp->AttachToComponent(SpringArmComp, FAttachmentTransformRules::KeepRelativeTransform);

	SpringArmComp->TargetArmLength = 250.0f;
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->bEnableCameraLag = false;

	//Broom Setting
	BroomClass = TSoftClassPtr<AActor>(FSoftClassPath(TEXT("/Game/Models/BP_Broom.BP_Broom_C"))).LoadSynchronous();
	BroomActor = nullptr;

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AWitchCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	MagicPoint = 100.0f;
	CheckPointCount = 0;

	CharacterFlying = false;
	bCanMoveChange = true;
}

// Called every frame
void AWitchCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CharacterFlying)
	{
		if (MagicPoint == 0.0f)
		{
			RunningChange();
		}
		UpdateMagicPoint(-5.0f * DeltaTime);
	}

}

// Called to bind functionality to input
void AWitchCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AWitchCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AWitchCharacter::MoveRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AWitchCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AWitchCharacter::StopJump);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LockUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("BackMirror", IE_Pressed, this, &AWitchCharacter::SubCamera);
	PlayerInputComponent->BindAction("BackMirror", IE_Released, this, &AWitchCharacter::MainCamera);

	PlayerInputComponent->BindAction("Fly", IE_Pressed, this, &AWitchCharacter::MoveModeChange);
}

void AWitchCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator CharacterRotation(Rotation.Pitch, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(CharacterRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AWitchCharacter::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator CharacterRotation(Rotation.Pitch, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(CharacterRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AWitchCharacter::StartJump()
{
	bPressedJump = true;
}

void AWitchCharacter::StopJump()
{
	bPressedJump = false;
}

//MagicPoint
float AWitchCharacter::GetMagicPoint()
{
	return MagicPointPercentage;
}

void AWitchCharacter::UpdateMagicPoint(float ChangeMagicPoint)
{
	MagicPoint += ChangeMagicPoint;
	MagicPoint = FMath::Clamp(MagicPoint, 0.0f, FullMagicPoint);
	MagicPointPercentage = MagicPoint / FullMagicPoint;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("HP : %f"), MagicPoint));
}

void AWitchCharacter::BroomSpawn()
{
	const FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, false);
	if (BroomClass != nullptr)
	{
		if (BroomActor == nullptr)
		{
			BroomActor = GetWorld()->SpawnActor<AActor>(BroomClass);
			BroomActor->AttachToComponent(GetMesh(), AttachmentRules, "BroomPosition");
		}
	}
}

void AWitchCharacter::BroomDestroy()
{
	BroomActor->Destroy();
	BroomActor = nullptr;
}

//Flying
bool AWitchCharacter::GetMovingMode()
{
	return CharacterFlying;
}

void AWitchCharacter::FlyingChange()
{
	if (0.0f < MagicPoint)
	{
		CharacterFlying = true;
		BroomSpawn();

		GetCharacterMovement()->SetMovementMode(MOVE_Flying);

		bUseControllerRotationPitch = true;
	}
}

void AWitchCharacter::RunningChange()
{
	CharacterFlying = false;

	GetCapsuleComponent()->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));

	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	bUseControllerRotationPitch = false;
}

void AWitchCharacter::MoveModeChange()
{
	if (bCanMoveChange)
	{
		if (CharacterFlying)
		{
			RunningChange();
			BroomDestroy();
		}
		else
		{
			FlyingChange();
		}
	}
}

//Camera Change
void AWitchCharacter::MainCamera()
{
	SpringArmComp->TargetArmLength = 250.0f;
	CameraComp->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
}

void AWitchCharacter::SubCamera()
{
	SpringArmComp->TargetArmLength = -250.0f;
	CameraComp->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
}