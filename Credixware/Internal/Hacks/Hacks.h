// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef HACKS_H
#define HACKS_H

#include "ESP.h"
#include "Menu.h"
#include "Nightmode.h"
#include "SilentAim.h"
#include "Skinchanger.h"
#include "Thirdperson.h"

namespace Hacks {
	void Init() {
		Menu::Init();
		ESP::Init();
	}
}

#endif