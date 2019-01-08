// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef DRAWMODELEXECUTE_H
#define DRAWMODELEXECUTE_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"

typedef void(__thiscall* DrawModelExecute_t)(void*, void*, const DrawModelState_t &state, const ModelRenderInfo_t &pInfo, matrix3x4_t *pCustomBoneToWorld);
DrawModelExecute_t oDrawModelExecute;
unsigned int* oDrawModelExecuteFunc;

void __fastcall hkDrawModelExecute(void* ecx, void* edx, void* thisptr, const DrawModelState_t &state, const ModelRenderInfo_t &pInfo, matrix3x4_t *pCustomBoneToWorld) {
	oDrawModelExecute(ecx, thisptr, state, pInfo, pCustomBoneToWorld);
}

#endif