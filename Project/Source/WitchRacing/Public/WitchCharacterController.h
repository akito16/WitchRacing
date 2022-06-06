// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WitchCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class WITCHRACING_API AWitchCharacterController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AWitchCharacterController();

	virtual void SetupInputComponent() override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UInGameMenu> MenuWidgetClass;

	UPROPERTY(EditAnywhere)
		class UInGameMenu* MenuCurrentWidget;

	UFUNCTION()
		void MenuToggle();
};
