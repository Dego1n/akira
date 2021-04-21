#include "GameSocket.h"

/**
 * @author Dego1n
 */
FSocket* GameSocket::tcp_socket = nullptr;
TSharedPtr<FInternetAddr> GameSocket::tcp_address = nullptr;

GameSocket::~GameSocket()
{
	if (tcp_socket != nullptr)
	{
		tcp_socket->Close();
		delete tcp_socket;
	}
}

bool GameSocket::InitSocket(FString serverAddress, int32 tcp_server_port)
{
	tcp_socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("TCP_SOCKET"), false);

	// create a proper FInternetAddr representation
	tcp_address = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	// parse server address 
	FIPv4Address serverIP;
	FIPv4Address::Parse(serverAddress, serverIP);

	// and set 
	tcp_address->SetIp(serverIP.Value);
	tcp_address->SetPort(tcp_server_port);

	return tcp_socket->Connect(*tcp_address);
}
