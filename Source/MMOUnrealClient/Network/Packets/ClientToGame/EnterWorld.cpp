#include "EnterWorld.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

EnterWorld::EnterWorld()
{

#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] EnterWorld"));
#endif

	Build();
	PrepareForSend();
}

void EnterWorld::Build()
{
	WriteH(ClientToGamePackets::Packet::ENTER_WORLD);
}