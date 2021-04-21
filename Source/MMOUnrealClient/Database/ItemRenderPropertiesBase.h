// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemRenderPropertiesBase.generated.h"

/**
 * @autor Dego1n
 */
USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FItemRenderPropertiesBase : public FTableRowBase
{
	GENERATED_BODY()
public:
	FItemRenderPropertiesBase(){
	}
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 itemId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 actorTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float locationX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float locationY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float locationZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float rotationX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float rotationY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float rotationZ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float scaleX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float scaleY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float scaleZ;
};
