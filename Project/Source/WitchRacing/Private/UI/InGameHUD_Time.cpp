// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InGameHUD_Time.h"
#include "MainGameMode.h"
#include "Components/TextBlock.h"

void UInGameHUD_Time::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	AMainGameMode* GameMode = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());

	Minutes->SetText(FText::AsNumber(GameMode->Minutes));
	Seconds->SetText(FText::AsNumber(GameMode->Seconds));
	MilliSeconds->SetText(FText::AsNumber(GameMode->MilliSeconds));
}