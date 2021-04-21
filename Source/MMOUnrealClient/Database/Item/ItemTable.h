// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemTable.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FItemTable : public FTableRowBase
{
    GENERATED_BODY()
	public:
		FItemTable() {

	}

//	UPROPERTY(EditAnywhere)
//		FText id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText icon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText model;
};
