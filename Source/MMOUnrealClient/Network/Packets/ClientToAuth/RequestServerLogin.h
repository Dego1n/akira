#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 * Пакет который отправляется после выбора сервера (его ID)
 */
class MMOUNREALCLIENT_API RequestServerLogin : public AbstractSendablePacket
{
private:
	int32 auth_session_key;
	int32 selected_server_id;
public:
	RequestServerLogin(int32 session_id, int32 selected_server_id);
	void Build() override;
};
