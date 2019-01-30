// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef HACKS_H
#define HACKS_H

#include "AntiAim.h"
#include "Backtrack.h"
#include "Bunnyhop.h"
#include "Chams.h"
#include "ClantagChanger.h"
#include "ESP.h"
#include "Events.h"
#include "Glow.h"
#include "GrenadeHelper.h"
#include "HitChance.h"
#include "Menu.h"
#include "Nightmode.h"
#include "SilentAim.h"
#include "Skinchanger.h"
#include "Thirdperson.h"

namespace Hacks {
	void Init() {
		Menu::Init();
		ESP::Init();
		SkinChanger::Init();
		ClantagChanger::Init();
		/* NOTE: Chams needs to be initalized last, because it will halt until we are in game */
		Chams::Init();
	}

	void Reset() {
		Nightmode::Reset();
		//Thirdperson::Reset();
		DeleteMaterials();
	}
}

#endif