// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef OVERRIDEVIEW_H
#define OVERRIDEVIEW_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"

typedef void(__thiscall* OverrideView_t)(void*, CViewSetup*);
OverrideView_t oOverrideView;
unsigned int* oOverrideViewFunc;

void __fastcall hkOverrideView(void* ecx, void* edx, CViewSetup* setup) {
	if (g_pEngineClient->IsInGame()) {
		if (g_pInput) {
			if (Settings::Misc::bThirdperson && !GetAsyncKeyState(Settings::Misc::ThirdpersonOffKey)) {
				g_pInput->m_fCameraInThirdPerson = true;
				Vector vec = CalculateCameraOffset(g_pInput->m_angPreviousViewAngles, Settings::Misc::ThirdpersonDistance);
				g_pInput->m_vecCameraOffset.x = vec.x;
				g_pInput->m_vecCameraOffset.y = vec.y;
				g_pInput->m_vecCameraOffset.z = vec.z;
			}
			else {
				g_pInput->m_fCameraInThirdPerson = false;
			}
		}
	}
	oOverrideView(ecx, setup);
}

#endif