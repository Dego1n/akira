// MMOClient 2019

#include "BaseInventorySlot.h"
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "WorldGameInstance.h"
#include "Network/Packets/ClientToGame/UseItem.h"
#include "Network/Game/Thread/GameSocketThread.h"


UTexture2D* UBaseInventorySlot::GetTexture(int32 item_id) {

	if (item_id == 0)
		return NULL;

    FItemTable item = GetItemTableObject(item_id);
//	if (item == nullptr)
//	{
//		return nullptr;
//	}
    auto *texture = LoadObject<UTexture2D>(NULL, *item.icon.ToString());

    return texture;
}
FItemTable UBaseInventorySlot::GetItemTableObject(int32 item_id)
{
    auto *wgi = Cast<UWorldGameInstance>(GetGameInstance());
    return *(wgi->itemsTable->FindRow<FItemTable>(FName(*FString::FromInt(item_id)), "", true));
}

void UBaseInventorySlot::UseItem() {
#if !UE_BUILD_SHIPPING
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("Trying to use item"));
#endif

    #if !UE_BUILD_SHIPPING
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, FString::FromInt(objectId));
    #endif
    GameSocketThread::Runnable->SendPacket(new class UseItem(objectId));
}