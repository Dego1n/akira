// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"

/**
 * @author Dego1n
 */
class MMOUNREALCLIENT_API ActorInfo : public AbstractRecivablePacket
{
public:
	ActorInfo(TArray <int8> packet);
	~ActorInfo();

private:
	void Handle();
};
