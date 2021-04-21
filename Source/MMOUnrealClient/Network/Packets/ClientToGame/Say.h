// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API Say : public AbstractSendablePacket
{
private:
	FString  message;
public:
	Say(FString message);
	void Build() override;
};
