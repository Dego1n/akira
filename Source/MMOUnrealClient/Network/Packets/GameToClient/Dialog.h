#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API Dialog : public AbstractRecivablePacket
{
public:
	Dialog(TArray <int8> packet);
	~Dialog();
private:
	void Handle();
};
