#include "RequestServerList.h"

/**
 * @author Dego1n
 */
RequestServerList::RequestServerList(int32 session_key)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Auth] RequestServerList"));
#endif

	auth_session_key = session_key;

	Build();
	PrepareForSend();
}


void RequestServerList::Build()
{
	WriteH(ClientToAuthPackets::Packet::REQUEST_SERVER_LIST);
	WriteD(auth_session_key);
}


