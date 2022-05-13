// Fill out your copyright notice in the Description page of Project Settings.


#include "Track/GoalLine.h"
#include "WitchCharacter.h"
#include "MainGameMode.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AGoalLine::AGoalLine()
{
    GoalLineVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("GoalLineVolume"));
    RootComponent = GoalLineVolume;
    OnActorBeginOverlap.AddDynamic(this, &AGoalLine::GoalLineOverlap);

    static ConstructorHelpers::FClassFinder<UUserWidget> Goal(TEXT("/Game/Blueprints/UI/UI_Goal"));
    GoalClass = Goal.Class;
}

void AGoalLine::GoalLineOverlap(AActor* MyOverlapActor, AActor* OtherActor)
{
    ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
    AMainGameMode* GameMode = Cast<AMainGameMode>(GetWorld()->GetAuthGameMode());

    if (OtherActor == MyCharacter)
    {
        AWitchCharacter* WitchCharacter = Cast<AWitchCharacter>(MyCharacter);
        if (WitchCharacter->CheckPointCount == GameMode->AllCheckPoint)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, FString::Printf(TEXT("GOAL")));
            GetWorldTimerManager().ClearTimer(GameMode->TimerHandle);

            if (GoalClass != nullptr)
            {
                APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
                Controller->SetInputMode(FInputModeUIOnly());
                Controller->bShowMouseCursor = true;
                Controller->SetIgnoreMoveInput(false);
                Controller->SetIgnoreLookInput(false);

                GoalWidget = CreateWidget<UUserWidget>(GetWorld(), GoalClass);
                GoalWidget->AddToViewport();
            }
        }
    }
}