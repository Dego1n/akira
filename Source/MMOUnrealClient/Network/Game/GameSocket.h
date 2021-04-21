#pragma once

#include "CoreMinimal.h"
#include "Networking.h"
#include "SocketSubsystem.h"
/**
 * @author Dego1n
 * Сокет для игрового сервера
 */
class MMOUNREALCLIENT_API GameSocket
{
	~GameSocket();
public:
	static FSocket* tcp_socket;
	// tcp адрес сервера
	static TSharedPtr<FInternetAddr> tcp_address;

	static bool InitSocket(FString serverAddress, int32 tcp_server_port);
};
