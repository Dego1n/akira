#pragma once

#include "CoreMinimal.h"
#include "ServerStruct.generated.h"

/**
 * @author Dego1n
 * ��������� Game �������, ������ �������� �� ServerList
 */
USTRUCT(BlueprintType)
struct MMOUNREALCLIENT_API FServerStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Server Struct")
	int32 ServerId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Server Struct")
	FString ServerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Server Struct")
	FString ServerAddress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Server Struct")
	int32 ServerPort;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Server Struct")
	int32 ServerStatus;
};
