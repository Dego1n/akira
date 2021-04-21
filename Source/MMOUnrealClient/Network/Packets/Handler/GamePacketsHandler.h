#pragma once

#include "CoreMinimal.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API GamePacketsHandler
{
public:
	static void Handle(int16 packetId, TArray<int8> packet);
};
