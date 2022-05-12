// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/StageSelect_StageBtn.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UStageSelect_StageBtn::NativeConstruct()
{
	Super::NativeConstruct();

	if (StartStageBtn)
	{
		StartStageBtn->OnClicked.AddDynamic(this, &UStageSelect_StageBtn::StartStage);
	}
}

void UStageSelect_StageBtn::StartStage()
{
	UGameplayStatics::OpenLevel(this, StageName);
}