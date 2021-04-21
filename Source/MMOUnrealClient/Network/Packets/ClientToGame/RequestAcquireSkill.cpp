// MMOClient 2019


#include "RequestAcquireSkill.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

/**
 * @author Dego1n
 */
RequestAcquireSkill::RequestAcquireSkill(int32 ability_id)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] RequestAcquireSkill"));
#endif

	this->ability_id = ability_id;

	Build();
	PrepareForSend();
}

void RequestAcquireSkill::Build()
{
	WriteH(ClientToGamePackets::Packet::REQUEST_ACQUIRE_SKILL);
	WriteD(this->ability_id);
}
