// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

float nightmode1;
float nightmode2;
float nightmode3;

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

enum KnifeType_t {
	KNIFE_DEFAULT_T = 1,
	KNIFE_DEFAULT_CT = 2,
	KNIFE_BAYONET,
	KNIFE_FLIP,
	KNIFE_GUT,
	KNIFE_KARAM,
	KNIFE_M9_BAY,
	KNIFE_TACTICAL,
	KNIFE_FALCHION_ADVANCED,
	KNIFE_SURVIVAL_BOWIE,
	KNIFE_BUTTERFLY,
	KNIFE_PUSH,
	KNIFE_WIDOWMAKER,
	KNIFE_URSUS,
	KNIFE_STILETTO,
	KNIFE_GYPSY_JACKKNIFE
};

std::string KnifeModels[] = {
	"models/weapons/v_knife_default.mdl",
	"models/weapons/v_knife_default_t.mdl",
	"models/weapons/v_knife_default_ct.mdl",
	"models/weapons/v_knife_bayonet.mdl",
	"models/weapons/v_knife_flip.mdl",
	"models/weapons/v_knife_gut.mdl",
	"models/weapons/v_knife_karam.mdl",
	"models/weapons/v_knife_m9_bay.mdl",
	"models/weapons/v_knife_tactical.mdl",
	"models/weapons/v_knife_falchion_advanced.mdl",
	"models/weapons/v_knife_survival_bowie.mdl",
	"models/weapons/v_knife_butterfly.mdl",
	"models/weapons/v_knife_push.mdl",
	"models/weapons/v_knife_widowmaker.mdl",
	"models/weapons/v_knife_ursus.mdl",
	"models/weapons/v_knife_stiletto.mdl",
	"models/weapons/v_knife_gypsy_jackknife.mdl"
};

namespace Settings {
	namespace Misc {
		/* THIRDPERSON */
		bool bThirdpersonEnabled = true;
		bool bThirdperson = true;
		float ThirdpersonDistance = 5.0f;
		short ThirdpersonToggleKey = VK_MENU;

		/* BUNNYHOP & AUTOSTRAFE */
		bool bBunnyhop = false;
		short BunnyhopKey = VK_SPACE;

		/* CONFIG */
		int SelectedConfig = 0;

		/* NIGHTMODE */
		bool bNightmodeEnabled = false;
	}
	namespace Rage {
		bool bAntiaim = false;
		AntiAimType_t antiAimType = ANTIAIM_NONE;
		bool bSilentAim;
	}

	namespace Visuals{

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

		// ESP
		bool bEspEnabled;
		bool bESPOnlyEnemies;
		bool bBoneESP;
		bool bNameESP;
		bool bHealthESP;
		bool bWeaponESPCheckbox;
		bool bHealtBar;
		float espRSlider;
		float espGSlider;
		float espBSlider;
	}

	namespace SkinChanger {
		/* KNIFE CHANGER */
		bool bKnifeChangerEnabled = false;
		int Knife = 0;
		int KnifeSkin = 0;
		float KnifeWear = 0.0f;
		bool bKnifeStattrak = false;
		int KnifeStattrak = 0;

		/* SKIN CHANGER */
		bool bSkinChangerEnabled = false;
		int CurrentWeapon = 0;
		int WeaponSkin;
		float WeaponWear;
		bool bWeaponStattrak;
		int WeaponStattrak;
	}
}

QAngle oldViewAngles;
float antiAimX = 0.0f;
float antiAimY = 0.0f;
float antiAimZ = 0.0f;
QAngle silentAimViewAngles;
matrix3x4_t antiAimBones[128];

#endif