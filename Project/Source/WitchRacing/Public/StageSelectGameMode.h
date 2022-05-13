// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StageSelectGameMode.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API AStageSelectGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AStageSelectGameMode();

protected:
	virtual void BeginPlay() override;

};
