// MMOClient 2019


#include "ActorDied.h"
#include "Model/Actor/GameActor.h"
#include "Model/WorldInstance.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Model/Struct/LootObjectStruct.h"

/**
 * @author Dego1n
 */
ActorDied::ActorDied(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] ActorDied"));
#endif
	this->Handle();
}

ActorDied::~ActorDied()
{
}

void ActorDied::Handle()
{
	int32 objectId = ReadD();
	int32 secondsToFade = ReadD();
	int16 lootSize = ReadH();
	TArray<LootObjectStruct> lootTable;
	for (int16 i = 0; i < lootSize; i++)
	{
		LootObjectStruct loot;
		loot.object_id =  ReadD();
		loot.item_id = ReadD();
		loot.count = ReadD();
		loot.actorId = objectId;

		lootTable.Add(loot);
	}

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, objectId, secondsToFade, lootTable]() {

		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(objectId);

		if (actor != nullptr)
		{
			if (GameSocketThread::Runnable->character->GetCurrentTarget() == actor)
			{
				GameSocketThread::Runnable->character->TargetUnselected();
			}
			if (actor->isNpc)
			{
				actor->isDead = true;
				actor->loot = lootTable;
				actor->DieMontage();
				actor->DestroyInTime(secondsToFade);
				/*WorldInstance::GetInstance()->RemoveActorFromWorld(actor);*/
			}
			//actor->Destroy();
		}


	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}
