// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CC_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
struct FGameplayTag;
UCLASS()
class CRASHGAS_API ACC_PlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly,Category = "Crash|Input")
	TArray<TObjectPtr<UInputMappingContext>>InputMappingContexts;

	UPROPERTY(EditDefaultsOnly,Category = "Crash|Input")
	TObjectPtr<UInputAction>JumpAction;

	UPROPERTY(EditDefaultsOnly,Category = "Crash|Input")
	TObjectPtr<UInputAction>LookAction;

	UPROPERTY(EditDefaultsOnly,Category = "Crash|Input")
	TObjectPtr<UInputAction>MoveAction;

	UPROPERTY(EditDefaultsOnly,Category = "Crash|Input|Ability")
	TObjectPtr<UInputAction>PrimaryAction;

	UPROPERTY(EditDefaultsOnly,Category = "Crash|Input|Ability")
	TObjectPtr<UInputAction>SecondaryAction;

	UPROPERTY(EditDefaultsOnly,Category = "Crash|Input|Ability")
	TObjectPtr<UInputAction>TertiaryAction;

	void Jump();
	void StopJump();
	void Look(const FInputActionValue& Value);
	void Move(const FInputActionValue& Value);
	void Primary();
	void Secondary();
	void Tertiary();

	void ActivateAbility(const FGameplayTag& Ability) const;
};
