// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef SKINCHANGER_H
#define SKINCHANGER_H

#include "../SDK/SDK.h"

/* NOTE: Changed by FireEventClientSide.h */
bool bKnifeEquipped = false;
int iLocalID = 0;

void ForceSkin(IClientEntity* Weapon, int SkinID)
{
	printf("1\n");
	int* IDHigh = (int*)(Weapon + Offsets::m_iItemIDHigh);
	if (IDHigh == nullptr)
		return;

	printf("2\n");
	*IDHigh = -1;

	int* ItemDefinition = (int*)(Weapon + Offsets::m_iItemDefinitionIndex);
	printf("%i\n", *ItemDefinition);

	printf("3\n");
	int* PaintKit = (int*)(Weapon + Offsets::m_nFallbackPaintKit);
	*PaintKit = SkinID;
	printf("4\n");

	printf("5\n");
	int* Wear = (int*)(Weapon + Offsets::m_flFallbackWear);
	*Wear = 0.0f;
	printf("6\n");

	printf("7\n");
	int* Seed = (int*)(Weapon + Offsets::m_nFallbackSeed);
	*Seed = 0.0f;
	printf("8\n");
}

template <typename T>
auto GetEntityFromHandle(CBaseHandle h) -> T*
{
	return (T*)(g_pClientEntityList->GetClientEntityFromHandle(h));
}


namespace SkinChanger {
	IClientEntity* LocalEntity;
	void Init() {
		player_info_t localPlayer;
		LocalEntity = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
		if (g_pEngineClient->GetPlayerInfo(g_pEngineClient->GetLocalPlayer(), &localPlayer)) {
			iLocalID = localPlayer.user_id;
		}
	}
	void Update() {	
		if ((/*Settings::SkinChanger::bGloveChangerEnabled ||*/ Settings::SkinChanger::bSkinChangerEnabled)) {
			/*IClientEntity* LocalEntity = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
			int* hMyWeapons = (int*)(LocalEntity + Offsets::m_hMyWeapons);
			for (int i = 0; i < 64; i++) {
				printf("Weapon: %i\n", hMyWeapons[i]);
			}*/
		}

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