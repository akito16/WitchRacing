// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InGameMenu.h"
#include "WitchCharacterController.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UInGameMenu::NativeConstruct()
{
	if (ReturnGameBtn)
	{
		ReturnGameBtn->OnClicked.AddDynamic(this, &UInGameMenu::ReturnGame);
	}
	if (QuitGameBtn)
	{
		QuitGameBtn->OnClicked.AddDynamic(this, &UInGameMenu::QuitGame);
	}
}

void UInGameMenu::OpenUI()
{
	AddToViewport();
	SetUIOnly();
	UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void UInGameMenu::CloseUI()
{
	RemoveFromParent();
	SetGameOnly();
	UGameplayStatics::SetGamePaused(GetWorld(), false);
}

void UInGameMenu::ReturnGame()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AWitchCharacterController* WCController = Cast<AWitchCharacterController>(Controller);
	WCController->MenuToggle();
}

void UInGameMenu::QuitGame()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (IsValid(Controller))
	{
		Controller->ConsoleCommand("quit");
	}
}

void UInGameMenu::Restart()
{

}

void UInGameMenu::SetUIOnly()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (IsValid(Controller))
	{
		Controller->SetInputMode(FInputModeUIOnly());
		Controller->bShowMouseCursor = true;
		Controller->SetIgnoreMoveInput(false);
		Controller->SetIgnoreLookInput(false);
	}
}

void UInGameMenu::SetGameOnly()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (IsValid(Controller))
	{
		Controller->SetInputMode(FInputModeGameOnly());
		Controller->bShowMouseCursor = false;
		Controller->SetIgnoreMoveInput(false);
		Controller->SetIgnoreLookInput(false);
	}
}