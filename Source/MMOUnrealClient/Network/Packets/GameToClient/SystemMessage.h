// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API SystemMessage : public AbstractRecivablePacket
{
public:
	SystemMessage(TArray <int8> packet);
	~SystemMessage();
private:
	void Handle();
};
