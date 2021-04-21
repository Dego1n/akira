#include "WorldInstance.h"

/**
 * @author Dego1n
 */
WorldInstance* WorldInstance::instance = NULL;

WorldInstance* WorldInstance::GetInstance()
{
	if(instance == NULL)
		instance = new WorldInstance();

	return instance;
}

WorldInstance::WorldInstance()
{
}

WorldInstance::~WorldInstance()
{
}

void WorldInstance::AddPlayerToWorld(AGameActor* character)
{
	players.Add(character);
}

void WorldInstance::RemoveActorFromWorld(AGameActor* actor)
{
	players.Remove(actor);
}

AGameActor* WorldInstance::GetPlayerById(int32 id)
{

	for(AGameActor* player : players)
	{

		if(player->id == id)
			return player;
	}
	return nullptr;
}
