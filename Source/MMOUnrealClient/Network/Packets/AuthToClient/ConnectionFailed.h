#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 * Пакет который приходит после отправки RequestConnect. Содержит session_key для дальнейшего общения
 */
class MMOUNREALCLIENT_API ConnectionFailed : public AbstractRecivablePacket
{
public:
	ConnectionFailed(TArray <int8> packet);
	~ConnectionFailed();
private:
	FString message;
	enum FailReason {
		WRONG_PROTOCOL = 0x00,
	};
	void Handle();
};
