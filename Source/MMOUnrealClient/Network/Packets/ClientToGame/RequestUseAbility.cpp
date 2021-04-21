// MMOClient 2019


#include "RequestUseAbility.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

RequestUseAbility::RequestUseAbility(int32 ability_id)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] RequestUseAbility"));
#endif

	this->ability_id = ability_id;

	Build();
	PrepareForSend();
}

void RequestUseAbility::Build()
{
	WriteH(ClientToGamePackets::Packet::REQUEST_USE_ABILITY);
	WriteD(this->ability_id);
}
