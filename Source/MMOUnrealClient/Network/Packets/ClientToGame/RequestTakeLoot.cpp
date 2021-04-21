// MMOClient 2019


#include "RequestTakeLoot.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

/**
 * @author Dego1n
 */
RequestTakeLoot::RequestTakeLoot(int32 actorObjectId, int32 itemObjectId)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] RequestTakeLoot"));
#endif

	this->actorObjectId = actorObjectId;
	this->itemObjectId = itemObjectId;

	Build();
	PrepareForSend();
}
void RequestTakeLoot::Build()
{
	WriteH(ClientToGamePackets::Packet::REQUEST_TAKE_LOOT);

	WriteD(actorObjectId);
	WriteD(itemObjectId);
}