#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"


/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API RequestConnectToGameServer : public AbstractSendablePacket
{
private:
	int32 session_key;
public:
	RequestConnectToGameServer(int32 game_session_key);
	void Build() override;
};
