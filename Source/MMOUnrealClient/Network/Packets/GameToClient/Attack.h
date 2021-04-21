// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API Attack : public AbstractRecivablePacket
{
public:
	Attack(TArray <int8> packet);
	~Attack();

private:
	void Handle();
};
