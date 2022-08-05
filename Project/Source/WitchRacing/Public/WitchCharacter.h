// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "WitchCharacter.generated.h"

UCLASS()
class WITCHRACING_API AWitchCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWitchCharacter();

	float FullMagicPoint = 100.0f;
	float MagicPointPercentage = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MagicPoint")
		float MagicPoint = FullMagicPoint;

	UFUNCTION(Category = "MagicPoint")
		float GetMagicPoint();

	UFUNCTION(Category = "MagicPoint")
		void UpdateMagicPoint(float ChangeMagicPoint);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CheckPoint")
		int AllCheckPoint = 6;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CheckPoint")
		int CheckPointCount = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Timer")
		int GoalTime;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
		bool CharacterFlying;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
		bool bCanMoveChange;

	UFUNCTION(Category = "Movement")
		void BroomSpawn();

	UFUNCTION(Category = "Movement")
		void BroomDestroy();

	UFUNCTION(BlueprintPure, Category = "Movement")
		bool GetMovingMode();
	
	UFUNCTION(Category = "Movement")
		void FlyingChange();

	UFUNCTION(Category = "Movement")
		void RunningChange();

	UFUNCTION(Category = "Movement")
		void MoveModeChange();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* CameraComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Camera)
		class USpringArmComponent* SpringArmComp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<class AActor> BroomClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class AActor* BroomActor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	//Character Control
	void MoveForward(float Value);

	void MoveRight(float Value);

	void StartJump();
	void StopJump();

	void MainCamera();
	void SubCamera();

	void OverlookCameraOn();
	void OverlookCameraOff();
};
