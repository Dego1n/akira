#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API UserInfo : public AbstractRecivablePacket
{
public:
	UserInfo(TArray <int8> packet);
	~UserInfo();

private:
	void Handle();
};
