// MMOClient 2019


#include "BuyList.h"
#include "Model/Item/InventoryItem.h"
#include "Network/Game/Thread/GameSocketThread.h"

BuyList::BuyList(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] BuyList"));
#endif
	this->Handle();
}

BuyList::~BuyList()
{
}

void BuyList::Handle()
{
	int32 buylistId = ReadD();
	int32 currencyId = ReadD();
	int16 buyListCount = ReadH();
	TMap<FInventoryItem, int32> buyItems;
	for (int16 i = 0; i < buyListCount; i++)
	{
		FInventoryItem item;
		item.item_id = ReadD();
		int32 price = ReadD();
		item.stackable = ReadH() == 1 ? true : false;
		buyItems.Add(item, price);
	}
	int16 sellListCount = ReadH();
	UE_LOG(LogTemp, Warning, TEXT("received sell count %d"), sellListCount);
	TMap<FInventoryItem, int32> sellItems;
	for (int16 i = 0; i < sellListCount; i++)
	{
		int32 item_id = ReadD();
		int32 object_id = ReadD();
		int32 amount = ReadD();
		int32 price = ReadD();
		bool stackable = ReadH() == 1 ? true : false;
		UE_LOG(LogTemp, Warning, TEXT("received sell item_id %d"), item_id);
		UE_LOG(LogTemp, Warning, TEXT("received sell item_object_id %d"), object_id);
		FInventoryItem item;
		item.item_id = item_id;
		item.object_id = object_id;
		item.count = amount;
		item.stackable = stackable;
		sellItems.Add(item, price);
	}


	FFunctionGraphTask::CreateAndDispatchWhenReady([this, buyItems, sellItems, currencyId, buylistId]() {

		GameSocketThread::Runnable->character->ShowBuyList(buyItems, sellItems, currencyId, buylistId);

		}
	, TStatId(), nullptr, ENamedThreads::GameThread);

}