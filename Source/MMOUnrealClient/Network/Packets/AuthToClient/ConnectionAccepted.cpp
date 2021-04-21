#include "ConnectionAccepted.h"

#include "Network/Auth/Thread/AuthSocketThread.h"
#include "Network/Packets/ClientToAuth/RequestAuth.h"

/**
 * @author Dego1n
 */
ConnectionAccepted::ConnectionAccepted(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("[Auth -> Client] ConnectionAccepted"));
	#endif
	this->Handle();
}

ConnectionAccepted::~ConnectionAccepted()
{
}

void ConnectionAccepted::Handle()
{
	int32 session_key = ReadD();
	AuthSocketThread::Runnable->auth_session_key = session_key;

	FString username = AuthSocketThread::Runnable->username;
	FString password = AuthSocketThread::Runnable->password;
	AuthSocketThread::Runnable->SendPacket(new RequestAuth(session_key, username, password));
}