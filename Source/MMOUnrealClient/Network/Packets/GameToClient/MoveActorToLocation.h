#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API MoveActorToLocation : public AbstractRecivablePacket
{
public:
	MoveActorToLocation(TArray <int8> packet);
	~MoveActorToLocation();

private:
	void Handle();
};
