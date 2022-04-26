// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameHUD_Time.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API UInGameHUD_Time : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* Minutes;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* Seconds;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* MilliSeconds;
};
