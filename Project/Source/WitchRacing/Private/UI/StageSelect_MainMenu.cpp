// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/StageSelect_MainMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UStageSelect_MainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	if (StartStageBtn)
	{
		StartStageBtn->OnClicked.AddDynamic(this, &UStageSelect_MainMenu::StartStage);
	}

	if (ReturnTitleBtn)
	{
		ReturnTitleBtn->OnClicked.AddDynamic(this, &UStageSelect_MainMenu::ReturnTitle);
	}
}

void UStageSelect_MainMenu::StartStage()
{
	UGameplayStatics::OpenLevel(this, "Tutorial_Stage");
}

void UStageSelect_MainMenu::ReturnTitle()
{
	UGameplayStatics::OpenLevel(this, "TitleLevel");
}