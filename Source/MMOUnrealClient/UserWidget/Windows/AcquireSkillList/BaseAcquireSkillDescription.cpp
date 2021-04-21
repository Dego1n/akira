// MMOClient 2019


#include "BaseAcquireSkillDescription.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Network/Packets/ClientToGame/RequestAcquireSkill.h"

void UBaseAcquireSkillDescription::AcquireAbility(int32 ability_id)
{
	GameSocketThread::Runnable->SendPacket(new RequestAcquireSkill(ability_id));
}