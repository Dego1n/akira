// MMOClient 2019


#include "SpecialActorInfo.h"
#include "Model/Actor/GameActor.h"
#include "Network/Game/Thread/GameSocketThread.h"

SpecialActorInfo::SpecialActorInfo(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] SpecialActorInfo"));
#endif
	this->Handle();
}

SpecialActorInfo::~SpecialActorInfo()
{
}

void SpecialActorInfo::Handle()
{

	FString name = ReadS();
	int32 level = ReadD();
	int32 currentHp = ReadD();
	int32 maxHp = ReadD();
	int32 currentMp = ReadD();
	int32 maxMp = ReadD();

	int32 physAttack = ReadD();
	int32 physDefence = ReadD();

	
	FFunctionGraphTask::CreateAndDispatchWhenReady([this, name, level, currentHp, maxHp, currentMp, maxMp, physAttack, physDefence]() {

		APlayableCharacter* actor = GameSocketThread::Runnable->character;

		if (actor != nullptr)
		{
			//void SpecialCharacterInfoWidget(FString name, int32 level, int32 currentHp, int32 maxHp, int32 currentMp, int32 maxMp, int32 pAtk, int32 pDef);
			actor->SpecialCharacterInfoWidget(name, level, currentHp, maxHp, currentMp, maxMp, physAttack, physDefence);
		}
		}
	, TStatId(), nullptr, ENamedThreads::GameThread);
}
