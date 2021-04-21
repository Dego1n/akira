// MMOClient 2020
#include "RotationChanged.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

/**
 * @author Dego1n
 */
RotationChanged::RotationChanged(float pitch, float yaw)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] RotationChanged"));
#endif

	this->pitch = pitch;
	this->yaw = yaw;

	Build();
	PrepareForSend();
}
void RotationChanged::Build()
{
	WriteH(ClientToGamePackets::Packet::ROTATION_CHANGED);

	WriteD((int)pitch);
	WriteD((int)yaw);
}