#include "GameServerAuthOk.h"

#include "Network/Auth/Thread/AuthSocketThread.h"

GameServerAuthOk::GameServerAuthOk(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("[Auth -> Client] GameServerAuthOk"));
#endif
	this->Handle();
}

GameServerAuthOk::~GameServerAuthOk()
{

}


void GameServerAuthOk::Handle()
{
	int32 game_session_key = ReadD();
	AuthSocketThread::Runnable->ReceivedGameSessionKey(game_session_key);
}