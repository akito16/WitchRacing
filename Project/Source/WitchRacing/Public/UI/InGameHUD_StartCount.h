// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameHUD_StartCount.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API UInGameHUD_StartCount : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* StartCount;

};
