// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TitleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API ATitleGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ATitleGameMode();

protected:
	virtual void BeginPlay() override;

};
