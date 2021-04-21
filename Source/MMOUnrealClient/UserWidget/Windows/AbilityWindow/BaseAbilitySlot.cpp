// MMOClient 2019


#include "BaseAbilitySlot.h"
#include "WorldGameInstance.h"
#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Network/Packets/ClientToGame/RequestUseAbility.h"

UTexture2D* UBaseAbilitySlot::GetTexture(int32 item_id)
{
	FAbilityTable ability = GetAbilityTableObject(item_id);
	auto* texture = LoadObject<UTexture2D>(NULL, *ability.icon);

	return texture;
}
FAbilityTable UBaseAbilitySlot::GetAbilityTableObject(int32 item_id)
{
	auto* wgi = Cast<UWorldGameInstance>(GetGameInstance());
	return *(wgi->abilitiesData->FindRow<FAbilityTable>(FName(*FString::FromInt(item_id)), "", true));
}

void UBaseAbilitySlot::UseSkill(int32 skillId)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("[Trying to use skill id %d from spell book]"), skillId));
	#endif
	if (GameSocketThread::Runnable != nullptr)
	{
		GameSocketThread::Runnable->SendPacket(new RequestUseAbility(skillId));
	}
		
}
