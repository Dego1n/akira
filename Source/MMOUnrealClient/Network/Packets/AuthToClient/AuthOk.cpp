#include "AuthOk.h"

#include "Network/Auth/Thread/AuthSocketThread.h"
#include "Network/Packets/ClientToAuth/RequestServerList.h"

AuthOk::AuthOk(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("[Auth -> Client] AuthOk"));
#endif
	this->Handle();
}

AuthOk::~AuthOk()
{
}
void AuthOk::Handle()
{
	//Приходит только айди пакета
	//Запрашиваем список серверов
	AuthSocketThread::Runnable->SendPacket(new RequestServerList(AuthSocketThread::Runnable->auth_session_key));
}