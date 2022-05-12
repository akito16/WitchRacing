// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleGameMode.h"
#include "Kismet/GameplayStatics.h"

ATitleGameMode::ATitleGameMode()
{

}

void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	Controller->SetInputMode(FInputModeUIOnly());
	Controller->bShowMouseCursor = true;
	Controller->SetIgnoreMoveInput(false);
	Controller->SetIgnoreLookInput(false);
}