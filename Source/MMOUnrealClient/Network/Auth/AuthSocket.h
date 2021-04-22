#pragma once

#include "CoreMinimal.h"
#include "Networking.h"
#include "SocketSubsystem.h"

/**
 * @author Dego1n
 * ����� ��� ������� �����������
 */
class MMOUNREALCLIENT_API AuthSocket
{
	~AuthSocket();
public:
	static FSocket* tcp_socket;
	// tcp ����� �������
	static TSharedPtr<FInternetAddr> tcp_address;

	static bool InitSocket(FString serverAddress, int32 tcp_server_port);
};
