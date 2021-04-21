#pragma once

#include "CoreMinimal.h"
#include "Network/Packets/AbstractRecivablePacket.h"


/**
 * @author Dego1n 
 * ѕакет который присылает сервер если авторизаци€ на сервере прошла успешна.
 * ¬ пакете мы получаем game_session_key, закрываем соединение с Auth сервером и подключаемс€ с полученным ключем на Game сервер
 */
class MMOUNREALCLIENT_API GameServerAuthOk : public AbstractRecivablePacket
{
public:
	GameServerAuthOk(TArray<int8> packet);
	~GameServerAuthOk();
private:
	void Handle();
};
