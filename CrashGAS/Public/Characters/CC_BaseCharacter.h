
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CC_BaseCharacter.generated.h"


class UGameplayAbility;
UCLASS(Abstract)//设为抽象类，不会被实例化
class CRASHGAS_API ACC_BaseCharacter : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ACC_BaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;//交给玩家类和敌人类去实现
protected:
	void GiveStartUpAbilities();
private:
	UPROPERTY(EditDefaultsOnly,Category = "Crash|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> StartUpAbilities;
};
