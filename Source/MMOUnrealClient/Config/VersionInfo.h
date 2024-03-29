// MMOClient 2019

#pragma once

#include "CoreMinimal.h"
#include "VersionInfo.generated.h"

/**
 * @author Dego1n
 */
UCLASS(Config=GameVersion)
class MMOUNREALCLIENT_API UVersionInfo : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(config)
	int32 VersionRevision = 52;

	UPROPERTY(config)
	FString VersionBranch = "master";

	UPROPERTY(config)
	FString Version = "v0.2";

	UPROPERTY(config)
	FString VersionTime = "06.10.2019 23:21:34";
};
