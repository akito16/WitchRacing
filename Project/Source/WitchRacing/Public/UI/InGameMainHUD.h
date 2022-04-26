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
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> InGameTimeClass;

	UPROPERTY(EditAnywhere)
		class UUserWidget* TimeCurrentWidget;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> StartCountClass;

	UPROPERTY(EditAnywhere)
		class UUserWidget* StartCountCurrentWidget;
};
