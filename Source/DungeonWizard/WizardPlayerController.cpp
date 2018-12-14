// Fill out your copyright notice in the Description page of Project Settings.

#include "WizardPlayerController.h"
#include "Blueprint/UserWidget.h"

void AWizardPlayerController::BeginPlay()
{

	Super::BeginPlay();

	if (wMainMenu)
	{
		MyMainMenu = CreateWidget<UUserWidget>(this, wMainMenu);

		if (MyMainMenu)
		{
			MyMainMenu->AddToViewport();
			SetInputMode(FInputModeUIOnly());
			SetPause(true);
			bShowMouseCursor = true;
		}
	}

}

void AWizardPlayerController::CreateHealthBar()
{
	if (wPlayerHealthBar)
	{
		PlayerHealthBar = CreateWidget<UUserWidget>(this, wPlayerHealthBar);

		if (PlayerHealthBar)
		{
			PlayerHealthBar->AddToViewport();
		}
	}

	if (wPlayerAbilities)
	{
		PlayerAbilities = CreateWidget<UUserWidget>(this, wPlayerAbilities);

		if (PlayerAbilities)
		{
			PlayerAbilities->AddToViewport();
		}
	}
}
