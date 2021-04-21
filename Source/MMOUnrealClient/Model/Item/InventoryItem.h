// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FInventoryItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 object_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 item_id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool stackable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 price;

	bool operator== (const FInventoryItem& Other) const
	{
		return item_id == Other.item_id;
	}
	friend uint32 GetTypeHash(const FInventoryItem& Other)
	{
		return GetTypeHash(Other.item_id);
	}
};
