// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/StageSelectHUD.h"
#include "Blueprint/UserWidget.h"

AStageSelectHUD::AStageSelectHUD()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> StageSelect(TEXT("/Game/Blueprints/UI/UI_StageSelectMain"));
	StageSelectClass = StageSelect.Class;
}

void AStageSelectHUD::BeginPlay()
{
	Super::BeginPlay();

	if (StageSelectClass != nullptr)
	{
		StageSelectWidget = CreateWidget<UUserWidget>(GetWorld(), StageSelectClass);
		StageSelectWidget->AddToViewport();
	}
}