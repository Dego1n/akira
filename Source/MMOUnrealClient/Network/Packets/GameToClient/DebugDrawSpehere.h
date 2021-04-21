// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API DebugDrawSpehere : public AbstractRecivablePacket
{
public:
	DebugDrawSpehere(TArray <int8> packet);
	~DebugDrawSpehere();
private:
	void Handle();
};
