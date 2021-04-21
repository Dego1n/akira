// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API MoveToPawn : public AbstractRecivablePacket
{
public:
	MoveToPawn(TArray <int8> packet);
	~MoveToPawn();

private:
	void Handle();
};
