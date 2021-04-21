#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API RequestCreateCharacter : public AbstractSendablePacket
{
private:
	FString name;
	int32 race;
	int32 characterClass;
public:
	RequestCreateCharacter(FString name, int32 race, int32 characterClass);
	void Build() override;
};
