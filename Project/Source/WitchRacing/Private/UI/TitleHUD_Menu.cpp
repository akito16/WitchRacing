// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TitleHUD_Menu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UTitleHUD_Menu::NativeConstruct()
{
	Super::NativeConstruct();

	if (StartGameBtn)
	{
		StartGameBtn->OnClicked.AddDynamic(this, &UTitleHUD_Menu::StartGame);
	}

	if (ConfigBtn)
	{
		ConfigBtn->OnClicked.AddDynamic(this, &UTitleHUD_Menu::ConfigOpen);
	}

	if (QuitGameBtn)
	{
		QuitGameBtn->OnClicked.AddDynamic(this, &UTitleHUD_Menu::QuitGame);
	}
}

void UTitleHUD_Menu::StartGame()
{
	UGameplayStatics::OpenLevel(this, "StageSelect");
}

void UTitleHUD_Menu::ConfigOpen()
{

}

void UTitleHUD_Menu::QuitGame()
{
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (Controller)
	{
		Controller->ConsoleCommand("quit");
	}
}