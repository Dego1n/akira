// MMOClient 2019


#include "BaseBuyListSellTab.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Network/Packets/ClientToGame/RequestSell.h"

void UBaseBuyListSellTab::RequestSellItems(int32 buyListId, TArray<UBaseBuyListItemSlot*> slots)
{
	TMap<int32, int32> items;
	for (UBaseBuyListItemSlot* slot : slots)
	{
		UE_LOG(LogTemp, Warning, TEXT("Client requeting sell item_object_id %d amount %d"), slot->objectId, slot->amount);
		items.Add(slot->objectId, slot->amount);
	}
	GameSocketThread::Runnable->SendPacket(new RequestSell(buyListId, items));
}