// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUp.h"
#include "Components/SphereComponent.h"
#include "DungeonWizardCharacter.h"
#include "Kismet/GameplayStatics.h"

APickUp::APickUp()
{
	PrimaryActorTick.bCanEverTick = true;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	RespawnTimer = 7;
}

void APickUp::BeginPlay()
{
	Super::BeginPlay();
}

void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PickedUp)
	{
		RespawnTimer -= DeltaTime;
		
		if (RespawnTimer <= 0)
		{
			RespawnPickUp();
		}
	}
}

void APickUp::NotifyActorBeginOverlap(AActor * OtherActor)
{

	OnActivate(OtherActor);
	ADungeonWizardCharacter* Character = Cast<ADungeonWizardCharacter>(OtherActor);
	Character->CurrentHealth += healthGained;
	Character->Rage += rageGained;
	Character->CurrentStamina += staminaGained;
	
	DestroyPickUp();
}

void APickUp::RespawnPickUp()
{
	RespawnTimer = 7;
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	PickedUp = false;
}

void APickUp::DestroyPickUp()
{
	PickedUp = true;
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

