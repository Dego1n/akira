#include "AuthFailed.h"

#include "Network/Auth/Thread/AuthSocketThread.h"

AuthFailed::AuthFailed(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("[Auth -> Client] AuthFailed"));
#endif
	this->Handle();
}

AuthFailed::~AuthFailed()
{
}
void AuthFailed::Handle()
{
	int16 reason = ReadH();


	switch (reason)
	{
		case FailReason::SYSTEM_ERROR:
			message = TEXT("System error");
			break;
		case FailReason::CREDENTIALS_INVALID:
			message = TEXT("Invalid credentials");
			break;
		case FailReason::ACCESS_DENIED:
			message = TEXT("Access denied");
			break;
		case FailReason::ACCOUNT_ALREADY_IN_USE:
			message = TEXT("Account already in use");
			break;
		case FailReason::ACCOUNT_BLOCKED:
			message = TEXT("Account blocked");
			break;
		case FailReason::SERVER_UNAVAILABLE:
			//message = TEXT("Сервер временно не доступен или проводится техническое обслуживание");
			message = TEXT("Service unavailable");
			break;
		default:
			message = TEXT("Unknown error");
			break;
	}
	AuthSocketThread::Runnable->ReceivedAuthFailed(message);
}