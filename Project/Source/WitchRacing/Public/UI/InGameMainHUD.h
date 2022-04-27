// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InGameMainHUD.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API AInGameMainHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AInGameMainHUD();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Timer")
		TSubclassOf<class UUserWidget> InGameTimeClass;

	UPROPERTY(EditAnywhere, Category = "Timer")
		class UUserWidget* TimeCurrentWidget;

	UPROPERTY(EditAnywhere, Category = "StartTimer")
		TSubclassOf<class UUserWidget> StartCountClass;

	UPROPERTY(EditAnywhere, Category = "StartTimer")
		class UUserWidget* StartCountCurrentWidget;

	UPROPERTY(EditAnywhere, Category = "MagicPoint")
		TSubclassOf<class UUserWidget> MagicPointClass;

	UPROPERTY(EditAnywhere, Category = "MagicPoint")
		class UUserWidget* MagicPointCurrentWidget;
};
