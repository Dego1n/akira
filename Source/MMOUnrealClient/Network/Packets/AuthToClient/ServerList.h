#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 * Список игровых серверов, приходит после отправки клиентом пакета RequestServerList
 */
class MMOUNREALCLIENT_API ServerList : public AbstractRecivablePacket
{
public:
	ServerList(TArray <int8> packet);
	~ServerList();
private:
	void Handle();
};
