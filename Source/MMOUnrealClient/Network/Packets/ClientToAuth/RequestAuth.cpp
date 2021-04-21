#include "RequestAuth.h"

/**
 * @author Dego1n
 */
RequestAuth::RequestAuth(int32 session_key, FString username, FString password) : AbstractSendablePacket()
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Auth] RequestAuth"));
	#endif

	auth_session_key = session_key;

	this->username = username;
	this->password = password;

	Build();
	PrepareForSend();
}

void RequestAuth::Build()
{
	WriteH(ClientToAuthPackets::Packet::REQUEST_AUTH);
	WriteD(auth_session_key);
	WriteS(username);
	WriteS(password);
}
