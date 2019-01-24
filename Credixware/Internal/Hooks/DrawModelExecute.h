// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef DRAWMODELEXECUTE_H
#define DRAWMODELEXECUTE_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"

typedef void(__thiscall* DrawModelExecute_t)(void*, void*, const DrawModelState_t &state, const ModelRenderInfo_t &pInfo, matrix3x4_t *pCustomBoneToWorld);
DrawModelExecute_t oDrawModelExecute;
unsigned int* oDrawModelExecuteFunc;

void __fastcall hkDrawModelExecute(void* ecx, void* edx, void* thisptr, const DrawModelState_t &state, const ModelRenderInfo_t &pInfo, matrix3x4_t *pCustomBoneToWorld) {
	if (!Chams::bFinished) {
		Chams::Init();
	}

	IClientEntity* LocalEntity = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());

	if (pInfo.pModel && LocalEntity) {
		IClientEntity* Entity = g_pClientEntityList->GetClientEntity(pInfo.entity_index);
		if (Entity) {
			int LocalTeam = *reinterpret_cast<int*>((DWORD)LocalEntity->GetBaseEntity() + Offsets::m_iTeamNum);
			int EntityTeam = *reinterpret_cast<int*>((DWORD)Entity->GetBaseEntity() + Offsets::m_iTeamNum);
			if (Entity && (!Settings::Visuals::bChamsOnlyEnemies || EntityTeam != LocalTeam)) {
				ClientClass* EntityClass = Entity->GetClientClass();
				if (EntityClass) {
					const char* entityType = EntityClass->GetName();
					if (EntityClass->m_ClassID == CCSPLAYER && Entity->entindex() != g_pEngineClient->GetLocalPlayer() && Settings::Visuals::bChams) {
						if (Chams::enemyBehindWall && Chams::enemyIgnoreZ) {
							g_pModelRender->ForcedMaterialOverride(Chams::enemyIgnoreZ);
							oDrawModelExecute(ecx, thisptr, state, pInfo, pCustomBoneToWorld);
							g_pModelRender->ForcedMaterialOverride(Chams::enemyBehindWall);
						}
					}
					if (Settings::Visuals::bChamsHandChams && EntityClass->m_ClassID == CPREDICTEDVIEWMODEL) {
						if (Chams::handChams) {
							g_pModelRender->ForcedMaterialOverride(Chams::handChams);
						}
					}
					if (pInfo.entity_index == g_pEngineClient->GetLocalPlayer() && Settings::Misc::bThirdperson) {
						g_pModelInfo->GetModelMaterialCount(pInfo.pModel);
						// TODO: Make player see through (AlphaModulate)
					}
				}
			}
			if (Entity->entindex() == g_pEngineClient->GetLocalPlayer()) {
				g_pModelRender->ForcedMaterialOverride(Chams::handChams);
				oDrawModelExecute(ecx, thisptr, state, pInfo, antiAimBones);
			}
		}
	}
	oDrawModelExecute(ecx, thisptr, state, pInfo, pCustomBoneToWorld);
	g_pModelRender->ForcedMaterialOverride(NULL);
}

#endif