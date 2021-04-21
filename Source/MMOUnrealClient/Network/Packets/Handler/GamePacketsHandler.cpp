#include "GamePacketsHandler.h"
#include "Network/Packets/Enum/GameToClientPackets.h"
#include "Network/Packets/GameToClient/MoveActorToLocation.h"
#include "Network/Packets/GameToClient/CharacterList.h"
#include "Network/Packets/GameToClient/CharacterSelectedOk.h"
#include "Network/Packets/GameToClient/UserInfo.h"
#include "Network/Packets/GameToClient/PlayableActorInfo.h"
#include "Network/Packets/GameToClient/DestroyActor.h"
#include "Network/Packets/GameToClient/ActorInfo.h"
#include "Network/Packets/GameToClient/TargetSelected.h"
#include "Network/Packets/GameToClient/Dialog.h"
#include "Network/Packets/GameToClient/MoveToPawn.h"
#include "Network/Packets/GameToClient/StopMoving.h"
#include "Network/Packets/GameToClient/Attack.h"
#include "Network/Packets/GameToClient/ActorSay.h"
#include "Network/Packets/GameToClient/ActorDied.h"
#include "Network/Packets/GameToClient/SystemMessage.h"
#include "Network/Packets/GameToClient/Inventory.h"
#include "Network/Packets/GameToClient/PCActorInfo.h"
#include "Network/Packets/GameToClient/DebugDrawSpehere.h"
#include "Network/Packets/GameToClient/LootDataUpdated.h"
#include "Network/Packets/GameToClient/AbilitiesList.h"
#include "Network/Packets/GameToClient/UseAbility.h"
#include "Network/Packets/GameToClient/BuyList.h"
#include "Network/Packets/GameToClient/StatusInfo.h"
#include "Network/Packets/GameToClient/SpecialActorInfo.h"
#include "Network/Packets/GameToClient/AcquireSkillList.h"
#include "Network/Packets/GameToClient/QuestList.h"
#include "Network/Packets/GameToClient/PlaySound.h"

/**
 * @author Dego1n
 */
void GamePacketsHandler::Handle(int16 packetId, TArray<int8> packet)
{
	switch (packetId)
	{
		case GameToClientPackets::Packet::CHARACTER_LIST:
			new CharacterList(packet);
			break;

		case GameToClientPackets::Packet::CHARACTER_SELECTED_OK:
			new CharacterSelectedOk(packet);
			break;

		case GameToClientPackets::Packet::MOVE_ACTOR_TO_LOCATION:
			new MoveActorToLocation(packet);
			break;	
		
		case GameToClientPackets::Packet::USER_INFO:
			new UserInfo(packet);
			break;

		case GameToClientPackets::Packet::PLAYABLE_ACTOR_INFO:
			new PlayableActorInfo(packet);
			break;

		case GameToClientPackets::Packet::DESTROY_ACTOR:
			new DestroyActor(packet);
			break;
		
		case GameToClientPackets::Packet::ACTOR_INFO:
			new ActorInfo(packet);
			break;

		case GameToClientPackets::Packet::TARGET_SELECTED:
			new TargetSelected(packet);
			break;

		case GameToClientPackets::Packet::Dialog:
			new Dialog(packet);
			break;

		case GameToClientPackets::Packet::MOVE_TO_PAWN:
			new MoveToPawn(packet);
			break;

		case GameToClientPackets::Packet::STOP_MOVING:
			new StopMoving(packet);
			break;

		case GameToClientPackets::Packet::ATTACK:
			new Attack(packet);
			break;

		case GameToClientPackets::Packet::SYSTEM_MESSAGE:
			new SystemMessage(packet);
			break;

		case GameToClientPackets::Packet::ACTOR_SAY:
			new ActorSay(packet);
			break;

		case GameToClientPackets::Packet::ACTOR_DIED:
			new ActorDied(packet);
			break;
		
		case GameToClientPackets::Packet::INVENTORY:
			new Inventory(packet);
			break;

		case GameToClientPackets::Packet::ABILITIES_LIST:
			new AbilitiesList(packet);
			break;

		case GameToClientPackets::Packet::PC_ACTOR_INFO:
			new PCActorInfo(packet);
			break;
				
		case GameToClientPackets::Packet::DEBUG_DRAW_SPHERE:
			new DebugDrawSpehere(packet);
			break;

		case GameToClientPackets::Packet::LOOT_DATA_UPDATED:
			new LootDataUpdated(packet);
			break;

		case GameToClientPackets::Packet::USE_ABILITY:
			new UseAbility(packet);
			break;

		case GameToClientPackets::Packet::BUYLIST:
			new BuyList(packet);
			break;

		case GameToClientPackets::Packet::STATUS_INFO:
			new StatusInfo(packet);
			break;

		case GameToClientPackets::Packet::SPECIAL_ACTOR_INFO:
			new SpecialActorInfo(packet);
			break;

		case GameToClientPackets::Packet::ACQUIRE_SKILL_LIST:
			new AcquireSkillList(packet);
			break;
		
		case GameToClientPackets::Packet::QUEST_LIST:
			new QuestList(packet);
			break;

		case GameToClientPackets::Packet::PLAY_SOUND:
			new PlaySound(packet);
			break;
	}
}