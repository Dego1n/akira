#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 * ѕакет который запрашивает список серверов, отправл€етс€ после успешной авторизации (пакет AuthOk)
 */
class MMOUNREALCLIENT_API RequestServerList : public AbstractSendablePacket
{
private:
	int32 auth_session_key;
public:
	RequestServerList(int32 session_key);
	void Build() override;
};
