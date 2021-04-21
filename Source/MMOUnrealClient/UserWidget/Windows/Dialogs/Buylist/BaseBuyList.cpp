// MMOClient 2019


#include "BaseBuyList.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Model/Actor/PlayableCharacter.h"

UTexture2D* UBaseBuyList::GetTexture(int32 item_id) {

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
FItemTable UBaseBuyList::GetItemTableObject(int32 item_id)
{
	auto* wgi = Cast<UWorldGameInstance>(GetGameInstance());
	return *(wgi->itemsTable->FindRow<FItemTable>(FName(*FString::FromInt(item_id)), "", true));
}
int32 UBaseBuyList::GetCurrencyAmount(int32 currencyId)
{
	APlayableCharacter* actor = GameSocketThread::Runnable->character;
	return actor->GetItemAmount(currencyId);
}

FText UBaseBuyList::GetCurrencyName(int32 currency_id)
{
	if (currency_id == 0)
		return *new FText();

	FItemTable item = GetItemTableObject(currency_id);
	//	if (item == nullptr)
	//	{
	//		return nullptr;
	//	}
	return item.name;
}
