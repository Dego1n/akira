#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API CharacterSelected : public AbstractSendablePacket
{
private:
	FString selected_character_id;
public:
	CharacterSelected(FString id);
	void Build() override;
};
