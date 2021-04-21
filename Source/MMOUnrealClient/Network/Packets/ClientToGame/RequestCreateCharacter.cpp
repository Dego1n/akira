#include "RequestCreateCharacter.h"
#include "Network/Packets/Enum/ClientToGamePackets.h"


RequestCreateCharacter::RequestCreateCharacter(FString name, int32 race, int32 characterClass)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("[Client -> Game] RequestCreateCharacter"));
	#endif

	this->name = name;
	this->race = race;
	this->characterClass = characterClass;

	Build();
	PrepareForSend();
}

void RequestCreateCharacter::Build()
{
	WriteH(ClientToGamePackets::Packet::REQUEST_CREATE_CHARACTER);

	WriteS(name);
	WriteH(race);
	WriteH(characterClass);
}
