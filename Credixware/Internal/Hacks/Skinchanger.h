// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef SKINCHANGER_H
#define SKINCHANGER_H

#include "../SDK/SDK.h"

/* NOTE: Changed by FireEventClientSide.h */
bool bKnifeEquipped = false;
int iLocalID = 0;

class Weapon {
public:
	void SetItemDefinition(int iValue) {
		*(int*)(this + Offsets::m_iItemDefinitionIndex) = iValue;
	}
	void SetItemIDHigh(int iValue) {
		*(int*)(this + Offsets::m_iItemIDHigh) = iValue;
	}
	void SetPaintKit(int iValue) {
		*(int*)(this + Offsets::m_nFallbackPaintKit) = iValue;
	}
	void SetSeed(int iValue) {
		*(int*)(this + Offsets::m_nFallbackSeed) = iValue;
	}

	int GetItemDefinition() {
		return *(int*)(this + Offsets::m_iItemDefinitionIndex);
	}
	int GetItemIDHigh() {
		return *(int*)(this + Offsets::m_iItemIDHigh);
	}
	int GetPaintKit() {
		return *(int*)(this + Offsets::m_nFallbackPaintKit);
	}
	int GetSeed() {
		return *(int*)(this + Offsets::m_nFallbackSeed);
	}
};

namespace SkinChanger {
	void Init() {
		player_info_t localPlayer;

		if (g_pEngineClient->GetPlayerInfo(g_pEngineClient->GetLocalPlayer(), &localPlayer)) {
			iLocalID = localPlayer.user_id;
		}
	}
	void Update() {	
		if (Settings::SkinChanger::bKnifeChangerEnabled && Settings::SkinChanger::Knife != 0) {
			for (int i = 0; i < g_pClientEntityList->GetHighestEntityIndex(); i++) {
				IClientEntity* Entity = g_pClientEntityList->GetClientEntity(i);
				if (Entity) {
					ClientClass* EntityClass = Entity->GetClientClass();
					if (EntityClass->m_ClassID == CPREDICTEDVIEWMODEL) {
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