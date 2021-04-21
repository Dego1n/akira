// MMOClient 2019


#include "RequestInventory.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

RequestInventory::RequestInventory()
{

#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] RequestInventory"));
#endif

	Build();
	PrepareForSend();
}

void RequestInventory::Build()
{
	WriteH(ClientToGamePackets::Packet::REQUEST_INVENTORY);
}

