

#include "CrashGAS/Public/Characters/CC_BaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameplayAbilitySpec.h"


ACC_BaseCharacter::ACC_BaseCharacter()
{
	//不使用tick
	PrimaryActorTick.bCanEverTick = false;

	//对于骨骼和动画要每秒刷新
	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* ACC_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void ACC_BaseCharacter::GiveStartUpAbilities()
{
	if (!IsValid(GetAbilitySystemComponent()))return;
	for (const auto& Ability:StartUpAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);//这个是GA能力的实例
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	}
}


