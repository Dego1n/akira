// MMOClient 2019


#include "BaseBuyListBuyTab.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Network/Packets/ClientToGame/RequestBuy.h"

void UBaseBuyListBuyTab::RequestBuyItems(int32 buyListId, TArray<UBaseBuyListItemSlot*> slots)
{
	TMap<int32, int32> items;
	for (UBaseBuyListItemSlot* slot : slots)
	{
		UE_LOG(LogTemp, Warning, TEXT("Client requeting buy item_id %d amount %d"), slot->itemId, slot->amount);
		items.Add(slot->itemId, slot->amount);
	}
	GameSocketThread::Runnable->SendPacket(new RequestBuy(buyListId,items));
}