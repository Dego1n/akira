// MMOClient 2020

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API RotationChanged : public AbstractSendablePacket
{
private:
	float pitch;
	float yaw;
public:
	RotationChanged(float pitch, float yaw);
	void Build() override;
};
