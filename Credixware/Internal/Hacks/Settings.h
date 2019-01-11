// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef SETTINGS_H
#define SETTINGS_H

enum AntiAimType_t {
	ANTIAIM_NONE = -1,
	ANTIAIM_SLOW_SPIN = 0,
	ANTIAIM_RANDOM_SPIN = 1,
	ANTIAIM_YAW_DOWN = 2,
	ANTIAIM_YAW_RANDOM = 3
};

enum SilentAimType_t {
	SILENTAIM_NONE = -1,
	SILENTAIM_CLOSEST_TO_BASE = 0,
	SILENTAIM_CLOSEST_TO_CROSSHAIR = 1
};

namespace Settings {
	namespace Misc {
		bool bThirdperson = true;
		float ThirdpersonDistance = 5.0f;
		short ThirdpersonOffKey = VK_MENU;
	}
	namespace Rage {
		bool bAntiaim = true;
		AntiAimType_t antiAimType = ANTIAIM_SLOW_SPIN;
		bool bSilentAim = true;
		SilentAimType_t silentAimType = SILENTAIM_CLOSEST_TO_CROSSHAIR;
	}
}

QAngle oldViewAngles;
float antiAimX = 0.0f;
float antiAimY = 0.0f;
float antiAimZ = 0.0f;
QAngle silentAimViewAngles;

#endif