// Fill out your copyright notice in the Description page of Project Settings.


#include "StageSelectGameMode.h"
#include "Kismet/GameplayStatics.h"

AStageSelectGameMode::AStageSelectGameMode()
{

}

void AStageSelectGameMode::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	Controller->SetInputMode(FInputModeUIOnly());
	Controller->bShowMouseCursor = true;
	Controller->SetIgnoreMoveInput(false);
	Controller->SetIgnoreLookInput(false);
}