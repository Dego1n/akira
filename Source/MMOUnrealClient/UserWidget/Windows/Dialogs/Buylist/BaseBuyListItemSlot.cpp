// MMOClient 2019


#include "BaseBuyListItemSlot.h"
#include <Runtime/Engine/Classes/Engine/Engine.h>
#include "WorldGameInstance.h"

UTexture2D* UBaseBuyListItemSlot::GetTexture(int32 item_id) {

	if (item_id == 0)
		return NULL;

	FItemTable item = GetItemTableObject(item_id);
	//	if (item == nullptr)
	//	{
	//		return nullptr;
	//	}
	auto* texture = LoadObject<UTexture2D>(NULL, *item.icon.ToString());

	return texture;
}
FItemTable UBaseBuyListItemSlot::GetItemTableObject(int32 item_id)
{
	auto* wgi = Cast<UWorldGameInstance>(GetGameInstance());
	return *(wgi->itemsTable->FindRow<FItemTable>(FName(*FString::FromInt(item_id)), "", true));
}