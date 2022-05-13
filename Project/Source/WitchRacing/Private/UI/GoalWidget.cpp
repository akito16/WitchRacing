// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GoalWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UGoalWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (TitleBtn)
	{
		TitleBtn->OnClicked.AddDynamic(this, &UGoalWidget::ReturnTitle);
	}
	if (StageSelectBtn)
	{
		StageSelectBtn->OnClicked.AddDynamic(this, &UGoalWidget::ReturnStageSelect);
	}
}

void UGoalWidget::ReturnTitle()
{
	UGameplayStatics::OpenLevel(this, "TitleLevel");
}

void UGoalWidget::ReturnStageSelect()
{
	UGameplayStatics::OpenLevel(this, "StageSelect");
}