// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TitleHUD.h"
#include "Blueprint/UserWidget.h"

ATitleHUD::ATitleHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> TitleMenu(TEXT("/Game/Blueprints/UI/UI_TitleMenu"));
	TitleMenuClass = TitleMenu.Class;
}

void ATitleHUD::BeginPlay()
{
	Super::BeginPlay();

	if (TitleMenuClass != nullptr)
	{
		TitleMenuWidget = CreateWidget<UUserWidget>(GetWorld(), TitleMenuClass);
		TitleMenuWidget->AddToViewport();
	}
}
