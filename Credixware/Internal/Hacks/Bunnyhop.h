// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef BUNNYHOP_H
#define BUNNYHOP_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

namespace Bunnyhop {
	IClientEntity* LocalEntity = NULL;

	void Init() {
		LocalEntity = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
	}

	void Tick(CUserCmd* pCmd) {
		if (!Settings::Misc::bBunnyhop || !GetAsyncKeyState(Settings::Misc::BunnyhopKey)) {
			return;
		}

		if (!LocalEntity || LocalEntity == NULL) {
			Init();
			return;
		}

		int fFlags = *reinterpret_cast<int*>((DWORD)LocalEntity->GetBaseEntity() + 0x104);
		if (fFlags & FL_ONGROUND) {
			pCmd->buttons |= IN_JUMP;
		}
	}
}

#endif