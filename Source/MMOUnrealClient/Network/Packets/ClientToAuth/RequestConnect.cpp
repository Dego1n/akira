#include "RequestConnect.h"
#include "Config/Network/NetworkConfig.h"


/**
 * @author Dego1n
 */

RequestConnect::RequestConnect() : AbstractSendablePacket()
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Auth] RequestConnect"));
	#endif
	Build();
	PrepareForSend();
}

void RequestConnect::Build() 
{
	WriteH(ClientToAuthPackets::Packet::REQUEST_CONNECT); //packetID
	WriteH(GetMutableDefault<UNetworkConfig>()->AuthProtocolVersion); //ProtocolVersion
}