// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef NIGHTMODE_H
#define NIGHTMODE_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

namespace Nightmode {
	void Perform() {
		for (MaterialHandle_t i = g_pMaterialSystem->FirstMaterial(); i < g_pMaterialSystem->GetNumMaterials(); i = g_pMaterialSystem->NextMaterial(i)) {
			IMaterial* mat = g_pMaterialSystem->GetMaterial(i);
			if (mat) {
				const char* groupName = mat->GetTextureGroupName();
				std::string GroupName = groupName;

				if ((GroupName.find("World") || GroupName.find("Model") || GroupName.find("StaticProp"))) {
					mat->ColorModulate(0.25f, 0.25f, 0.5f);
				}
			}
		}
		Chams::Init();
		Menu::Init();
	}

	void Reset() {
		for (MaterialHandle_t i = g_pMaterialSystem->FirstMaterial(); i < g_pMaterialSystem->GetNumMaterials(); i = g_pMaterialSystem->NextMaterial(i)) {
			IMaterial* mat = g_pMaterialSystem->GetMaterial(i);
			if (mat) {
				const char* groupName = mat->GetTextureGroupName();
				std::string GroupName = groupName;

				if ((GroupName.find("World") || GroupName.find("Model") || GroupName.find("StaticProp"))) {
					mat->ColorModulate(1.0f, 1.0f, 1.0f);
				}
			}
		}
		Chams::Init();
		Menu::Init();
	}
}

#endif