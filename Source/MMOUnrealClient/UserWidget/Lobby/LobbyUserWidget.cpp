#include "LobbyUserWidget.h"
#include "Network/Auth/Thread/AuthSocketThread.h"

#include "Network/Packets/ClientToAuth/RequestServerLogin.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Kismet/GameplayStatics.h"
#include "Config/Network/NetworkConfig.h"


/**
 * @author Dego1n
 */
void ULobbyUserWidget::ConnectToAuthServer(FString username, FString password)
{
	AuthSocketThread::StartConnectionThread(this, username, password);
}

void ULobbyUserWidget::DoRequestServerLogin(int32 serverId)
{
	AuthSocketThread* threadInstance = AuthSocketThread::Runnable;
	threadInstance->selected_server_id = serverId;
	threadInstance->SendPacket(new RequestServerLogin(threadInstance->auth_session_key, serverId));
}

void ULobbyUserWidget::CloseConnectionWithAuthServer()
{
	if(AuthSocketThread::Runnable != NULL)
		AuthSocketThread::Runnable->Stop();
}

void ULobbyUserWidget::StartConnectionToGameServer(int32 game_session_key, FServerStruct server)
{
	server.ServerAddress;
	GameSocketThread::StartConnectionThread(game_session_key, server.ServerAddress, server.ServerPort, GetWorld());
}