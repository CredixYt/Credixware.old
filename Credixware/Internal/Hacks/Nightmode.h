// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef NIGHTMODE_H
#define NIGHTMODE_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

namespace Nightmode {
	void Init() {
		// TODO: Finish InvalidMaterial and GetMaterial crash
		/*for (auto i = g_pMaterialSystem->FirstMaterial(); i != g_pMaterialSystem->InvalidMaterial(); i = g_pMaterialSystem->NextMaterial(i)) {
			printf("%i\n", i);
		}*/
		/*for (auto i = g_pMaterialSystem->FirstMaterial(); i > 100; i = g_pMaterialSystem->NextMaterial(i)) {
			printf("Before!\n");
			IMaterial* mat = g_pMaterialSystem->GetMaterial(i);
			printf("Worked!\n");
		}*/
	}
}

#endif