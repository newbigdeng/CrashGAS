


#include "AbilitySystem/CC_AbilitySystemComponent.h"

#include "GameplayTags/CCTags.h"


void UCC_AbilitySystemComponent::OnGiveAbility(FGameplayAbilitySpec& AbilitySpec)
{
	Super::OnGiveAbility(AbilitySpec);

	HandleAutoActivatedAbility(AbilitySpec);
}

void UCC_AbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();
	
	FScopedAbilityListLock(*this);//加上锁，防止在访问时能力被移除
	
	for (const FGameplayAbilitySpec& ability:GetActivatableAbilities())
	{
		HandleAutoActivatedAbility(ability);
	}
}


void UCC_AbilitySystemComponent::HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec)
{
	if (!IsValid(AbilitySpec.Ability))return;

	for (const FGameplayTag& Tag:AbilitySpec.Ability->GetAssetTags())
	{
		if (Tag.MatchesTagExact(CCTags::CCAbilities::ActivateOnGiven))//找到这个特定标签
		{
			TryActivateAbility(AbilitySpec.Handle);
			return;
		}
	}
}
