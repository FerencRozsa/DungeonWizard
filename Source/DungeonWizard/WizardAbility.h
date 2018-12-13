// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WizardAbility.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DUNGEONWIZARD_API UWizardAbility : public UActorComponent
{
	GENERATED_BODY()

public:	

	UWizardAbility();

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		class USphereComponent* CollisionComp;

	UPROPERTY(EditDefaultsOnly, Category = "FX")
		class UParticleSystem* ExplosionEffect;

	UPROPERTY(EditDefaultsOnly, Category = "FX")
		class USoundBase* AudioEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float CooldownAbilityOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		float CooldownAbilityTwo;

	float SetCooldownOne;
	float SetCooldownTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool canBeUsedAbilityOne = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		bool canBeUsedAbilityTwo = true;

protected:

	virtual void BeginPlay() override;

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	FORCEINLINE class USphereComponent* GetCollisionComp() const { return CollisionComp; }

	UFUNCTION(BlueprintCallable)
		void AbilityOne();
	
	UFUNCTION(BlueprintCallable)
		void AbilityTwo();
};
