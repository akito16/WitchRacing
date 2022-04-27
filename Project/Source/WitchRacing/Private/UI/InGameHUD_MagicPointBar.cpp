// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/InGameHUD_MagicPointBar.h"
#include "WitchCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UInGameHUD_MagicPointBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	AWitchCharacter* WitchCharacter = Cast<AWitchCharacter>(MyCharacter);

	MagicPointBar->SetPercent(WitchCharacter->GetMagicPoint());
	MPText->SetText(FText::AsPercent(WitchCharacter->GetMagicPoint()));
}