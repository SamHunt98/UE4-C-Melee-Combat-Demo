// Fill out your copyright notice in the Description page of Project Settings.

#include "AttackNotifyState.h"
#include "cppSlasherCharacter.h"
#include "Runtime/Engine/Public/EngineGlobals.h"

//notifies for when the attack colliders should be activated/deactivated during each swing. Attack logic is only active between these notifies.
void UAttackNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	//GEngine->AddOnScreenDebugMessage(-1, 4.5f, FColor::Magenta, __FUNCTION__);
	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		AcppSlasherCharacter* playerChar = Cast<AcppSlasherCharacter>(MeshComp->GetOwner());
		if (playerChar != NULL)
		{
			playerChar->StartAttack();
		}
	}
}

void UAttackNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	//GEngine->AddOnScreenDebugMessage(-1, 4.5f, FColor::Magenta, __FUNCTION__);
	if (MeshComp != NULL && MeshComp->GetOwner() != NULL)
	{
		AcppSlasherCharacter* playerChar = Cast<AcppSlasherCharacter>(MeshComp->GetOwner());
		if (playerChar != NULL)
		{
			playerChar->EndAttack();
		}
	}
}

