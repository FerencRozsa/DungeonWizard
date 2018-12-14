// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableTorch.generated.h"

UCLASS()
class DUNGEONWIZARD_API AInteractableTorch : public AActor
{
	GENERATED_BODY()
	
public:	

	AInteractableTorch();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* StaticMesh;

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	
	
};
