#include "PlayableActorInfo.h"
#include "Database/AssetDatabase.h"
#include "Network/Game/Thread/GameSocketThread.h"
#include "Model/WorldInstance.h"

/**
 * @author Dego1n
 */
PlayableActorInfo::PlayableActorInfo(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] PlayableActorInfo"));
	#endif

	this->Handle();
}

PlayableActorInfo::~PlayableActorInfo()
{

}

void PlayableActorInfo::Handle()
{


	int32 actorId = ReadD();
	int16 raceId = ReadH();
	int32 characterClassId = ReadH();

	int32 locationX = ReadD();
	int32 locationY = ReadD();
	int32 locationZ = ReadD();

	int32 collisionHeight = ReadD();
	int32 collisionRadius = ReadD();

	FVector locationVector;
	locationVector.X = locationX;
	locationVector.Y = locationY;
	locationVector.Z = locationZ;


	FString name = ReadS();

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, actorId, locationVector, name, raceId, collisionHeight, collisionRadius]() {
		
		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(actorId);
		if(actor == nullptr)
		{
			actor = GameSocketThread::Runnable->world->SpawnActor<AGameActor>(locationVector,FRotator::ZeroRotator);
		}
		
		actor->id = actorId;
		actor->race = raceId;
		actor->UpdateSkeletalMesh();
		actor->UpdateName(name);
		actor->UpdateCollision(collisionHeight,collisionRadius);
		actor->LoadAnimations();
		actor->SpawnDefaultController();
		actor->AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
		WorldInstance::GetInstance()->AddPlayerToWorld(actor);
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}

