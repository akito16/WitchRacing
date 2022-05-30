// Fill out your copyright notice in the Description page of Project Settings.


#include "Track/GoalLine.h"
#include "WitchCharacter.h"
#include "MainGameMode.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "Save/BestTimeSave.h"

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

        //Clear Widget Add
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

        //Best Time Update
        UBestTimeSave* SaveGameInstance = Cast<UBestTimeSave>
            (UGameplayStatics::CreateSaveGameObject(UBestTimeSave::StaticClass()));
        SaveGameInstance = Cast<UBestTimeSave>(UGameplayStatics::LoadGameFromSlot("SaveData", 0));
        if (!IsValid(SaveGameInstance))
        {
            SaveGameInstance = Cast<UBestTimeSave>(UGameplayStatics::CreateSaveGameObject(UBestTimeSave::StaticClass()));
            int index = 0;
            FString NowMap = UGameplayStatics::GetCurrentLevelName(GetWorld(), true);
            if (SaveGameInstance->StageNames.Find(FName(NowMap), index))
            {
                SaveGameInstance->BestTimes[index] = GameMode->Time;
            }
            UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveData"), 0);
        }
        else
        {
            int index = 0;
            FString NowMap = UGameplayStatics::GetCurrentLevelName(GetWorld(), true);
            if (SaveGameInstance->StageNames.Find(FName(NowMap), index))
            {
                float BestTime = SaveGameInstance->BestTimes[index];
                if (BestTime == 0 || GameMode->Time < BestTime)
                {
                    SaveGameInstance->BestTimes[index] = GameMode->Time;
                    UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("SaveData"), 0);
                }
            }
        }
    }
}