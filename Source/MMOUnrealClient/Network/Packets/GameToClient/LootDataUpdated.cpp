// MMOClient 2019


#include "LootDataUpdated.h"
#include "Model/Actor/GameActor.h"
#include "Model/WorldInstance.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Model/Struct/LootObjectStruct.h"

/**
 * @author Dego1n
 */
LootDataUpdated::LootDataUpdated(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] LootDataUpdated"));
#endif
	this->Handle();
}

LootDataUpdated::~LootDataUpdated()
{
}

void LootDataUpdated::Handle()
{
	int32 objectId = ReadD();
	int16 lootSize = ReadH();
	TArray<LootObjectStruct> lootTable;
	for (int16 i = 0; i < lootSize; i++)
	{
		LootObjectStruct loot;
		loot.object_id = ReadD();
		loot.item_id = ReadD();
		loot.count = ReadD();
		loot.actorId = objectId;

		lootTable.Add(loot);
	}

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, objectId, lootTable]() {

		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(objectId);

		if (actor != nullptr)
		{
			if (GameSocketThread::Runnable->character->GetCurrentTarget() == actor)
			{
				GameSocketThread::Runnable->character->TargetUnselected();
			}
			if (actor->isNpc)
			{
				actor->loot = lootTable;
				GameSocketThread::Runnable->character->onLootDataUpdated(actor);

			}
		}


		}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}
