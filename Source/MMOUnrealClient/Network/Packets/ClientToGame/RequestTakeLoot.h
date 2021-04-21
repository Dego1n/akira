// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API RequestTakeLoot : public AbstractSendablePacket
{
private:
	int32 actorObjectId;
	int32 itemObjectId;
public:
	RequestTakeLoot(int32 actorObjectId, int32 itemObjectId);
	void Build() override;
};
