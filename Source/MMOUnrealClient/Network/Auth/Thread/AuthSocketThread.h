#pragma once

#include "CoreMinimal.h"
#include "Runnable.h"
#include "RunnableThread.h"
#include "Network/Auth/AuthSocket.h"
#include "Network/Packets/AbstractSendablePacket.h"

#include "UserWidget/Lobby/LobbyUserWidget.h"

#include "Network/Auth/Model/ServerStruct.h"

/**
 * @author Dego1n
 * Тред для чтения пакетов из сокета авторизации.
 */
class MMOUNREALCLIENT_API AuthSocketThread : public FRunnable
{
private:
	ULobbyUserWidget* userWidget;
public:
	FString username;
	FString password;
	static AuthSocketThread* Runnable;

	FRunnableThread* Thread;

	AuthSocket* AuthSocket;
	bool stopReceive = false;

	void ReceivedServerList(TArray<FServerStruct> gameServer);
	void ReceivedGameSessionKey(int32 gameSessionKey);
	void ReceivedAuthFailed(FString message);
	void ReceivedConnectionFailed(FString message);
	void SendPacket(AbstractSendablePacket* packet);
	static AuthSocketThread* StartConnectionThread(ULobbyUserWidget* widget, FString username, FString password);

	int32 selected_server_id;
	int32 auth_session_key;
	TArray<FServerStruct> GameServers;
	//~~~ Thread stuff ~~~

	// Begin FRunnable interface.
	virtual uint32 Run();
	virtual void Stop();
	// End FRunnable interface

	AuthSocketThread();
	virtual ~AuthSocketThread();

};