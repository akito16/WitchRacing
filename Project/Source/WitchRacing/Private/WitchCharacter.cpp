// Fill out your copyright notice in the Description page of Project Settings.


#include "WitchCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

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

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWitchCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWitchCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
}

void AWitchCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AWitchCharacter::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
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
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("HP : %f"), MagicPoint));
}

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