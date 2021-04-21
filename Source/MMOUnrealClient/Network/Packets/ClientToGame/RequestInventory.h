// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API RequestInventory : public AbstractSendablePacket
{
public:
	RequestInventory();
	void Build() override;
};
