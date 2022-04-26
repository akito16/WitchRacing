// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InGameMainHUD.h"
#include "Blueprint/UserWidget.h"

AInGameMainHUD::AInGameMainHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> InGameTime(TEXT("/Game/Blueprints/UI/UI_Time"));
	InGameTimeClass = InGameTime.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> StartCount(TEXT("/Game/Blueprints/UI/UI_StartCount"));
	StartCountClass = StartCount.Class;
}

void AInGameMainHUD::BeginPlay()
{
	Super::BeginPlay();

	if (InGameTimeClass != nullptr)
	{
		TimeCurrentWidget = CreateWidget<UUserWidget>(GetWorld(), InGameTimeClass);
		TimeCurrentWidget->AddToViewport();
	}

	if (StartCountClass != nullptr)
	{
		StartCountCurrentWidget = CreateWidget<UUserWidget>(GetWorld(), StartCountClass);
		StartCountCurrentWidget->AddToViewport();
	}
}