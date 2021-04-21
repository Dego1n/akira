#pragma once

#include "CoreMinimal.h"

/**
 * @author Dego1n
 * Enum ID пакетов от клиента к серверу авторизации
 */
class MMOUNREALCLIENT_API ClientToAuthPackets
{
public:
	enum Packet
	{
		REQUEST_CONNECT = 0x01,
		REQUEST_AUTH = 0x02,
		REQUEST_SERVER_LIST = 0x03,
		REQUEST_SERVER_LOGIN = 0x04
	};
};
