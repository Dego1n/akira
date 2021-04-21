// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidget/Windows/BaseInventorySlot.h"
#include "Model/Item/EquipInfo.h"

#include "BaseInventory.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseInventory : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryItems")
	TArray<UBaseInventorySlot*> inventorySlots;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InventoryItems")
    FEquipInfo equipInfo;

	UFUNCTION(BlueprintImplementableEvent, Category = "Inventory Events", BlueprintCallable)
	void ItemListUpdated();
};
