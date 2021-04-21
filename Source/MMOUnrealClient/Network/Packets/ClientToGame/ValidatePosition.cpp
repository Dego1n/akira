// MMOClient 2019

#include "ValidatePosition.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

ValidatePosition::ValidatePosition(FVector location, bool stoppedMoving)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] ValidatePosition"));
	#endif

	this->location = location;
	this->stoppedMoving = stoppedMoving;

	Build();
	PrepareForSend();
}

void ValidatePosition::Build()
{
	WriteH(ClientToGamePackets::Packet::VALIDATE_POSITION);

	WriteD(location.X);
	WriteD(location.Y);
	WriteD(location.Z);
	
	WriteH(stoppedMoving ? 1 : 0);
}