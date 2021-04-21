// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidget/Windows/Dialogs/Buylist/BaseBuyListItemSlot.h"
#include "BaseBuyListBuyTab.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseBuyListBuyTab : public UUserWidget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "BaseBuyList", BlueprintCallable)
	void RequestBuyItems(int32 buyListId, TArray<UBaseBuyListItemSlot*> slots);
};
