#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API CharacterSelected : public AbstractSendablePacket
{
private:
	int32 selected_character_id;
public:
	CharacterSelected(int32 id);
	void Build() override;
};
