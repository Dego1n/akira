// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API ValidatePosition : public AbstractSendablePacket
{
private:
	FVector location;
	bool stoppedMoving;
public:
	ValidatePosition(FVector location, bool stoppedMoving = false);
	void Build() override;
};
