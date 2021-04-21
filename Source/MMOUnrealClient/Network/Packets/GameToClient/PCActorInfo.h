// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API PCActorInfo : public AbstractRecivablePacket
{
public:
	PCActorInfo(TArray <int8> packet);
	~PCActorInfo();

private:
	void Handle();
};
