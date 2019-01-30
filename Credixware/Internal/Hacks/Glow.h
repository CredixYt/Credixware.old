// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef GLOW_H
#define GLOW_H

#include "../Headers/Interfaces.h"
#include "../Headers/Offsets.h"
#include "../Hacks/Settings.h"

#define END_OF_FREE_LIST -1
#define ENTRY_IN_USE -2

struct GlowObjectDefinition_t {
	C_BaseEntity* m_pEntity;
	Vector m_vGlowColor;
	float m_flGlowAlpha;
	char __unknown00[8];
	float m_flBloomAmount;
	char __unknown01[4];
	bool m_bRenderWhenOccluded;
	bool m_bRenderWhenUnoccluded;
	bool m_bFullBloomRender;
	char __unknown02;
	int m_nFullBloomStencilTestValue;
	char __unknown03[4];
	int m_nSplitScreenSlot;
	int m_nNextFreeSlot;
};

namespace Glow {
	void Init() {

	}
	void Render() {
		if (!Settings::Visuals::bGlowEnabled)
			return;

		if (!g_pEngineClient->IsInGame())
			return;

		IClientEntity* LocalEntity = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
		int LocalTeam = *(int*)(LocalEntity + Offsets::m_iTeamNum);
		DWORD GlowObjectManager = *(DWORD*)g_pGlowObjectManager;

		for (int i = 0; i < g_pClientEntityList->GetHighestEntityIndex(); i++) {
			IClientEntity* Entity = g_pClientEntityList->GetClientEntity(i);
			if (!Entity)
				continue;

			ClientClass* EntityClass = Entity->GetClientClass();
			if (!EntityClass)
				continue;

			if (EntityClass->m_ClassID != CCSPLAYER)
				continue;

			int EntityTeam = *(int*)(Entity + Offsets::m_iTeamNum);
			if (Settings::Visuals::bGlowOnlyEnemies) {
				int GlowIndex = *reinterpret_cast<int*>((DWORD)Entity + Offsets::m_iGlowIndex);
				if (EntityTeam != LocalTeam) {
					*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x4)) = Settings::Visuals::glowEnemiesIgnoreZR / 255.0f;
					*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x8)) = Settings::Visuals::glowEnemiesIgnoreZG / 255.0f;
					*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0xC)) = Settings::Visuals::glowEnemiesIgnoreZB / 255.0f;
					*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x10)) = 1.0f;
					*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x1C)) = 0.75f;
					*(bool*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x24)) = false;
					*(bool*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x25)) = true;
				}
			}
			else {
				int GlowIndex = *reinterpret_cast<int*>((DWORD)Entity + Offsets::m_iGlowIndex);
				if (EntityTeam == LocalTeam) {
					*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x4)) = Settings::Visuals::glowAllyR / 255.0f;
					*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x8)) = Settings::Visuals::glowAllyG / 255.0f;
					*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0xC)) = Settings::Visuals::glowAllyB / 255.0f;
				}
				else {
					*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x4)) = Settings::Visuals::glowEnemiesIgnoreZR / 255.0f;
					*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x8)) = Settings::Visuals::glowEnemiesIgnoreZG / 255.0f;
					*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0xC)) = Settings::Visuals::glowEnemiesIgnoreZB / 255.0f;
				}
				*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x10)) = 1.0f;
				*(float*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x1C)) = 0.75f;
				*(bool*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x24)) = false;
				*(bool*)(GlowObjectManager + ((GlowIndex * 0x38) + 0x25)) = true;
			}
		}
	}
}

#endif