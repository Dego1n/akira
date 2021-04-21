#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 * Пакет который указывает что прошла ошибка при авторизации, закрываем коннект и выводим сообщение от FailReason
 */
class MMOUNREALCLIENT_API AuthFailed : public AbstractRecivablePacket
{
public:
	AuthFailed(TArray<int8> packet);
	~AuthFailed();
private:
	enum FailReason {
		SYSTEM_ERROR = 0x00,
		CREDENTIALS_INVALID = 0x01,
		ACCESS_DENIED = 0x02,
		ACCOUNT_ALREADY_IN_USE = 0x03,
		ACCOUNT_BLOCKED = 0x04,
		SERVER_UNAVAILABLE = 0x05
	};
	FString message;
	void Handle();
};
