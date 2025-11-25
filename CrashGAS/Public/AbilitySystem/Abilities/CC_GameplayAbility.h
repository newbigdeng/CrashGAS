// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CC_GameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class CRASHGAS_API UCC_GameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	//这个类可以作为GA的父类，下面这个函数能在每次激活能力是触发
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Crash | Debugs")
	bool bDrawDebugs = false;
};
