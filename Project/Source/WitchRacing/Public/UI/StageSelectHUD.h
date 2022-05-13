// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "StageSelectHUD.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API AStageSelectHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AStageSelectHUD();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> StageSelectClass;

	UPROPERTY(EditAnywhere)
		class UUserWidget* StageSelectWidget;
};
