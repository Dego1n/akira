// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MMOUNREALCLIENT_API ClientToGamePackets
{
public:
	enum Packet
	{
		REQUEST_CONNECT_TO_GAME_SERVER = 0x01,
		CHARACTER_SELECTED = 0x02,
		REQUEST_CREATE_CHARACTER = 0x03,
		MOVE_TO_LOCATION = 0x05,
		ENTER_WORLD = 0x06,
		ACTION = 0x07,
		REQUEST_DIALOG = 0x08,
		REQUEST_ATTACK = 0x09,
		VALIDATE_POSITION = 0x0A,
		//?
		REQUEST_ACQUIRE_SKILL = 0x0E,
		//?
		USE_ITEM = 0x1c,
		//?
		SAY = 0x19,
		REQUEST_INVENTORY = 0x1d,
		REQUEST_COMMAND = 0x1e,
		REQUEST_TAKE_LOOT = 0x1f,
		REQUEST_USE_ABILITY = 0x20,
		REQUEST_BUY = 0x21,
		REQUEST_SELL = 0x22,
		QUEST_TALK = 0x23,
		ROTATION_CHANGED = 0x24
	};
};
