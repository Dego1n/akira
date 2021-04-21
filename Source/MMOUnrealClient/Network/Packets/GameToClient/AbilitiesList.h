// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API AbilitiesList : public AbstractRecivablePacket
{
public:
	AbilitiesList(TArray <int8> packet);
	~AbilitiesList();

private:
	void Handle();
};
