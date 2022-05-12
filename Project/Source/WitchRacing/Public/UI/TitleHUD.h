// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TitleHUD.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API ATitleHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	ATitleHUD();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Timer")
		TSubclassOf<class UUserWidget> TitleMenuClass;

	UPROPERTY(EditAnywhere, Category = "Timer")
		class UUserWidget* TitleMenuWidget;
};
