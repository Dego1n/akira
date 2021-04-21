// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "QuestTable.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FQuestTable : public FTableRowBase
{
	GENERATED_BODY()
public:
	FQuestTable() {

	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 type;

};
