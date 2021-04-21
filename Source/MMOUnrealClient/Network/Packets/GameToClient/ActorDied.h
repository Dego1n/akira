// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API ActorDied : public AbstractRecivablePacket
{
public:
	ActorDied(TArray <int8> packet);
	~ActorDied();

private:
	void Handle();
};
