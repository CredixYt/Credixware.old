// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef SKINCHANGER_H
#define SKINCHANGER_H

#include "../SDK/SDK.h"

/* NOTE: Changed by FireEventClientSide.h */
bool bKnifeEquipped = false;
int iLocalID = 0;

namespace Skinchanger {
	void Init() {
		player_info_t localPlayer;

		if (g_pEngineClient->GetPlayerInfo(g_pEngineClient->GetLocalPlayer(), &localPlayer)) {
			iLocalID = localPlayer.user_id;
		}
	}
	void Update() {
		/*IClientEntity* LocalPlayer = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
		UINT* hWeapons = (UINT*)((DWORD)LocalPlayer->GetBaseEntity() + Offsets::m_hMyWeapons);
		for (int i = 0; hWeapons[i]; i++) {
			if (hWeapons[i] > 0) {
				printf("%i: %i\n", hWeapons[i], hWeapons[i]+Offsets::m_iItemDefinitionIndex);
			}
		}*/
		if (Settings::SkinChanger::bKnifeChangerEnabled && Settings::SkinChanger::Knife != 0) {
			for (int i = 0; i < g_pClientEntityList->GetHighestEntityIndex(); i++) {
				IClientEntity* Entity = g_pClientEntityList->GetClientEntity(i);
				if (Entity) {
					ClientClass* EntityClass = Entity->GetClientClass();
					if (strstr(EntityClass->GetName(), "CPredictedViewModel")) {
						C_BaseEntity* BaseEntity = Entity->GetBaseEntity();
						if (BaseEntity && bKnifeEquipped) {
							int karam = g_pModelInfo->GetModelIndex(KnifeModels[Settings::SkinChanger::Knife].c_str());
							BaseEntity->SetModelIndex(karam);
						}
					}
				}
			}
		}
	}
}

#endif