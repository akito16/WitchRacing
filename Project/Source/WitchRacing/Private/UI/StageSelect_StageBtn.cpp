// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/StageSelect_StageBtn.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "Save/BestTimeSave.h"

void UStageSelect_StageBtn::NativeConstruct()
{
	Super::NativeConstruct();

	//ステージ選択ボタンを作成
	if (StartStageBtn)
	{
		StartStageBtn->OnClicked.AddDynamic(this, &UStageSelect_StageBtn::StartStage);
	}

	//ステージ名をセット
	StageNameText->SetText(StageName);

	//ステージ画像をセット
	StageImage->SetBrushFromTexture(StageTexture);
	
	//ベストタイムをボタンに表示
	UBestTimeSave* SaveGameInstance = Cast<UBestTimeSave>
		(UGameplayStatics::CreateSaveGameObject(UBestTimeSave::StaticClass()));
	SaveGameInstance = Cast<UBestTimeSave>(UGameplayStatics::LoadGameFromSlot("SaveData", 0));
	if (IsValid(SaveGameInstance))
	{
		int index = 0;
		if (SaveGameInstance->StageNames.Find(LevelName, index))
		{
			int Time = SaveGameInstance->BestTimes[index];
			int MilliSeconds = Time % 100;
			int Seconds = (Time / 100) % 60;
			int Minutes = Time / 6000;
			FString str = FString::Printf(TEXT("%02d:%02d:%02d"), Minutes, Seconds, MilliSeconds);
			BestTimeText->SetText(FText::FromString(str));
		}
	}
	else
	{
		BestTimeText->SetText(FText::AsNumber(0));
	}
	
}

//ステージを開く
void UStageSelect_StageBtn::StartStage()
{
	UGameplayStatics::OpenLevel(this, LevelName);
}