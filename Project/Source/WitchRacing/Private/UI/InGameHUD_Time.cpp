// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InGameHUD_Time.h"
#include "MainGameMode.h"
#include "Components/TextBlock.h"

void UInGameHUD_Time::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	AMainGameMode* GameMode = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());

	int Minutes = GameMode->Minutes;
	int Seconds = GameMode->Seconds;
	int MilliSeconds = GameMode->MilliSeconds;
	FString str = FString::Printf(TEXT("%02d:%02d:%02d"), Minutes, Seconds, MilliSeconds);
	Time->SetText(FText::FromString(str));
}