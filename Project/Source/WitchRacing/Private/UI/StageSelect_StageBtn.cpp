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

	//�X�e�[�W�I���{�^�����쐬
	if (StartStageBtn)
	{
		StartStageBtn->OnClicked.AddDynamic(this, &UStageSelect_StageBtn::StartStage);
	}

	//�X�e�[�W�����Z�b�g
	StageNameText->SetText(StageName);

	//�X�e�[�W�摜���Z�b�g
	StageImage->SetBrushFromTexture(StageTexture);
	
	//�x�X�g�^�C�����{�^���ɕ\��
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

//�X�e�[�W���J��
void UStageSelect_StageBtn::StartStage()
{
	UGameplayStatics::OpenLevel(this, LevelName);
}