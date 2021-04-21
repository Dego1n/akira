// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Database/Item/ItemTable.h"
#include "BaseLootWindowSlot.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseLootWindowSlot : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 objectId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 itemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 actorObjectId;

	UFUNCTION(BlueprintCallable, Category = "BaseLootWindow", BlueprintCallable)
	UTexture2D* GetTexture(int32 item_id);

	UFUNCTION(BlueprintImplementableEvent, Category = "BaseLootWindow", BlueprintCallable)
	void UpdateIconTexture(UTexture2D* texture);

	UFUNCTION(BlueprintCallable, Category = "BaseLootWindow", BlueprintCallable)
	FItemTable GetItemTableObject(int32 item_id);

	UFUNCTION(BlueprintCallable, Category = "BaseLootWindow", BlueprintCallable)
	void LootItem(int32 objId, int32 actorObjId);
};
