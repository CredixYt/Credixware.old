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
	if (pInfo.pModel) {
		IClientEntity* Entity = g_pClientEntityList->GetClientEntity(pInfo.entity_index);
		if (Entity) {
			ClientClass* EntityClass = Entity->GetClientClass();
			if (EntityClass) {
				const char* entityType = EntityClass->GetName();
				std::string EntityType = entityType;
				if (EntityType == "CCSPlayer" && pInfo.entity_index != g_pEngineClient->GetLocalPlayer() && Settings::Visuals::bChams) {
					if (Chams::enemyBehindWall && Chams::enemyIgnoreZ) {
						g_pModelRender->ForcedMaterialOverride(Chams::enemyIgnoreZ);
						oDrawModelExecute(ecx, thisptr, state, pInfo, pCustomBoneToWorld);
						g_pModelRender->ForcedMaterialOverride(Chams::enemyBehindWall);
					}
				}
				if (Settings::Visuals::bChamsHandChams) {
					if (EntityType == "CPredictedViewModel") {
						if (Chams::handChams) {
							g_pModelRender->ForcedMaterialOverride(Chams::handChams);
						}
					}
				}
				if (pInfo.entity_index == g_pEngineClient->GetLocalPlayer() && Settings::Misc::bThirdperson) {
					// TODO: Make player see through (AlphaModulate)
				}
			}
		}
	}
	oDrawModelExecute(ecx, thisptr, state, pInfo, pCustomBoneToWorld);
}

#endif