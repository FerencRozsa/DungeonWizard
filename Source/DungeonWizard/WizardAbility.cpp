// Fill out your copyright notice in the Description page of Project Settings.

#include "WizardAbility.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "Engine/World.h"

UWizardAbility::UWizardAbility()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UWizardAbility::BeginPlay()
{
	Super::BeginPlay();	
	SetCooldownOne = CooldownAbilityOne;
	SetCooldownTwo = CooldownAbilityTwo;
}


void UWizardAbility::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (canBeUsedAbilityOne == false)
	{
		CooldownAbilityOne -= DeltaTime;

		if (CooldownAbilityOne <= 0)
		{
			CooldownAbilityOne = SetCooldownOne;
			canBeUsedAbilityOne = true;
		}
	}

	if (canBeUsedAbilityTwo == false)
	{
		CooldownAbilityTwo -= DeltaTime;

		if (CooldownAbilityTwo <= 0)
		{
			CooldownAbilityTwo = SetCooldownTwo;
			canBeUsedAbilityTwo = true;
		}
	}

}

void UWizardAbility::AbilityOne()
{
	if (canBeUsedAbilityOne)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetOwner()->GetActorTransform());
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), AudioEffect, GetOwner()->GetActorLocation());
		canBeUsedAbilityOne = false;
	}	
}

void UWizardAbility::AbilityTwo()
{
	if (canBeUsedAbilityTwo)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetOwner()->GetActorTransform());
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), AudioEffect, GetOwner()->GetActorLocation());
		canBeUsedAbilityTwo = false;
	}
}