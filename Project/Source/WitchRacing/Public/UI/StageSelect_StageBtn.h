// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StageSelect_StageBtn.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API UStageSelect_StageBtn : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* StagePhoto;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName StageName;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* StartStageBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* StageNameText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UTextBlock* BestTimeText;

	UFUNCTION()
		void StartStage();

};
