// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API BuyList : public AbstractRecivablePacket
{
public:
	BuyList(TArray <int8> packet);
	~BuyList();

private:
	void Handle();
};

