// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WizardPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DUNGEONWIZARD_API AWizardPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets") TSubclassOf<class UUserWidget> wMainMenu;
		UUserWidget* MyMainMenu;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets") TSubclassOf<class UUserWidget> wPlayerHealthBar;
		UUserWidget* PlayerHealthBar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets") TSubclassOf<class UUserWidget> wPlayerAbilities;
		UUserWidget* PlayerAbilities;


	virtual void BeginPlay() override;

	void CreateHealthBar();
};
