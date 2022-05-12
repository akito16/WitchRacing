// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "WitchCharacter.h"
#include "Kismet/GameplayStatics.h"

AMainGameMode::AMainGameMode()
{
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_WitchCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/

	Time = 0;
	StartTime = 5;
}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();

	NotMove();
	GetWorldTimerManager().SetTimer(StartTimerHandle, this, &AMainGameMode::StartCount, 1.0f, true);
}

//Time Score
void AMainGameMode::TimeMeasure()
{
	MilliSeconds = Time % 100;
	Minutes = Time / 6000;
	Seconds = (Time / 100) % 60;
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("%02d : %02d : %02d"), Minutes, Seconds, MilliSeconds));
	Time++;
}

//Start Count Down
void AMainGameMode::StartCount()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	StartTime--;
	switch (StartTime)
	{
	case 3:
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("%d"), StartTime));
		StartCountText = FString::FromInt(StartTime);
		if (StartSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, StartSound, MyCharacter->GetActorLocation());
		}
		break;
	case 2:
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("%d"), StartTime));
		StartCountText = FString::FromInt(StartTime);
		break;
	case 1:
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("%d"), StartTime));
		StartCountText = FString::FromInt(StartTime);
		break;
	case 0:
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::Printf(TEXT("START")));
		StartCountText = "START";
		CanMove();
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AMainGameMode::TimeMeasure, 0.01f, true);
		break;
	default:
		StartCountText = "";
		if (StartTime < 0)
		{
			GetWorldTimerManager().ClearTimer(StartTimerHandle);
		}
		break;
	}
}

void AMainGameMode::CanMove()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	Controller->SetIgnoreMoveInput(false);
	Controller->SetIgnoreLookInput(false);
}

void AMainGameMode::NotMove()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	Controller->SetIgnoreMoveInput(true);
	Controller->SetIgnoreLookInput(true);
}

