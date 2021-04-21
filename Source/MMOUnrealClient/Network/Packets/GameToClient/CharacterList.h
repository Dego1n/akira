#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API CharacterList : public AbstractRecivablePacket
{
public:
	CharacterList(TArray <int8> packet);
	~CharacterList();

private:
	void Handle();
};
