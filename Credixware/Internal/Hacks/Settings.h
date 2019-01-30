// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

float nightmode1;
float nightmode2;
float nightmode3;

enum ESPBoxType_t {
	ESPBOX_NONE = 0,
	ESPBOX_DEFAULT = 1,
	ESPBOX_CORNERED = 2,
	ESPBOX_VERTICALLINE = 3,
	ESPBOX_HORIZONTALLINE = 4,
	ESPBOX_LINES = 5
};

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

int KnifeDefinitions_t[] {
	41,
	59,
	42,
	500,
	505,
	506,
	507,
	508,
	509,
	510,
	511,
	515,
	516,
	523,
	519,
	522,
	520
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

enum ChamMaterials_t {
	MATERIAL_NONE = 0,
	MATERIAL_LIT = 1,
	MATERIAL_UNLIT = 2,
	MATERIAL_METALIC = 3
};

enum ESPHealthBarType_t {
	HEALTHBAR_NONE = 0,
	HEALTHBAR_BAR = 1,
	HEALTHBAR_TEXT = 2
};

namespace Settings {
	namespace Rage {
		/* ANTI AIM */
		bool bAntiaim = false;
		AntiAimType_t antiAimType = ANTIAIM_NONE;
		/* SILENT AIM */
		bool bSilentAim;
	}
	namespace Visuals{
		/* CHAMS */
		bool bChamsEnabled = true;
		int chamsMaterial = MATERIAL_NONE;
		bool bChamsEnemiesNormal = false;
		bool bChamsEnemiesIgnoreZ = false;
		bool bChamsAlliesNormal = false;
		bool bChamsAlliesIgnoreZ = false;
		bool bChamsHandChamsEnabled = false;
		bool bChamsWeaponChamsEnabled = false;


		float chamsEnemiesNormalR = 193.0f;
		float chamsEnemiesNormalG = 30.0f;
		float chamsEnemiesNormalB = 54.0f;
		float chamsEnemiesIgnoreZR = 0.0f;
		float chamsEnemiesIgnoreZG = 179.0f;
		float chamsEnemiesIgnoreZB = 235.0f;

		float chamsAlliesNormalR = 46.0f;
		float chamsAlliesNormalG = 204.0f;
		float chamsAlliesNormalB = 113.0f;
		float chamsAlliesIgnoreZR = 16.0f;
		float chamsAlliesIgnoreZG = 109.0f;
		float chamsAlliesIgnoreZB = 90.0f;

		float chamsHandChamsR = 235.0f;
		float chamsHandChamsG = 254.0f;
		float chamsHandChamsB = 3.0f;

		float chamsWeaponChamsR = 235.0f;
		float chamsWeaponChamsG = 254.0f;
		float chamsWeaponChamsB = 3.0f;

		/* GLOW */
		bool bGlowEnabled = false;
		bool bGlowOnlyEnemies = false;
		bool bGlowIgnoreZ = false;
		float glowEnemiesIgnoreZR = 0.0f;
		float glowEnemiesIgnoreZG = 0.0f;
		float glowEnemiesIgnoreZB = 0.0f;
		float glowEnemiesNormalR = 0.0f;
		float glowEnemiesNormalG = 0.0f;
		float glowEnemiesNormalB = 0.0f;
		float glowAllyR = 0.0f;
		float glowAllyG = 0.0f;
		float glowAllyB = 0.0f;

		/* ESP */
		bool bEspEnabled = false;
		int espBoxType = ESPBOX_NONE;
		bool bESPEnemiesNormal = false;
		float espEnemiesNormalR = 255.0f;
		float espEnemiesNormalG = 255.0f;
		float espEnemiesNormalB = 255.0f;
		bool bESPEnemiesIgnoreZ = false;
		float espEnemiesIgnoreZR = 193.0f;
		float espEnemiesIgnoreZG = 30.0f;
		float espEnemiesIgnoreZB = 54.0f;
		bool bESPAlliesNormal = false;
		float espAlliesNormalR = 193.0f;
		float espAlliesNormalG = 30.0f;
		float espAlliesNormalB = 54.0f;
		bool bESPAlliesIgnoreZ = false;
		float espAlliesIgnoreZR = 193.0f;
		float espAlliesIgnoreZG = 30.0f;
		float espAlliesIgnoreZB = 54.0f;
		bool bESPBone = false;
		bool bESPName = false;
		bool bESPHealth = false;
		int espHealtBar = HEALTHBAR_NONE;
		bool bESPWeapon = false;

		/* GRENADE TRAJECTORY */
		bool bGrenadeTrajectoryEnabled = false;
		bool bGrenadeTrajectoryShowDamage = false;
		float grenadeTrajectoryR = 255.0f;
		float grenadeTrajectoryG = 255.0f;
		float grenadeTrajectoryB = 255.0f;
	}
	namespace SkinChanger {
		/* KNIFE CHANGER */
		bool bKnifeChangerEnabled = false;
		int Knife = 0;
		int KnifeSkin = 0;
		float KnifeWear = 0.0f;
		bool bKnifeStattrak = false;
		int KnifeStattrak = 0;

		/* GLOVE CHANGER */
		bool bGloveChangerEnabled = true;
		int Glove = 1;
		int GloveSkin = 0;

		/* SKIN CHANGER */
		bool bSkinChangerEnabled = false;
		int CurrentWeapon = 0;
		int WeaponSkin;
		float WeaponWear;
		bool bWeaponStattrak;
		int WeaponStattrak;
	}
	namespace Misc {
		/* THIRDPERSON */
		bool bThirdpersonEnabled = false;
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

		/* CLAN TAG CHANGER */
		bool bClanTagChangerEnabled = false;
	}
}

QAngle oldViewAngles;
float antiAimX = 0.0f;
float antiAimY = 0.0f;
float antiAimZ = 0.0f;
QAngle silentAimViewAngles;
matrix3x4_t antiAimBones[128];

#endif