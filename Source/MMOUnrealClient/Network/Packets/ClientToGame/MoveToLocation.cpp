#include "MoveToLocation.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

/**
 * @author Dego1n
 */
MoveToLocation::MoveToLocation(FVector origin, FVector target)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] MoveToLocation"));
#endif

	this->origin = origin;
	this->target = target;

	Build();
	PrepareForSend();
}
void MoveToLocation::Build()
{
	WriteH(ClientToGamePackets::Packet::MOVE_TO_LOCATION);

	WriteD(origin.X);
	WriteD(origin.Y);
	WriteD(origin.Z);

	WriteD(target.X);
	WriteD(target.Y);
	WriteD(target.Z);
}