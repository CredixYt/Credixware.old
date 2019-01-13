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
		/* THIRDPERSON */
		bool bThirdperson = true;
		float ThirdpersonDistance = 5.0f;
		short ThirdpersonToggleKey = VK_MENU;

		/* BUNNYHOP & AUTOSTRAFE */
		bool bBunnyhop = true;
		short BunnyhopKey = VK_SPACE;
	}
	namespace Rage {
		bool bAntiaim = true;
		AntiAimType_t antiAimType = ANTIAIM_NONE;
		bool bSilentAim = true;
		SilentAimType_t silentAimType = SILENTAIM_CLOSEST_TO_CROSSHAIR;
	}

	namespace Visuals {
		bool bChams = true;
		bool bChamsOnlyEnemies = false;
		bool bChamsHandChams = true;

		/*               WARNING: RANT                  */
		/*                                              */
		/*    I just can't seem to understand why       */
		/*    these motherf*ckers can't make it so      */
		/*  that if you input a color code bigger than  */
		/*  1.0f it divides by 255 and if it's less     */
		/*  than 1.0f it doesn't. Because now I have    */
		/*   to write this ugly ass code to divide      */
		/*  my color codes by 255, so I can use the     */
		/*  standard color codes everyone else uses!    */
		/*              Thank you Valve!                */
		/*                                              */
		/*                  RANT END                    */

		float enemyBehindWallR =	193.0f / 255;
		float enemyBehindWallG =	30.0f  / 255;
		float enemyBehindWallB =	54.0f  / 255;
		float enemyIgnoreZR =		0.0f   / 255;
		float enemyIgnoreZG =		179.0f / 255;
		float enemyIgnoreZB =		235.0f / 255;

		float allyBehindWallR =		193.0f / 255;
		float allyBehindWallG =		30.0f  / 255;
		float allyBehindWallB =		54.0f  / 255;
		float allyIgnoreZR =		0.0f   / 255;
		float allyIgnoreZG =		179.0f / 255;
		float allyIgnoreZB =		235.0f / 255;

		float handChamsR = 235.0f / 255;
		float handChamsG = 254.0f / 255;
		float handChamsB = 3.0f  / 255;

		/*float handChamsR = 116.0f / 255;
		float handChamsG = 111.0f / 255;
		float handChamsB = 210.0f / 255;*/
	}
}

QAngle oldViewAngles;
float antiAimX = 0.0f;
float antiAimY = 0.0f;
float antiAimZ = 0.0f;
QAngle silentAimViewAngles;

#endif