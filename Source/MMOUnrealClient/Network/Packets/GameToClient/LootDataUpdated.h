// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API LootDataUpdated : public AbstractRecivablePacket
{
public:
	LootDataUpdated(TArray <int8> packet);
	~LootDataUpdated();

private:
	void Handle();
};
