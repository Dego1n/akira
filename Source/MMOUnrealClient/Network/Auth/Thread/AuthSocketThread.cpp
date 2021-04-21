#include "AuthSocketThread.h"
#include "Network/Packets/Handler/AuthPacketsHandler.h"
#include "Network/Packets/ClientToAuth/RequestConnect.h"
#include "Kismet/GameplayStatics.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Config/Network/NetworkConfig.h"

/**
 * @author Dego1n
 * Тред для общения с сервером авторизации, доступ к треду можно получить через синглтон
 */
AuthSocketThread* AuthSocketThread::Runnable = NULL;

/**
 * Конструктор, создает объект треда
 */
AuthSocketThread::AuthSocketThread()
{
	Thread = FRunnableThread::Create(this, TEXT("AuthSocketThread"), 0, TPri_BelowNormal); //TODO: Винда по умолчанию выделяет 8мб под тред, возможно можно и нужно выделить больше
}

/**
 * Деструктор, на всякий случай затираем тред
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
		return 0; //TODO: Выводить на экран что сервер авторизации не доступен
	}

	this->SendPacket(new RequestConnect()); //Сразу после подключения шлем пакет Request Connect
	while (!stopReceive)
	{
		uint8 * packet_size = new uint8[2];
		int16 actual_packet_size;

		int32 bytes_read;
		
		uint8 * received_packet;
		try {
			AuthSocket->tcp_socket->Recv(packet_size, 2, bytes_read); //Читаем 2 байта, чтобы узнать размер следующего пакета

			actual_packet_size = (((packet_size[1] & 0xFF) << 8) | (packet_size[0] & 0xFF)); //конвертим размер пакета в шорт

			if (actual_packet_size < 2) //Обычно такое происходит когда коннект с сервером оборвался
			{
				throw "Packet size < 2!"; //TODO: выдывать на экран сообщение о системной ошибке
			}

			received_packet = new uint8[actual_packet_size - 2];

			AuthSocket->tcp_socket->Recv(received_packet, actual_packet_size - 2, bytes_read);
		}
		catch (...)
		{
			Stop();
			break;
		}

		int16 packetId = (((received_packet[1] & 0xFF) << 8) | (received_packet[0] & 0xFF)); //Вытаскиваем ID пакета для хендлера //TODO: поменять на int16 или uint16?

		/**
		 * Java сервер отправляет нам пакет в формате byte (аналог C++ - int8 (-128 - 128)), а сокет принимает его в массив uint8 (0-255).
		 * Пришлось поебаться нихуево, но это лучшее что пока придумал. А вообще... я в рот ебал этот C++
		 */
		TArray<int8> convertedPacket;
		for (int32 i = 0; i <= actual_packet_size - 2; i++)
		{
			convertedPacket.Add(received_packet[i] << 24 >> 24); //Не, ну за это сразу бан нахуй... ПЕРЕВОД С UINT8 В INT8
		}

		AuthPacketsHandler::Handle(packetId, convertedPacket); //Отдаем пакет хендлер для дальнейшей черной магии
	}
	return 0;
}

/**
 * Мы получили ServerList, сохраняем список серверов отсылаем ивент в Main тред какой-то магической хуйней анриала. Не знаю как, но работает
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
 * После выбора сервера, мы получаем ключ игровой сессии с которой мы можем стучаться на гейм сервер.
 * Собственно тут мы и обрываем соединение с сервером авторизации, так как общих тем разговора у нас больше нет.
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
 * Получили уведомление об ошибки при попытке авторизации, передаем ивент блюпринту и закрываем коннект
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
 * Получили уведомление об ошибки при попытке коннекта к серверу авторизации, передаем ивент блюпринту и закрываем коннект
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
 * Отправка пакета на сервер авторизации
 */
void AuthSocketThread::SendPacket(AbstractSendablePacket* packet)
{
	if (Runnable->AuthSocket->tcp_socket == nullptr) //Проверка что есть коннект с сокетом
	{
		GLog->Log("Cant send packet, not connected to a socket"); //TODO: Выводить не в лог, а сообщение клиенту о системной ошибке
		return;
	}
	
	int32 bytes_sent;

	Runnable->AuthSocket->tcp_socket->Send(packet->GetData(), packet->GetSize(), bytes_sent);

	return;
}

/**
 * Собственно здесь берем с клиента логин, пароль и создаем тред
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
 * Здесь мы завершаем коннект с сервером и удаляем тред
 */
void AuthSocketThread::Stop()
{
	stopReceive = true;

	if (AuthSocketThread::Runnable != NULL)
	{
		AuthSocketThread::Runnable = NULL;
	}
}