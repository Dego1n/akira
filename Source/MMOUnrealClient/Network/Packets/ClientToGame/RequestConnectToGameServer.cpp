#include "RequestConnectToGameServer.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

RequestConnectToGameServer::RequestConnectToGameServer(int32 game_session_key)
{

	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] RequestConnectToGameServer"));
	#endif

		this->session_key = game_session_key;

	Build();
	PrepareForSend();
}

void RequestConnectToGameServer::Build()
{
	WriteH(ClientToGamePackets::Packet::REQUEST_CONNECT_TO_GAME_SERVER);

	WriteD(session_key);
}