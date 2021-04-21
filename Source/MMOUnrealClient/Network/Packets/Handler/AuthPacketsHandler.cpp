#include "AuthPacketsHandler.h"

#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "Network/Packets/Enum/AuthToClientPackets.h"

#include "Network/Packets/AuthToClient/ConnectionAccepted.h"
#include "Network/Packets/AuthToClient/ConnectionFailed.h"
#include "Network/Packets/AuthToClient/AuthOk.h"
#include "Network/Packets/AuthToClient/AuthFailed.h"
#include "Network/Packets/AuthToClient/ServerList.h"
#include "Network/Packets/AuthToClient/GameServerAuthOk.h"

/**
 * @author Dego1n
 */
void AuthPacketsHandler::Handle(int16 packetId, TArray<int8> packet)
{
	switch (packetId)
	{
		case AuthToClientPackets::Packet::CONNECTION_ACCEPTED:
			new ConnectionAccepted(packet);
			break;
		case AuthToClientPackets::Packet::AUTH_OK:
			new AuthOk(packet);
			break;
		case AuthToClientPackets::Packet::AUTH_FAILED:
			new AuthFailed(packet);
			break;
		case AuthToClientPackets::Packet::CONNECTION_FAILED:
			new ConnectionFailed(packet);
			break;
		case AuthToClientPackets::Packet::SERVER_LIST:
			new ServerList(packet);
			break;
		case AuthToClientPackets::Packet::GAME_SERVER_AUTH_OK:
			new GameServerAuthOk(packet);
			break;
	}
}