#ifndef SDK_H
#define SDK_H

#include "math/mathlib.h"
#include "basetypes.h"
#include "C_BaseCombatWeapon.h"
#include "C_BaseEntity.h"
#include "C_BasePlayer.h"
#include "C_BaseViewModel.h"
#include "CGlobalVars.h"
#include "CGlowObjectManager.h"
#include "CInput.h"
#include "ClientClass.h"
#include "Color.h"
#include "ConVar.h"
#include "CViewSetup.h"
#include "CUserCmd.h"
#include "IAppSystem.h"
#include "IClientEntity.h"
#include "IClientEntityList.h"
#include "IClientNetworkable.h"
#include "IClientPanel.h"
#include "IClientRenderable.h"
#include "IClientThinkable.h"
#include "IGameEvent.h"
#include "IHTML.h"
#include "IImage.h"
#include "IInput.h"
#include "ImageFormat.h"
#include "IMaterial.h"
#include "IMaterialSystem.h"
#include "Interface.h"
#include "IPanel.h"
#include "ISurface.h"
#include "IVEngineClient.h"
#include "IVModelInfo.h"
#include "IVModelRender.h"
#include "KeyValues.h"

enum {
	WEAPONTYPE_UNKNOWN = -1,
	WEAPONTYPE_KNIFE = 0,
	WEAPONTYPE_PISTOL = 1,
	WEAPONTYPE_SUBMACHINEGUN = 2,
	WEAPONTYPE_RIFLE = 3,
	WEAPONTYPE_SHOTGUN = 4,
	WEAPONTYPE_SNIPER_RIFLE = 5,
	WEAPONTYPE_MACHINEGUN = 6,
	WEAPONTYPE_C4 = 7,
	WEAPONTYPE_TASER = 8,
	WEAPONTYPE_GRENADE = 9,
	WEAPONTYPE_HEALTHSHOT = 11
};

#endif