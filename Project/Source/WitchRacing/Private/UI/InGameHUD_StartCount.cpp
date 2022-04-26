// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InGameHUD_StartCount.h"
#include "MainGameMode.h"
#include "Components/TextBlock.h"

void UInGameHUD_StartCount::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	AMainGameMode* GameMode = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());

	StartCount->SetText(FText::FromString(GameMode->StartCountText));
}