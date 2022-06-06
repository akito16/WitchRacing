// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API UInGameMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ReturnGameBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* QuitGameBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* RestartBtn;

	UFUNCTION()
		void OpenUI();

	UFUNCTION()
		void CloseUI();

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
		void ReturnGame();

	UFUNCTION()
		void QuitGame();

	UFUNCTION()
		void Restart();

	UFUNCTION()
		void SetUIOnly();

	UFUNCTION()
		void SetGameOnly();
};
