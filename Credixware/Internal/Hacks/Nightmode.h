// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef NIGHTMODE_H
#define NIGHTMODE_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

namespace Nightmode {
	void Perform() {
		ConVar* DrawSpecificStaticProp = g_pCvar->FindVar("r_DrawSpecificStaticProp");
		DrawSpecificStaticProp->SetValue(0);
		for (MaterialHandle_t i = g_pMaterialSystem->FirstMaterial(); i < g_pMaterialSystem->GetNumMaterials(); i = g_pMaterialSystem->NextMaterial(i)) {
			IMaterial* mat = g_pMaterialSystem->GetMaterial(i);
			if (mat) {
				const char* groupName = mat->GetTextureGroupName();
				if (strstr(groupName, "World")) {
					mat->ColorModulate(0.25f, 0.25f, 0.5f);
				}
				else if (strstr(groupName, "StaticProp")) {
					mat->ColorModulate(0.4f, 0.4f, 0.5f);
				}
			}
		}
	}

	void Reset() {
		//ConVar* DrawSpecificStaticProp = g_pCvar->FindVar("r_DrawSpecificStaticProp");
		//DrawSpecificStaticProp->SetValue(1);
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
	}
}

#endif