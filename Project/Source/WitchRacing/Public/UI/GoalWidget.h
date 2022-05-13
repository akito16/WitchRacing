// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GoalWidget.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API UGoalWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* TitleBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* StageSelectBtn;

	UFUNCTION()
		void ReturnTitle();

	UFUNCTION()
		void ReturnStageSelect();

};
