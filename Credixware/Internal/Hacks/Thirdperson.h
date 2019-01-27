// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef THIRDPERSON_H
#define THIRDPERSON_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

namespace Thirdperson {
	void Update(CViewSetup* setup) {
		if (Utils::GetKey(Settings::Misc::ThirdpersonToggleKey) && Settings::Misc::bThirdpersonEnabled) {
			Settings::Misc::bThirdperson = !Settings::Misc::bThirdperson;
		}
		if (g_pEngineClient->IsInGame()) {
			if (g_pInput) {
				if (Settings::Misc::bThirdperson && Settings::Misc::bThirdpersonEnabled) {
					g_pInput->m_fCameraInThirdPerson = true;
					Vector vec = CalculateCameraOffset(Vector(oldViewAngles.x, oldViewAngles.y, oldViewAngles.z), Settings::Misc::ThirdpersonDistance);
					g_pInput->m_vecCameraOffset.x = vec.x;
					g_pInput->m_vecCameraOffset.y = vec.y;
					g_pInput->m_vecCameraOffset.z = vec.z;
				}
				else {
					g_pInput->m_fCameraInThirdPerson = false;
				}
			}
		}
	}

	void Reset() {
		Settings::Misc::bThirdperson = false;
		Update(nullptr);
	}
}

#endif