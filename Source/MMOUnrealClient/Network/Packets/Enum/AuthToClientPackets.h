#pragma once

#include "CoreMinimal.h"

/**
 * @author Dego1n
 * Enum ID пакетов которые приходят от сервера авторизации клиенту
 */
class MMOUNREALCLIENT_API AuthToClientPackets
{
public:
	enum Packet {
		CONNECTION_ACCEPTED = 0x01,
		AUTH_OK = 0x02,
		AUTH_FAILED = 0x03,
		CONNECTION_FAILED = 0x04,
		SERVER_LIST = 0x05,
		GAME_SERVER_AUTH_OK = 0x06
	};
};
