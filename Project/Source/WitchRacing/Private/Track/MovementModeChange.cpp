// Fill out your copyright notice in the Description page of Project Settings.


#include "Track/MovementModeChange.h"
#include "WitchCharacter.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMovementModeChange::AMovementModeChange()
{
    OverlapVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapVolume"));
    RootComponent = OverlapVolume;
    OnActorBeginOverlap.AddDynamic(this, &AMovementModeChange::OverlapBegins);

    ModeChangeParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ModeChangeParticle"));
    ModeChangeParticle->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    ModeChangeParticle->SetupAttachment(RootComponent);
}

void AMovementModeChange::OverlapBegins(AActor* MyOverlapActor, AActor* OtherActor)
{
    ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);

    if (OtherActor == MyCharacter)
    {
        AWitchCharacter* WitchCharacter = Cast<AWitchCharacter>(MyCharacter);
        WitchCharacter->MoveModeChange();
    }
}
