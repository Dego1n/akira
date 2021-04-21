// MMOClient 2019


#include "StatusInfo.h"
#include "Model/Actor/GameActor.h"
#include "Model/Actor/PlayableCharacter.h"
#include "Model/WorldInstance.h"

/**
 * @author Dego1n
 */
StatusInfo::StatusInfo(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] StatusInfo"));
#endif

	this->Handle();
}

StatusInfo::~StatusInfo()
{

}

void StatusInfo::Handle()
{


	int32 actorId = ReadD();
	int32 level = ReadD();
	int32 currentHp = ReadD();
	int32 maxHp = ReadD();
	int32 currentMp = ReadD();
	int32 maxMp = ReadD();
	int32 startLevelExperience = ReadD();
	int32 currentExperience = ReadD();
	int32 experienceToNextLevel = ReadD();

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, actorId, level, currentHp, maxHp, currentMp, maxMp, startLevelExperience, currentExperience, experienceToNextLevel]() {

		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(actorId);
		if (actor != nullptr)
		{
			if (APlayableCharacter* pc = dynamic_cast<APlayableCharacter*>(actor))
			{
				pc->UpdateStatusInfo(level, currentHp, maxHp, currentMp, maxMp, startLevelExperience, currentExperience, experienceToNextLevel);
			}
		}
	}
		, TStatId(), nullptr, ENamedThreads::GameThread);
}

