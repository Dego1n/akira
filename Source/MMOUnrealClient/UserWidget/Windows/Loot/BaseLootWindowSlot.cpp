// MMOClient 2019


#include "BaseLootWindowSlot.h"
#include "WorldGameInstance.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Network/Packets/ClientToGame/RequestTakeLoot.h"

UTexture2D* UBaseLootWindowSlot::GetTexture(int32 item_id)
{
	FItemTable item = GetItemTableObject(item_id);
	auto* texture = LoadObject<UTexture2D>(NULL, *item.icon.ToString());

	return texture;
}
FItemTable UBaseLootWindowSlot::GetItemTableObject(int32 item_id)
{
	auto* wgi = Cast<UWorldGameInstance>(GetGameInstance());
	return *(wgi->itemsTable->FindRow<FItemTable>(FName(*FString::FromInt(item_id)), "", true));
}

void UBaseLootWindowSlot::LootItem(int32 objId, int32 actorObjId)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("Trying to loot item"));
#endif

#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, FString::FromInt(objId));
#endif
	GameSocketThread::Runnable->SendPacket(new RequestTakeLoot(actorObjId, objId));
}