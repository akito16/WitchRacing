// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleHUD_Menu.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API UTitleHUD_Menu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* StartGameBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* ConfigBtn;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
		class UButton* QuitGameBtn;

	UFUNCTION()
		void StartGame();

	UFUNCTION()
		void ConfigOpen();

	UFUNCTION()
		void QuitGame();
};
