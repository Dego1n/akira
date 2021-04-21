// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API Inventory : public AbstractRecivablePacket
{
public:
	Inventory(TArray <int8> packet);
	~Inventory();

private:
	void Handle();
};
