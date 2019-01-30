// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef DRAWMODELEXECUTE_H
#define DRAWMODELEXECUTE_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"

typedef void(__thiscall* DrawModelExecute_t)(void*, void*, const DrawModelState_t &state, const ModelRenderInfo_t &pInfo, matrix3x4_t *pCustomBoneToWorld);
DrawModelExecute_t oDrawModelExecute;
unsigned int* oDrawModelExecuteFunc;

void __fastcall hkDrawModelExecute(void* ecx, void* edx, void* thisptr, const DrawModelState_t &state, const ModelRenderInfo_t &pInfo, matrix3x4_t *pCustomBoneToWorld) {
	IClientEntity* LocalEntity = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
	int LocalTeam = *reinterpret_cast<int*>((DWORD)LocalEntity->GetBaseEntity() + Offsets::m_iTeamNum);

	if (!pInfo.pModel || !LocalEntity || !Settings::Visuals::bChamsEnabled) {
		oDrawModelExecute(ecx, thisptr, state, pInfo, pCustomBoneToWorld);
		g_pModelRender->ForcedMaterialOverride(NULL);
		return;
	}

	IClientEntity* Entity = g_pClientEntityList->GetClientEntity(pInfo.entity_index);
	if (!Entity) {
		oDrawModelExecute(ecx, thisptr, state, pInfo, pCustomBoneToWorld);
		g_pModelRender->ForcedMaterialOverride(NULL);
		return;
	}

	ClientClass* EntityClass = Entity->GetClientClass();
	if (!Entity) {
		oDrawModelExecute(ecx, thisptr, state, pInfo, pCustomBoneToWorld);
		g_pModelRender->ForcedMaterialOverride(NULL);
		return;
	}

	if (EntityClass->m_ClassID == CCSPLAYER) {
		int EntityTeam = *reinterpret_cast<int*>((DWORD)Entity->GetBaseEntity() + Offsets::m_iTeamNum);
		if (Entity->entindex() == g_pEngineClient->GetLocalPlayer() && Settings::Visuals::bChamsHandChamsEnabled && Chams::handChams && Settings::Misc::bThirdperson) {
			g_pModelRender->ForcedMaterialOverride(Chams::handChams);
		} else if (EntityTeam == LocalTeam) {
			if (Settings::Visuals::bChamsAlliesIgnoreZ && Chams::alliesIgnoreZ) {
				g_pModelRender->ForcedMaterialOverride(Chams::alliesIgnoreZ);
				oDrawModelExecute(ecx, thisptr, state, pInfo, pCustomBoneToWorld);
			}
			if (Settings::Visuals::bChamsAlliesNormal && Chams::alliesNormal) {
				g_pModelRender->ForcedMaterialOverride(Chams::alliesNormal);
			}
		}
		else {
			if (Settings::Visuals::bChamsEnemiesIgnoreZ && Chams::enemiesIgnoreZ) {
				g_pModelRender->ForcedMaterialOverride(Chams::enemiesIgnoreZ);
				oDrawModelExecute(ecx, thisptr, state, pInfo, pCustomBoneToWorld);
			}
			if (Settings::Visuals::bChamsEnemiesNormal && Chams::enemiesNormal) {
				g_pModelRender->ForcedMaterialOverride(Chams::enemiesNormal);
			}
		}
	}
	else if (EntityClass->m_ClassID == CPREDICTEDVIEWMODEL && Settings::Visuals::bChamsWeaponChamsEnabled && Chams::weaponChams) {
		g_pModelRender->ForcedMaterialOverride(Chams::weaponChams);
	}
	oDrawModelExecute(ecx, thisptr, state, pInfo, pCustomBoneToWorld);
	g_pModelRender->ForcedMaterialOverride(NULL);
}

#endif