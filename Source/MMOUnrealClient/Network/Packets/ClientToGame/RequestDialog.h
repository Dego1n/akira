#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API RequestDialog : public AbstractSendablePacket
{
private:
	int32 objectId;
	FString dialog;
public:
	RequestDialog(int32 objectId, FString dialog);
	void Build() override;
};
