#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API PlayableActorInfo : public AbstractRecivablePacket
{
public:
	PlayableActorInfo(TArray <int8> packet);
	~PlayableActorInfo();

private:
	void Handle();
};
