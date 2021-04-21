
#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API EnterWorld : public AbstractSendablePacket
{
public:
	EnterWorld();
	void Build() override;
};
