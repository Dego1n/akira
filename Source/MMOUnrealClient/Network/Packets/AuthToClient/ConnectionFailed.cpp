#include "ConnectionFailed.h"

#include "Network/Auth/Thread/AuthSocketThread.h"

/**
 * @author Dego1n
 */
ConnectionFailed::ConnectionFailed(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("[Auth -> Client] ConnectionFailed"));
#endif
	this->Handle();
}

ConnectionFailed::~ConnectionFailed()
{
}

void ConnectionFailed::Handle()
{
	int16 reason = ReadH();

	switch (reason)
	{
	case FailReason::WRONG_PROTOCOL:
		message = TEXT("Game version is outdated and not supported");
		break;
	default:
		message = TEXT("Unknown error");
		break;
	}
	AuthSocketThread::Runnable->ReceivedConnectionFailed(message);
}