// MMOClient 2019


#include "RequestAttack.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

/**
 * @author Dego1n
 */
RequestAttack::RequestAttack()
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] RequestAttack"));
	#endif

	Build();
	PrepareForSend();
}

void RequestAttack::Build()
{
	WriteH(ClientToGamePackets::Packet::REQUEST_ATTACK);
}
