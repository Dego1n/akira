// MMOClient 2019


#include "BaseActionBarSlot.h"
#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Network/Packets/ClientToGame/RequestUseAbility.h"

void UBaseActionBarSlot::UseSkill(int32 skillId)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("[Trying to use skill id %d from spell book]"), skillId));
#endif
	if (GameSocketThread::Runnable != nullptr)
	{
		GameSocketThread::Runnable->SendPacket(new RequestUseAbility(skillId));
	}
}
