#pragma once

#include "CoreMinimal.h"
#include "NetworkConfig.generated.h"

/**
 * @author Dego1n
 */
UCLASS(Config=Game)
class MMOUNREALCLIENT_API UNetworkConfig : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(config)
	FString AuthServerAddress = "127.0.0.1";
	
	UPROPERTY(config)
	int32 AuthServerPort = 4784;

	UPROPERTY(config)
	int16 AuthProtocolVersion = 0x02;
};
