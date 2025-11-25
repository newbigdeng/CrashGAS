
#include "GameplayTags/CCTags.h"

namespace CCTags
{
	namespace CCAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary,"CCTags.CCAbilities.Primary" , "Tag For Primary Ability");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary,"CCTags.CCAbilities.Secondary" , "Tag For Secondary Ability");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary,"CCTags.CCAbilities.Tertiary" , "Tag For Tertiary Ability");
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven,"CCTags.CCAbilities.ActivateOnGiven" , "Tag For Activate On Given");
	}
	namespace Events
	{
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact,"CCTags.Events.Enemy.HitReact","Tag for HitReactEnemy");
		}
	}
}