// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

class USphereComponent;

UCLASS()
class DUNGEONWIZARD_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	

	APickUp();
	void NotifyActorBeginOverlap(AActor * OtherActor);

	UFUNCTION(BlueprintImplementableEvent, Category = "Pickup")
		void OnActivate(AActor* pickedUpBy);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere, Category = Gameplay)
		float healthGained;
	UPROPERTY(EditAnywhere, Category = Gameplay)
		float staminaGained;
	UPROPERTY(EditAnywhere, Category = Gameplay)
		float rageGained;


protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	
	
};
