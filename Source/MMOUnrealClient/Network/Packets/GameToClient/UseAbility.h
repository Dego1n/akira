// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API UseAbility : public AbstractRecivablePacket
{
public:
	UseAbility(TArray <int8> packet);
	~UseAbility();

private:
	void Handle();
};
