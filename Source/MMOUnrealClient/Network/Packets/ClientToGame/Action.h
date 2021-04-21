// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractSendablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API Action : public AbstractSendablePacket
{
private:
	int32 objectId;
	bool isShiftPressed;
public:
	Action(int32 id) : Action(id, false) {};
	Action(int32 id, bool isShiftPressed);
	void Build() override;
};
