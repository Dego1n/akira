// MMOClient 2020

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Sound2DTable.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FSound2DTable : public FTableRowBase
{
	GENERATED_BODY()
public:
	FSound2DTable() {

	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText path;
};
