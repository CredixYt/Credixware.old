// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef SKINCHANGER_H
#define SKINCHANGER_H

#include "../SDK/SDK.h"

/* NOTE: Changed by FireEventClientSide.h */
bool bKnifeEquipped = false;

namespace Skinchanger {
	void Update() {
		/*IClientEntity* LocalPlayer = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
		UINT* hWeapons = (UINT*)((DWORD)LocalPlayer->GetBaseEntity() + 0x2DF8);
		for (int i = 0; hWeapons[i]; i++) {
			int iItemDefinition = *(int*)hWeapons[i] + 0x2FAA;
			printf("%i\n", iItemDefinition);
		}*/
		for(int i = 0; i < g_pClientEntityList->GetHighestEntityIndex(); i++) {
			IClientEntity* Entity = g_pClientEntityList->GetClientEntity(i);
			if (Entity) {
				ClientClass* EntityClass = Entity->GetClientClass();
				if (EntityClass->m_ClassID == 136 /* || !_strcmpi("CPredictedViewModel", EntityType) */) {
					C_BaseEntity* BaseEntity = Entity->GetBaseEntity();
					if (BaseEntity && bKnifeEquipped) {
						int karam = g_pModelInfo->GetModelIndex("models/weapons/v_knife_karam.mdl");
						BaseEntity->SetModelIndex(karam);
					}
				}
			}
		}
	}
}

#endif