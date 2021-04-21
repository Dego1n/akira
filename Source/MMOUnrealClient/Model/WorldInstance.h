#pragma once

#include "CoreMinimal.h"
#include "Model/Actor/PlayableCharacter.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API WorldInstance
{
private: 
	TArray<AGameActor*> players;
public:
	static WorldInstance* instance;
	static WorldInstance* GetInstance();
	
	WorldInstance();
	virtual ~WorldInstance();

	void AddPlayerToWorld(AGameActor* character);
	void RemoveActorFromWorld(AGameActor* actor);
	AGameActor* GetPlayerById(int32 id);
};
