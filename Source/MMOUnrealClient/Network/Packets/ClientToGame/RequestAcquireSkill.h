// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API RequestAcquireSkill : public AbstractSendablePacket
{
private:
	int32 ability_id;
public:
	RequestAcquireSkill(int32 ability_id);
	void Build() override;
	
};