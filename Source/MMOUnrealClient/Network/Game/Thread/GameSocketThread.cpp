
#include "GameSocketThread.h"
#include "Network/Packets/Handler/GamePacketsHandler.h"
#include "Network/Packets/ClientToGame/RequestConnectToGameServer.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreaming.h"

/**
 * @author Dego1n
 * Тред для общения с сервером авторизации, доступ к треду можно получить через синглтон
 */
GameSocketThread* GameSocketThread::Runnable = NULL;


/**
 * Конструктор, создает объект треда
 */
GameSocketThread::GameSocketThread(int32 game_session_key, FString server_address, int32 server_port, UWorld* world)
{
	this->game_session_key = game_session_key;
	this->world = world;
	this->address = server_address;
	this->port = server_port;
	Thread = FRunnableThread::Create(this, TEXT("AuthSocketThread"), 0, TPri_BelowNormal); //TODO: Винда по умолчанию выделяет 8мб под тред, возможно можно и нужно выделить больше
}


/**
 * Деструктор, на всякий случай затираем тред
 */
GameSocketThread::~GameSocketThread()
{
	delete Thread;
	Thread = NULL;
}

uint32 GameSocketThread::Run()
{

	FPlatformProcess::Sleep(0.03); // ???

	bool is_connected = GameSocket::InitSocket(address, port);

	if (!is_connected)
	{
		Stop();
		return 0;
	}

	this->SendPacket(new RequestConnectToGameServer(game_session_key));
	while (!stopReceive)
	{
		FPlatformProcess::Sleep(0.03);
		uint8 * packet_size = new uint8[2];
		int16 actual_packet_size; //TODO: поменять на int16 или uint16?

		int32 bytes_read;

		uint8 * received_packet;
		try {
			GameSocket->tcp_socket->Recv(packet_size, 2, bytes_read); //Читаем 2 байта, чтобы узнать размер следующего пакета

			actual_packet_size = (((packet_size[1] & 0xFF) << 8) | (packet_size[0] & 0xFF)); //конвертим размер пакета в шорт

			if (actual_packet_size < 2) //Обычно такое происходит когда коннект с сервером оборвался
			{
				throw "Packet size < 2!"; //TODO: выдывать на экран сообщение о системной ошибке
			}

			received_packet = new uint8[actual_packet_size - 2];

			GameSocket->tcp_socket->Recv(received_packet, actual_packet_size - 2, bytes_read);
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

		GamePacketsHandler::Handle(packetId, convertedPacket);
		//AuthPacketsHandler::Handle(packetId, convertedPacket); //Отдаем пакет хендлер для дальнейшей черной магии
	}
	return 0;
}


/**
 * Отправка пакета на игровой сервер
 */
void GameSocketThread::SendPacket(AbstractSendablePacket* packet)
{
	if (Runnable->GameSocket->tcp_socket == nullptr) //Проверка что есть коннект с сокетом
	{
		GLog->Log("Cant send packet, not connected to a socket"); //TODO: Выводить не в лог, а сообщение клиенту о системной ошибке
		return;
	}

	int32 bytes_sent;

	Runnable->GameSocket->tcp_socket->Send(packet->GetData(), packet->GetSize(), bytes_sent);

	return;
}

/**
 * Здесь создаем тред
 */
GameSocketThread * GameSocketThread::StartConnectionThread(int32 game_session_key, FString server_address, int32 server_port, UWorld* world)
{
	if (!Runnable)
	{
		Runnable = new GameSocketThread(game_session_key, server_address, server_port, world);
	}

	return Runnable;
}

void GameSocketThread::ReceivedCharacterList(TArray<APlayableCharacter*> characters)
{
	this->availableCharacters = characters;

	FFunctionGraphTask::CreateAndDispatchWhenReady([this]() {
		UGameplayStatics::OpenLevel(world, FName(TEXT("/Game/Levels/ChampionSelect/ChampionSelect")), TRAVEL_Absolute);
		state = 1;
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}

void GameSocketThread::CharacterSelectedOk()
{
	/*FFunctionGraphTask::CreateAndDispatchWhenReady([this]() {
		UGameplayStatics::OpenLevel(world, FName(TEXT("/Game/Levels/World/GameLevel")), TRAVEL_Absolute);
	}, TStatId(), nullptr, ENamedThreads::GameThread);*/
	FFunctionGraphTask::CreateAndDispatchWhenReady([this]() {
		UGameplayStatics::OpenLevel(world, FName(TEXT("/Game/Levels/World/GameWorld")), TRAVEL_Absolute);
	}, TStatId(), nullptr, ENamedThreads::GameThread);
}


/**
 * Здесь мы завершаем коннект с сервером и удаляем тред
 */
void GameSocketThread::Stop()
{
	stopReceive = true;

	if (GameSocketThread::Runnable != NULL)
	{
		GameSocketThread::Runnable = NULL;
	}
}