// Fill out your copyright notice in the Description page of Project Settings.


#include "Track/CheckPoint.h"
#include "WitchCharacter.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACheckPoint::ACheckPoint()
{
    CheckPointVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapVolume"));
    RootComponent = CheckPointVolume;
    OnActorBeginOverlap.AddDynamic(this, &ACheckPoint::CheckPointOverlap);
}

void ACheckPoint::CheckPointOverlap(AActor* MyOverlapActor, AActor* OtherActor)
{
    Destroy();
    ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

    if (OtherActor == MyCharacter)
    {
        AWitchCharacter* WitchCharacter = Cast<AWitchCharacter>(MyCharacter);
        WitchCharacter->CheckPointCount++;
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("Check Point : %d"), WitchCharacter->CheckPointCount));
    }
}
