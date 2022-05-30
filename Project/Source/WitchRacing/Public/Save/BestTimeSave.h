// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "BestTimeSave.generated.h"


UCLASS()
class WITCHRACING_API UBestTimeSave : public USaveGame
{
	GENERATED_BODY()
	
public:
	UBestTimeSave();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<FName> StageNames;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<float> BestTimes;
};
