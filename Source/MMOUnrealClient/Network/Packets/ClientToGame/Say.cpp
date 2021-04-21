// MMOClient 2019


#include "Say.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

Say::Say(FString message)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] Say"));
	#endif
	
	this->message = message;

	Build();
	PrepareForSend();
}

void Say::Build()
{
	WriteH(ClientToGamePackets::Packet::SAY);
	WriteS(message);
}
