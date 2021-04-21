// MMOClient 2019


#include "RequestCommand.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

RequestCommand::RequestCommand(FString command)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] RequestCommand"));
#endif
	this->command = command;
	Build();
	PrepareForSend();
}

void RequestCommand::Build()
{
	WriteH(ClientToGamePackets::Packet::REQUEST_COMMAND);
	WriteS(command);
}
