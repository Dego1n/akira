// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidget/Windows/Dialogs/Buylist/BaseBuyListItemSlot.h"
#include "BaseBuyListSellTab.generated.h"
/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseBuyListSellTab : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "BaseSellList", BlueprintCallable)
	void RequestSellItems(int32 buyListId, TArray<UBaseBuyListItemSlot*> slots);
};
