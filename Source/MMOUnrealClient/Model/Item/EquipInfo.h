//
// Created by Dego1n on 01.07.2019.
//

// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "EquipInfo.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FEquipInfo
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 rightHand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 leftHand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 helmet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 upperArmor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 lowerArmor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 gloves;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 boots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 belt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 earring1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 earring2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ring1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ring2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 necklace;
};
