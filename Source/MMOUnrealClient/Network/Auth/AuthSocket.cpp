#include "AuthSocket.h"

/**
 * @author Dego1n
 */

FSocket* AuthSocket::tcp_socket = nullptr;
TSharedPtr<FInternetAddr> AuthSocket::tcp_address = nullptr;

AuthSocket::~AuthSocket()
{
	if (tcp_socket != nullptr)
	{
		tcp_socket->Close();
		delete tcp_socket;
	}
}

bool AuthSocket::InitSocket(FString serverAddress, int32 tcp_server_port)
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
