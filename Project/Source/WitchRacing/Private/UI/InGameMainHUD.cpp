// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InGameMainHUD.h"
#include "Blueprint/UserWidget.h"
#include "WitchCharacter.h"
#include "Kismet/GameplayStatics.h"

AInGameMainHUD::AInGameMainHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> InGameTime(TEXT("/Game/Blueprints/UI/UI_Time"));
	InGameTimeClass = InGameTime.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> StartCount(TEXT("/Game/Blueprints/UI/UI_StartCount"));
	StartCountClass = StartCount.Class;

	static ConstructorHelpers::FClassFinder<UUserWidget> MagicPoint(TEXT("/Game/Blueprints/UI/UI_MPBar"));
	MagicPointClass = MagicPoint.Class;
}

void AInGameMainHUD::BeginPlay()
{
	Super::BeginPlay();

	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	AWitchCharacter* WitchCharacter = Cast<AWitchCharacter>(MyCharacter);

	//Timer
	if (InGameTimeClass != nullptr)
	{
		TimeCurrentWidget = CreateWidget<UUserWidget>(GetWorld(), InGameTimeClass);
		TimeCurrentWidget->AddToViewport();
	}
	//Start Count
	if (StartCountClass != nullptr)
	{
		StartCountCurrentWidget = CreateWidget<UUserWidget>(GetWorld(), StartCountClass);
		StartCountCurrentWidget->AddToViewport();
	}
	//Magic Point
	if (MagicPointClass != nullptr)
	{
		MagicPointCurrentWidget = CreateWidget<UUserWidget>(GetWorld(), MagicPointClass);
		MagicPointCurrentWidget->AddToViewport();
	}
}