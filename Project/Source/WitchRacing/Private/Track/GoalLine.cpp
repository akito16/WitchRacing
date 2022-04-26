// Fill out your copyright notice in the Description page of Project Settings.


#include "Track/GoalLine.h"
#include "WitchCharacter.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGoalLine::AGoalLine()
{
    GoalLineVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("GoalLineVolume"));
    RootComponent = GoalLineVolume;
    OnActorBeginOverlap.AddDynamic(this, &AGoalLine::GoalLineOverlap);
}

void AGoalLine::GoalLineOverlap(AActor* MyOverlapActor, AActor* OtherActor)
{
    ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

    if (OtherActor == MyCharacter)
    {
        AWitchCharacter* WitchCharacter = Cast<AWitchCharacter>(MyCharacter);
        if (WitchCharacter->CheckPointCount == WitchCharacter->AllCheckPoint)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("GOAL")));
        }
    }
}