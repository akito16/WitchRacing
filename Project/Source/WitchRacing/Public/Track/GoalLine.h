// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "GoalLine.generated.h"

UCLASS()
class WITCHRACING_API AGoalLine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGoalLine();

	UFUNCTION()
		void GoalLineOverlap(AActor* MyOverlapActor, AActor* OtherActor);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* GoalLineVolume;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UParticleSystemComponent* GoalParticle;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> GoalClass;

	UPROPERTY(EditAnywhere)
		class UUserWidget* GoalWidget;

};
