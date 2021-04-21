// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API AcquireSkillList : public AbstractRecivablePacket
{
public:
	AcquireSkillList(TArray <int8> packet);
	~AcquireSkillList();

private:
	void Handle();
};
