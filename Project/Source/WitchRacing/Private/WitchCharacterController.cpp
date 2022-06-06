// Fill out your copyright notice in the Description page of Project Settings.


#include "WitchCharacterController.h"
#include "Blueprint/UserWidget.h"
#include "UI/InGameMenu.h"

AWitchCharacterController::AWitchCharacterController()
{
	bShowMouseCursor = false;

	static ConstructorHelpers::FClassFinder<UInGameMenu> MenuWidgetObj(TEXT("/Game/Blueprints/UI/UI_InGameMenu"));
	MenuWidgetClass = MenuWidgetObj.Class;
}

void AWitchCharacterController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Menu", IE_Pressed, this, &AWitchCharacterController::MenuToggle);
}

void AWitchCharacterController::MenuToggle()
{
	if (IsValid(MenuCurrentWidget))
	{
		MenuCurrentWidget->CloseUI();
		MenuCurrentWidget = nullptr;
	}
	else
	{
		MenuCurrentWidget = CreateWidget<UInGameMenu>(GetWorld(), MenuWidgetClass);
		if (IsValid(MenuCurrentWidget))
		{
			MenuCurrentWidget->OpenUI();
		}
	}
}