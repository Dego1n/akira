#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API TargetSelected : public AbstractRecivablePacket
{
public:
	TargetSelected(TArray <int8> packet);
	~TargetSelected();

private:
	void Handle();
};
