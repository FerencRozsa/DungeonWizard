// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUp.h"
#include "Components/SphereComponent.h"

// Sets default values
APickUp::APickUp()
{
	PrimaryActorTick.bCanEverTick = true;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUp::NotifyActorBeginOverlap(AActor * OtherActor)
{
	OnActivate(OtherActor);
	Destroy();
}



