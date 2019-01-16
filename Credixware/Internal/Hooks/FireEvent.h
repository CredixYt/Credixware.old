// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef FIREEVENT_H
#define FIREEVENT_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"

typedef bool(__thiscall* FireEvent_t)(void*, IGameEvent*, bool);
FireEvent_t oFireEvent;
unsigned int* oFireEventFunc;

bool __fastcall hkFireEvent(void* ecx, void* edx, IGameEvent* pEvent, bool bDontBroadcast) {
	if (!pEvent) {
		return oFireEvent(ecx, pEvent, bDontBroadcast);
	}

	if (_strcmpi(pEvent->GetName(), "item_equip") == 0) {
		int weaponType = pEvent->GetInt("weptype");
		int userID = pEvent->GetInt("userid");
		player_info_t localPlayer;

		/*if (!g_pEngineClient->GetPlayerInfo(g_pEngineClient->GetLocalPlayer(), &localPlayer)) {
			return oFireEvent(ecx, pEvent, bDontBroadcast);
		}
		if (weaponType == WEAPONTYPE_KNIFE && userID == localPlayer.user_id) {
			bKnifeEquipped = true;
		}
		else {
			bKnifeEquipped = false;
		}*/
	}
	return oFireEvent(ecx, pEvent, bDontBroadcast);
}

#endif