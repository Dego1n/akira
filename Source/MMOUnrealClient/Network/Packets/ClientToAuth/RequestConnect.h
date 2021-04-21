#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 * Пакет который отправляется сразу после подключения к серверу авторизации. 
 * Если все ок - получаем в ответ пакет ConnectionAccepted с session_key
 */
class MMOUNREALCLIENT_API RequestConnect : public AbstractSendablePacket
{
public:
	RequestConnect();
	void Build() override;
};
