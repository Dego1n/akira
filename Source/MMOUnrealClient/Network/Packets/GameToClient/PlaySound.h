// MMOClient 2020

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API PlaySound : public AbstractRecivablePacket
{
public:
	PlaySound(TArray <int8> packet);
	~PlaySound();

private:
	void Handle();
};
