#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API MoveToLocation : public AbstractSendablePacket
{
private:
	FVector origin;
	FVector target;
public:
	MoveToLocation(FVector origin, FVector target);
	void Build() override;
};
