#pragma once

#include "CoreMinimal.h"
#include "Runnable.h"
#include "RunnableThread.h"

#include "Model/Actor/PlayableCharacter.h"

#include "Network/Game/GameSocket.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 * Тред для чтения пакетов из игрового сокета.
 */
class MMOUNREALCLIENT_API GameSocketThread : public FRunnable
{
private:
	int32 game_session_key;
	FString address;
	int32 port;
public:
	int32 state = 0; // 0 - champion select, 1 - in world
	UWorld* world;
	static GameSocketThread* Runnable;

	FRunnableThread* Thread;

	TArray<APlayableCharacter*> availableCharacters;
	APlayableCharacter* character;

	GameSocket* GameSocket;
	bool stopReceive = false;

	void SendPacket(AbstractSendablePacket* packet);
	static GameSocketThread* StartConnectionThread(int32 game_session_key, FString server_address, int32 server_port, UWorld * world = nullptr);

	void ReceivedCharacterList(TArray<APlayableCharacter*> characters);
	void CharacterSelectedOk();

	// Begin FRunnable interface.
	virtual uint32 Run();
	virtual void Stop();
	// End FRunnable interface

	GameSocketThread(int32 game_session_key, FString server_address, int32 server_port, UWorld* world = nullptr);
	virtual ~GameSocketThread();
};
