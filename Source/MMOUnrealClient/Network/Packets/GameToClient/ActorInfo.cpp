// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorInfo.h"
#include "Model/Actor/GameActor.h"
#include "Model/WorldInstance.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "GameFramework/CharacterMovementComponent.h"

/**
 * @author Dego1n
 */
ActorInfo::ActorInfo(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] ActorInfo"));
	#endif
	this->Handle();
}

ActorInfo::~ActorInfo()
{
}

void ActorInfo::Handle()
{
	int32 objectId = ReadD();
	int32 templateId = ReadD();

	int32 locationX = ReadD();
	int32 locationY = ReadD();
	int32 locationZ = ReadD();

	int32 collisionHeight = ReadD();
	int32 collisionRadius = ReadD();

	bool isFriendly = ReadH() == 0 ? false : true;
	int32 currentHp = ReadD();
	int32 maxHp = ReadD();

	FVector locationVector;
	locationVector.X = locationX;
	locationVector.Y = locationY;
	locationVector.Z = locationZ;

	FString name = ReadS();
	int32 attackSpeed = ReadD();
	int32 moveSpeed = ReadD();
	int16 hasQuests = ReadH();

		FFunctionGraphTask::CreateAndDispatchWhenReady([this, objectId, locationVector, name, templateId, isFriendly, collisionHeight, collisionRadius, currentHp, maxHp, attackSpeed, moveSpeed, hasQuests]() {
		
		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(objectId);

		if(actor == nullptr)
		{
			actor = GameSocketThread::Runnable->world->SpawnActor<AGameActor>();
			WorldInstance::GetInstance()->AddPlayerToWorld(actor);

			actor->id = objectId;
			actor->race = NULL; //TODO: ?
			actor->templateId = templateId;
			actor->UpdateCollision(collisionHeight, collisionRadius);
			actor->isNpc = true;
			actor->isFriendly = isFriendly;
			actor->UpdateSkeletalMesh();
			actor->LoadAnimations();
			actor->SpawnDefaultController();
			actor->AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
			#if !UE_BUILD_SHIPPING
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("ACTOR IS NULLPTR"));
			#endif
		}
		
		
		actor->SetActorLocation(locationVector);

		
		actor->UpdateName(name);
		actor->attackSpeed = attackSpeed;
		actor->moveSpeed = moveSpeed;
		actor->currentHp = float(currentHp);
		actor->maxHp = float(maxHp);
		actor->GetCharacterMovement()->MaxWalkSpeed = moveSpeed;
		switch (hasQuests)
		{
			case 1:
				actor->ShowExclamationMark(true);
				actor->ShowLootBag(false);
				break;
			case 2:
				actor->ShowExclamationMark(false);
				actor->ShowLootBag(true);
				break;
			default:
				actor->ShowExclamationMark(false);
				actor->ShowLootBag(false);
				break;
		}
		

		//Если это цель - обновляем статы
		if (GameSocketThread::Runnable->character->GetCurrentTarget() == actor)
		{
			GameSocketThread::Runnable->character->TargetSelected(actor);
		}


	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}
