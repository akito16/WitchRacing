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
		UTexture2D* StageTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText StageName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName LevelName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UImage* StageImage;

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
