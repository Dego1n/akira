#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 * Пакет который приходит после отправки RequestConnect. Содержит session_key для дальнейшего общения
 */
class MMOUNREALCLIENT_API ConnectionAccepted : public AbstractRecivablePacket
{
public:
	ConnectionAccepted(TArray <int8> packet);
	~ConnectionAccepted();
private:
	void Handle();
};
