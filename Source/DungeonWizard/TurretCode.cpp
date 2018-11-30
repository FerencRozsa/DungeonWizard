// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretCode.h"


// Sets default values
ATurretCode::ATurretCode()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATurretCode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurretCode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurretCode::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

