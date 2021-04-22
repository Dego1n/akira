#include "AuthSocketThread.h"
#include "Network/Packets/Handler/AuthPacketsHandler.h"
#include "Network/Packets/ClientToAuth/RequestConnect.h"
#include "Kismet/GameplayStatics.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Config/Network/NetworkConfig.h"

/**
 * @author Dego1n
 * ���� ��� ������� � �������� �����������, ������ � ����� ����� �������� ����� ��������
 */
AuthSocketThread* AuthSocketThread::Runnable = NULL;

/**
 * �����������, ������� ������ �����
 */
AuthSocketThread::AuthSocketThread()
{
	Thread = FRunnableThread::Create(this, TEXT("AuthSocketThread"), 0, TPri_BelowNormal); //TODO: ����� �� ��������� �������� 8�� ��� ����, �������� ����� � ����� �������� ������
}

/**
 * ����������, �� ������ ������ �������� ����
 */
AuthSocketThread::~AuthSocketThread()
{
	delete Thread;
	Thread = NULL;
}

uint32 AuthSocketThread::Run()
{
	UNetworkConfig *networkConfig = GetMutableDefault<UNetworkConfig>();
	FPlatformProcess::Sleep(0.03); // ???

	bool is_connected = AuthSocket::InitSocket(networkConfig->AuthServerAddress, networkConfig->AuthServerPort);

	if (!is_connected)
	{
		Stop();
		return 0; //TODO: �������� �� ����� ��� ������ ����������� �� ��������
	}

	this->SendPacket(new RequestConnect()); //����� ����� ����������� ���� ����� Request Connect
	while (!stopReceive)
	{
		uint8 * packet_size = new uint8[2];
		int16 actual_packet_size;

		int32 bytes_read;
		
		uint8 * received_packet;
		try {
			AuthSocket->tcp_socket->Recv(packet_size, 2, bytes_read); //������ 2 �����, ����� ������ ������ ���������� ������

			actual_packet_size = (((packet_size[1] & 0xFF) << 8) | (packet_size[0] & 0xFF)); //��������� ������ ������ � ����

			if (actual_packet_size < 2) //������ ����� ���������� ����� ������� � �������� ���������
			{
				throw "Packet size < 2!"; //TODO: �������� �� ����� ��������� � ��������� ������
			}

			received_packet = new uint8[actual_packet_size - 2];

			AuthSocket->tcp_socket->Recv(received_packet, actual_packet_size - 2, bytes_read);
		}
		catch (...)
		{
			Stop();
			break;
		}

		int16 packetId = (((received_packet[1] & 0xFF) << 8) | (received_packet[0] & 0xFF)); //����������� ID ������ ��� �������� //TODO: �������� �� int16 ��� uint16?

		/**
		 * Java ������ ���������� ��� ����� � ������� byte (������ C++ - int8 (-128 - 128)), � ����� ��������� ��� � ������ uint8 (0-255).
		 * �������� ��������� �������, �� ��� ������ ��� ���� ��������. � ������... � � ��� ���� ���� C++
		 */
		TArray<int8> convertedPacket;
		for (int32 i = 0; i <= actual_packet_size - 2; i++)
		{
			convertedPacket.Add(received_packet[i] << 24 >> 24); //��, �� �� ��� ����� ��� �����... ������� � UINT8 � INT8
		}

		AuthPacketsHandler::Handle(packetId, convertedPacket); //������ ����� ������� ��� ���������� ������ �����
	}
	return 0;
}

/**
 * �� �������� ServerList, ��������� ������ �������� �������� ����� � Main ���� �����-�� ���������� ������ �������. �� ���� ���, �� ��������
 */
void AuthSocketThread::ReceivedServerList(TArray<FServerStruct> gameServers)
{
	GameServers = gameServers;
	FFunctionGraphTask::CreateAndDispatchWhenReady([this]() {
		userWidget->OnReceivedServerList(GameServers);
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
	
}

/**
 * ����� ������ �������, �� �������� ���� ������� ������ � ������� �� ����� ��������� �� ���� ������.
 * ���������� ��� �� � �������� ���������� � �������� �����������, ��� ��� ����� ��� ��������� � ��� ������ ���.
 */
void AuthSocketThread::ReceivedGameSessionKey(int32 gameSessionKey)
{
	for (int32 i = 0; i < GameServers.Num(); i++)
	{
		if (GameServers[i].ServerId == selected_server_id)
		{
			FServerStruct serverStruct = GameServers[i];
			FFunctionGraphTask::CreateAndDispatchWhenReady([this, gameSessionKey, serverStruct]() {
				userWidget->StartConnectionToGameServer(gameSessionKey, serverStruct);
			}
			, TStatId(), nullptr, ENamedThreads::GameThread);
		}
	}
	Stop();
}

/**
 * �������� ����������� �� ������ ��� ������� �����������, �������� ����� ��������� � ��������� �������
 */
void AuthSocketThread::ReceivedAuthFailed(FString message)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, message]() {
		FString msg = message;
		userWidget->OnReceivedAuthFailed(msg);
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
	Stop();
}

/**
 * �������� ����������� �� ������ ��� ������� �������� � ������� �����������, �������� ����� ��������� � ��������� �������
 */
void AuthSocketThread::ReceivedConnectionFailed(FString message)
{
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, message]() {
		FString msg = message;
		userWidget->OnReceivedConnectionFailed(msg);
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
	Stop();
}

/**
 * �������� ������ �� ������ �����������
 */
void AuthSocketThread::SendPacket(AbstractSendablePacket* packet)
{
	if (Runnable->AuthSocket->tcp_socket == nullptr) //�������� ��� ���� ������� � �������
	{
		GLog->Log("Cant send packet, not connected to a socket"); //TODO: �������� �� � ���, � ��������� ������� � ��������� ������
		return;
	}
	
	int32 bytes_sent;

	Runnable->AuthSocket->tcp_socket->Send(packet->GetData(), packet->GetSize(), bytes_sent);

	return;
}

/**
 * ���������� ����� ����� � ������� �����, ������ � ������� ����
 */
AuthSocketThread * AuthSocketThread::StartConnectionThread(ULobbyUserWidget* widget, FString username, FString password)
{
	if (!Runnable)
	{
		Runnable = new AuthSocketThread();
		Runnable->userWidget = widget;
		Runnable->username = username;
		Runnable->password = password;
	}

	return Runnable;
}

/**
 * ����� �� ��������� ������� � �������� � ������� ����
 */
void AuthSocketThread::Stop()
{
	stopReceive = true;

	if (AuthSocketThread::Runnable != NULL)
	{
		AuthSocketThread::Runnable = NULL;
	}
}