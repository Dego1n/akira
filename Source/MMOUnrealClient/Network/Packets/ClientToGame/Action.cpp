#include "Action.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

/**
 * @author Dego1n
 */
Action::Action(int32 id, bool isShiftPressed = false)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] Action"));
#endif

	this->objectId = id;
	this->isShiftPressed = isShiftPressed;

	Build();
	PrepareForSend();
}
void Action::Build()
{
	WriteH(ClientToGamePackets::Packet::ACTION);

	WriteD(objectId);
	WriteH(isShiftPressed);
}