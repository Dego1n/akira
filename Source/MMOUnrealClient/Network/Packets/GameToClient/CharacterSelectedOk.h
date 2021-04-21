#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API CharacterSelectedOk : public AbstractRecivablePacket
{
public:
	CharacterSelectedOk(TArray <int8> packet);
	~CharacterSelectedOk();

private:
	void Handle();
};
