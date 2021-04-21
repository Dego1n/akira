#include "CharacterList.h"
#include "Model/Actor/PlayableCharacter.h"
#include "Network/Game/Thread/GameSocketThread.h"

/**
 * @author Dego1n
 */
CharacterList::CharacterList(TArray<int8> packet) : AbstractRecivablePacket(packet)
{
	#if !UE_BUILD_SHIPPING
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("[Game -> Client] CharacterList"));
	#endif
	this->Handle();
}

CharacterList::~CharacterList()
{
}

void CharacterList::Handle()
{
	int16 count = ReadH(); 


	TArray<APlayableCharacter*> characters;
	for (int i = 0; i < count; i++)
	{
		APlayableCharacter* character = NewObject<APlayableCharacter>();
		
		character->id = ReadD();
		character->name = ReadS();

		FVector location;
		location.X = ReadD();
		location.Y = ReadD();
		location.Z = ReadD();

		character->race = ReadH();
		character->characterClass = ReadH();

		character->SetActorLocation(location);

		characters.Add(character);
	}
	GameSocketThread::Runnable->ReceivedCharacterList(characters);
}