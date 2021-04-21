#include "ServerList.h"
#include "Network/Auth/Thread/AuthSocketThread.h"

#include "Network/Auth/Model/ServerStruct.h"

ServerList::ServerList(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("[Auth -> Client] ServerList"));
#endif
	this->Handle();
}

ServerList::~ServerList()
{
}

void ServerList::Handle()
{
	TArray<FServerStruct> gameServers;
	int16 serverCount = ReadH();
	for (int i = 0; i < serverCount; i++)
	{
		FServerStruct server;

		server.ServerId = ReadH();
		server.ServerName = ReadS();
		server.ServerAddress = ReadS();
		server.ServerPort = ReadD();
		server.ServerStatus = ReadH();

		gameServers.Add(server);
	}
	AuthSocketThread::Runnable->ReceivedServerList(gameServers);
}