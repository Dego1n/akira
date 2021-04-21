#include "CharacterSelected.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"

/**
 * @author Dego1n
 */
CharacterSelected::CharacterSelected(int32 id)
{
#if !UE_BUILD_SHIPPING
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] CharacterSelected"));
#endif

	this->selected_character_id = id;

	Build();
	PrepareForSend();
}
void CharacterSelected::Build()
{
	WriteH(ClientToGamePackets::Packet::CHARACTER_SELECTED);

	WriteD(selected_character_id);
}