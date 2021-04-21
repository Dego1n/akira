// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API StatusInfo : public AbstractRecivablePacket
{
public:
	StatusInfo(TArray <int8> packet);
	~StatusInfo();

private:
	void Handle();
};
