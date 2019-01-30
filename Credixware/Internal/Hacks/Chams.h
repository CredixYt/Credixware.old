// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef CHAMS_H
#define CHAMS_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

namespace Chams {
	IMaterial* enemiesNormal = nullptr;
	IMaterial* enemiesIgnoreZ = nullptr;
	IMaterial* alliesNormal = nullptr;
	IMaterial* alliesIgnoreZ = nullptr;
	IMaterial* handChams = nullptr;
	IMaterial* weaponChams = nullptr;
	const char* chamType = "VertexLitGeneric";
	bool bMetalic = false;
	bool bFlat = false;

	bool bFinished = false;

	void Init() {
		if (!g_pEngineClient->IsInGame()) return;
		if (Settings::Visuals::chamsMaterial == MATERIAL_NONE) {
			enemiesNormal = nullptr;
			enemiesIgnoreZ = nullptr;
			alliesNormal = nullptr;
			alliesIgnoreZ = nullptr;
			handChams = nullptr;
			weaponChams = nullptr;
			bFinished = true;
			return;
		} else if (Settings::Visuals::chamsMaterial == MATERIAL_LIT) {
			chamType = "VertexLitGeneric";
			bFlat = false;
		} else if (Settings::Visuals::chamsMaterial == MATERIAL_UNLIT) {
			chamType = "UnlitGeneric";
			bFlat = true;
		} else if (Settings::Visuals::chamsMaterial == MATERIAL_METALIC) {
			chamType = "VertexLitGeneric";
			bFlat = false;
			bMetalic = true;
		}
		enemiesNormal = CreateCustomMaterial("credixware_enemiesNormal", false, bFlat, bMetalic, chamType);
		enemiesNormal->ColorModulate(Settings::Visuals::chamsEnemiesNormalR / 255.0f, Settings::Visuals::chamsEnemiesNormalG / 255.0f, Settings::Visuals::chamsEnemiesNormalB / 255.0f);

		enemiesIgnoreZ = CreateCustomMaterial("credixware_enemiesIgnoreZ", true, bFlat, bMetalic, chamType);
		enemiesIgnoreZ->ColorModulate(Settings::Visuals::chamsEnemiesIgnoreZR / 255.0f, Settings::Visuals::chamsEnemiesIgnoreZG / 255.0f, Settings::Visuals::chamsEnemiesIgnoreZB / 255.0f);

		alliesNormal = CreateCustomMaterial("credixware_alliesNormal", false, bFlat, bMetalic, chamType);
		alliesNormal->ColorModulate(Settings::Visuals::chamsAlliesNormalR / 255.0f, Settings::Visuals::chamsAlliesNormalG / 255.0f, Settings::Visuals::chamsAlliesNormalB / 255.0f);

		alliesIgnoreZ = CreateCustomMaterial("credixware_alliesIgnoreZ", true, bFlat, bMetalic, chamType);
		alliesIgnoreZ->ColorModulate(Settings::Visuals::chamsAlliesIgnoreZR / 255.0f, Settings::Visuals::chamsAlliesIgnoreZG / 255.0f, Settings::Visuals::chamsAlliesIgnoreZB / 255.0f);

		handChams = CreateCustomMaterial("credixware_handChams", false, bFlat, bMetalic, chamType);
		handChams->ColorModulate(Settings::Visuals::chamsHandChamsR / 255.0f, Settings::Visuals::chamsHandChamsG / 255.0f, Settings::Visuals::chamsHandChamsB / 255.0f);

		weaponChams = CreateCustomMaterial("credixware_weaponChams", false, bFlat, bMetalic, chamType);
		weaponChams->ColorModulate(Settings::Visuals::chamsWeaponChamsR / 255.0f, Settings::Visuals::chamsWeaponChamsG / 255.0f, Settings::Visuals::chamsWeaponChamsB / 255.0f);

		bFinished = true;
	}
}

#endif