// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef FIREEVENTCLIENTSIDE_H
#define FIREEVENTCLIENTSIDE_H

#include <Windows.h>
#pragma comment(lib, "Winmm.lib") 

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"
#include "../Headers/MenuWrapper.h"

typedef bool(__thiscall* FireEventClientSide_t)(void*, IGameEvent*);
FireEventClientSide_t oFireEventClientSide;
unsigned int* oFireEventClientSideFunc;

bool __fastcall hkFireEventClientSide(void* ecx, void* edx, IGameEvent* pEvent) {
	if (!pEvent) {
		return oFireEventClientSide(ecx, pEvent);
	}

	if (_strcmpi(pEvent->GetName(), "item_equip") == 0) {
		int weaponType = pEvent->GetInt("weptype");
		int userID = pEvent->GetInt("userid");
		if (weaponType == WEAPONTYPE_KNIFE && userID == iLocalID) {
			bKnifeEquipped = true;
		}
		else {
			bKnifeEquipped = false;
		}
	} else if (_strcmpi(pEvent->GetName(), "player_spawn") == 0) {
		player_info_t localPlayer;

		if (g_pEngineClient->GetPlayerInfo(g_pEngineClient->GetLocalPlayer(), &localPlayer)) {
			iLocalID = localPlayer.user_id;
		}
		
	} else if (_strcmpi(pEvent->GetName(), "game_newmap") == 0 && Settings::Misc::bNightmodeEnabled) {
		Nightmode::Perform();
	} else if (_strcmpi(pEvent->GetName(), "game_newmap") == 0 && !Settings::Misc::bNightmodeEnabled) {
		Nightmode::Reset();
	}
	return oFireEventClientSide(ecx, pEvent);
}

#endif