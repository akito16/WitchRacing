// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AMainGameMode();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USoundBase* StartSound;

	void CanMove();
	void NotMove();

public:
	void TimeMeasure();

	void StartCount();

	UPROPERTY(BlueprintReadOnly, Category = "Timer")
		FTimerHandle TimerHandle;

	UPROPERTY(BlueprintReadOnly)
		FTimerHandle StartTimerHandle;

	UPROPERTY(BlueprintReadOnly, Category = "StartTimer")
		int StartTime = 5;

	UPROPERTY(BlueprintReadOnly, Category = "StartTimer")
		FString StartCountText;

	UPROPERTY(BlueprintReadOnly, Category = "Timer")
		int Time = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Timer")
		int Minutes = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Timer")
		int Seconds = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Timer")
		int MilliSeconds = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CheckPoint")
		int AllCheckPoint;
};
