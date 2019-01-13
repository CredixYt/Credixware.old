// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef SILENTAIM_H
#define SILENTAIM_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

namespace SilentAim {
	void Shoot() {
		if (Settings::Rage::bSilentAim && Settings::Rage::silentAimType != SILENTAIM_NONE) {
			if (Settings::Rage::silentAimType == SILENTAIM_CLOSEST_TO_CROSSHAIR) {
				/*for (int i = 0; i < g_pClientEntityList->GetHighestEntityIndex(); i++) {
					IClientEntity* Entity = g_pClientEntityList->GetClientEntity(i);
					if (Entity) {
						matrix3x4_t BoneMatrix[128];
						Entity->SetupBones(BoneMatrix, 128, 0x00000100, 0.0f);
						Vector HeadVector = Vector(BoneMatrix[8][0][3], BoneMatrix[8][1][3], BoneMatrix[8][2][3]);
						//printf("%i: %.1f	%.1f	%.1f\n", i, HeadVector.x, HeadVector.y, HeadVector.z);
					}
				}*/
			}
		}
	}
}

#endif