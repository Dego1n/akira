// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AbilityTable.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FAbilityTable : public FTableRowBase
{
	GENERATED_BODY()
public:
	FAbilityTable() {

	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 manaCost;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float castTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString icon;
};
