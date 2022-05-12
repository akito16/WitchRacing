// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StageSelect_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API UStageSelect_MainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* StartStageBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ReturnTitleBtn;


	UFUNCTION()
		void StartStage();

	UFUNCTION()
		void ReturnTitle();

};
