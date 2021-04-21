// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API ActorSay : public AbstractRecivablePacket
{

public:
	ActorSay(TArray <int8> packet);
	~ActorSay();

private:
	void Handle();
};
