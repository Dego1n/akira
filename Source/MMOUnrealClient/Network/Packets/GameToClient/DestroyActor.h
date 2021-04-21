#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API DestroyActor : public AbstractRecivablePacket
{
public:
	DestroyActor(TArray <int8> packet);
	~DestroyActor();
private:
	void Handle();
};
