// Fill out your copyright notice in the Description page of Project Settings.

#include "InteractableTorch.h"

AInteractableTorch::AInteractableTorch()
{
	PrimaryActorTick.bCanEverTick = true;
	UStaticMeshComponent* StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Torch"));
}

void AInteractableTorch::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInteractableTorch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

