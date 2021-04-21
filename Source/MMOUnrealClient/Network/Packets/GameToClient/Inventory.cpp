// MMOClient 2019


#include "Inventory.h"
#include "Model/Actor/PlayableCharacter.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Model/Item/InventoryItem.h"
#include "Model/Item/EquipInfo.h"

/**
 * @author Dego1n
 */
Inventory::Inventory(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] Inventory"));
#endif
	this->Handle();
}

Inventory::~Inventory()
{
}

void Inventory::Handle()
{

	FEquipInfo* equipInfo = new FEquipInfo();

	equipInfo->rightHand = ReadD();
	ReadD();
	equipInfo->leftHand = ReadD();
	ReadD();
	equipInfo->helmet = ReadD();
	ReadD();
	equipInfo->upperArmor = ReadD();
	ReadD();
	equipInfo->lowerArmor = ReadD();
	ReadD();
	equipInfo->gloves = ReadD();
	ReadD();
	equipInfo->boots = ReadD();
	ReadD();
	equipInfo->belt = ReadD();
	ReadD();
	equipInfo->earring1 = ReadD();
	ReadD();
	equipInfo->earring2 = ReadD();
	ReadD();
	equipInfo->ring1 = ReadD();
	ReadD();
	equipInfo->ring2 = ReadD();
	ReadD();
	equipInfo->necklace = ReadD();
	ReadD();
	int32 count = ReadD();


	TArray<FInventoryItem> inventoryItems;
	for (int i = 0; i < count; i++)
	{
		FInventoryItem item;

		item.object_id = ReadD();
		item.item_id = ReadD();
		item.count = ReadD();

		inventoryItems.Add(item);
	}

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, inventoryItems, equipInfo]() {

		APlayableCharacter* pc = GameSocketThread::Runnable->character;

		if (pc != nullptr)
		{
			pc->inventoryItems = inventoryItems;
			pc->equipInfo = equipInfo;
			pc->InventoryUpdated();
		}
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);

}