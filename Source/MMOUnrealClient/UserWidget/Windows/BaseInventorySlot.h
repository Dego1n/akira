// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Database/Item/ItemTable.h"
#include "BaseInventorySlot.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseInventorySlot : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 objectId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 itemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 count;

    UFUNCTION(BlueprintCallable, Category = "BaseInventory", BlueprintCallable)
    UTexture2D* GetTexture(int32 item_id);

    UFUNCTION(BlueprintImplementableEvent, Category = "BaseInventory", BlueprintCallable)
    void UpdateIconTexture(UTexture2D* texture);

    UFUNCTION(BlueprintCallable, Category = "BaseInventory", BlueprintCallable)
    FItemTable GetItemTableObject(int32 item_id);

    UFUNCTION(BlueprintCallable, Category = "BaseInventory", BlueprintCallable)
    void UseItem();
};
