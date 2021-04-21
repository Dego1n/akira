// MMOClient 2019


#include "BaseAcquireSkillListSlot.h"
#include "WorldGameInstance.h"
#include "EngineGlobals.h"

UTexture2D* UBaseAcquireSkillListSlot::GetTexture(int32 item_id)
{
	FAbilityTable ability = GetAbilityTableObject(item_id);
	auto* texture = LoadObject<UTexture2D>(NULL, *ability.icon);

	return texture;
}
FAbilityTable UBaseAcquireSkillListSlot::GetAbilityTableObject(int32 item_id)
{
	auto* wgi = Cast<UWorldGameInstance>(GetGameInstance());
	return *(wgi->abilitiesData->FindRow<FAbilityTable>(FName(*FString::FromInt(item_id)), "", true));
}