// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/Player/CC_Primary.h"

#include "Engine/OverlapResult.h"

void UCC_Primary::HitBoxOverlapTest()
{
	TArray<AActor*>ActorToIgnore;
	ActorToIgnore.Add(GetAvatarActorFromActorInfo());

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActors(ActorToIgnore);
	
	FCollisionResponseParams ResponseParams;
	ResponseParams.CollisionResponse.SetAllChannels(ECR_Ignore);
	ResponseParams.CollisionResponse.SetResponse(ECC_Pawn,ECR_Block);
	
	TArray<FOverlapResult> OverlapResults;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(HitBoxRadius);

	FVector Forward = GetAvatarActorFromActorInfo()->GetActorForwardVector() * HitBoxRadius;
	FVector HitBoxLocation = GetAvatarActorFromActorInfo()->GetActorLocation()+Forward+FVector(0.0f,0.0f,HitBoxElevationOffset);

	GetWorld()->OverlapMultiByChannel(OverlapResults,HitBoxLocation,FQuat::Identity,
		ECC_Visibility,Sphere,QueryParams,ResponseParams);

	if (bDrawDebugs)
	{
		DrawDebugSphere(GetWorld(),HitBoxLocation,HitBoxRadius,16,FColor::Red,false,3.0f);

		for (const FOverlapResult& result:OverlapResults)
		{
			if (IsValid(result.GetActor()))
			{
				FVector DebugLocation = result.GetActor()->GetActorLocation();
				DebugLocation.Z += 100.f;
				DrawDebugSphere(GetWorld(),DebugLocation,30.f,16,FColor::Green,false,1.5f);
			}
		}
	}
}
