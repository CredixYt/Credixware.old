// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef RENDERGLOWEFFECTS_H
#define RENDERGLOWEFFECTS_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"

typedef void(__thiscall* RenderGlowEffects_t)(void*, const CViewSetup*, int);
RenderGlowEffects_t oRenderGlowEffects;
unsigned int* oRenderGlowEffectsFunc;

void __fastcall hkRenderGlowEffects(void* ecx, void* edx, const CViewSetup *pSetup, int nSplitScreenSlot) {
	printf("hkRenderGlowEffects\n");
	oRenderGlowEffects(ecx, pSetup, nSplitScreenSlot);
}

#endif