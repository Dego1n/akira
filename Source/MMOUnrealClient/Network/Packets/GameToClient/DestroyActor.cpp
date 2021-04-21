// Fill out your copyright notice in the Description page of Project Settings.

#include "DestroyActor.h"
#include "Model/Actor/GameActor.h"
#include "Model/WorldInstance.h"

/**
 * @author Dego1n
 */
DestroyActor::DestroyActor(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] DestroyActor"));
	#endif
	this->Handle();
}

DestroyActor::~DestroyActor()
{
}


void DestroyActor::Handle()
{
	int32 objectId = ReadD();

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, objectId]() {
		AGameActor* actor = WorldInstance::GetInstance()->GetPlayerById(objectId);
	
		if(actor != nullptr)
		{
			actor->Destroy();
		}
	}
	, TStatId(), nullptr, ENamedThreads::GameThread);

}