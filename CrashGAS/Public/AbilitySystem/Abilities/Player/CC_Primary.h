// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/CC_GameplayAbility.h"
#include "CC_Primary.generated.h"

/**
 * 
 */
UCLASS()
class CRASHGAS_API UCC_Primary : public UCC_GameplayAbility
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category = "Crash|Abilitis")
	void HitBoxOverlapTest();

private:
	UPROPERTY(EditDefaultsOnly,Category = "Crash|Abilities")
	float HitBoxRadius = 100.f;//半径

	UPROPERTY(EditDefaultsOnly,Category = "Crash|Abilities")
	float HitBoxForwardOffset = 200.f;//向前

	UPROPERTY(EditDefaultsOnly,Category = "Crash|Abilities")
	float HitBoxElevationOffset = 20.f;//上偏
};
