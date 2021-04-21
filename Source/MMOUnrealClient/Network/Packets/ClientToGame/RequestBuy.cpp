// MMOClient 2019


#include "RequestBuy.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

/**
 * @author Dego1n
 */
RequestBuy::RequestBuy(int32 buyListId, TMap<int32, int32> items)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] RequestBuy"));
#endif

	_items = items;
	_buyListId = buyListId;
	Build();
	PrepareForSend();
}

void RequestBuy::Build()
{
	WriteH(ClientToGamePackets::Packet::REQUEST_BUY);
	WriteD(_buyListId);
	WriteD(_items.Num());
	for (auto& item : _items)
	{
		WriteD(item.Key);
		WriteD(item.Value);
	}
}