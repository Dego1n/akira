#include "RequestServerLogin.h"

RequestServerLogin::RequestServerLogin(int32 session_key, int32 server_id)
{

	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Auth] RequestServerLogin"));
	#endif

	auth_session_key = session_key;
	selected_server_id = server_id;

	Build();
	PrepareForSend();
}
void RequestServerLogin::Build()
{
	WriteH(ClientToAuthPackets::Packet::REQUEST_SERVER_LOGIN);
	WriteD(auth_session_key);
	WriteD(selected_server_id);
}