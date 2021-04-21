// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Model/Item/InventoryItem.h"
#include "Database/Item/ItemTable.h"
#include "BaseBuyList.generated.h"

/**
 * 
 */
UCLASS()
class MMOUNREALCLIENT_API UBaseBuyList : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FInventoryItem, int32> buyItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FInventoryItem, int32> sellItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 buylistId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 currencyId;

	UFUNCTION(BlueprintCallable, Category = "BaseBuyList", BlueprintCallable)
	UTexture2D* GetTexture(int32 item_id);

	UFUNCTION(BlueprintCallable, Category = "BaseBuyList", BlueprintCallable)
	FItemTable GetItemTableObject(int32 item_id);

	UFUNCTION(BlueprintCallable, Category = "BaseBuyList", BlueprintCallable)
	int32 GetCurrencyAmount(int32 currency_id);

	UFUNCTION(BlueprintCallable, Category = "BaseBuyList", BlueprintCallable)
	FText GetCurrencyName(int32 currency_id);
};
