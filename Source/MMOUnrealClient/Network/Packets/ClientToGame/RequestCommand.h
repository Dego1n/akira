// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API RequestCommand : public AbstractSendablePacket
{
private:
	FString command;
public:
	RequestCommand(FString command);
	void Build() override;

};
