// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API RequestAttack : public AbstractSendablePacket
{
public:
	RequestAttack();
	void Build() override;
	
};
