// MMOClient 2019


#include "DebugDrawSpehere.h"
#include "Model/Actor/GameActor.h"
#include "Model/WorldInstance.h"
#include "DrawDebugHelpers.h"
#include "Network/Game/Thread/GameSocketThread.h"

/**
 * @author Dego1n
 */
DebugDrawSpehere::DebugDrawSpehere(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] DebugDrawSpehere"));
#endif
	this->Handle();
}

DebugDrawSpehere::~DebugDrawSpehere()
{
}


void DebugDrawSpehere::Handle()
{
#if !UE_BUILD_SHIPPING
	int32 loc_x = ReadD();
	int32 loc_y = ReadD();
	int32 loc_z = ReadD();
	int32 radius = ReadD();
	int32 segments = ReadD();
	int32 duration = ReadD();
	int32 thickness = ReadD();

	FFunctionGraphTask::CreateAndDispatchWhenReady([this, loc_x, loc_y, loc_z, radius, segments, duration, thickness]() {
		DrawDebugSphere(
			GameSocketThread::Runnable->world,
			FVector(loc_x,loc_y, loc_z),
			radius,
			segments,
			FColor(255, 0, 0),
			false,
			duration,
			0,
			thickness
		);

	}
	, TStatId(), nullptr, ENamedThreads::GameThread);
#endif
}
