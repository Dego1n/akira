// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API StopMoving : public AbstractRecivablePacket
{
public:
	StopMoving(TArray <int8> packet);
	~StopMoving();

private:
	void Handle();
};
