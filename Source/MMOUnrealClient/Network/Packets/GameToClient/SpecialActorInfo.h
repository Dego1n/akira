// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API SpecialActorInfo : public AbstractRecivablePacket
{
public:
	SpecialActorInfo(TArray <int8> packet);
	~SpecialActorInfo();

private:
	void Handle();
};
