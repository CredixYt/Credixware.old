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
						matrix3x4_t MatrixArray[128];
						Vector BoneLocation;
						Entity->SetupBones(&MatrixArray[0], 128, 0x00000100, 0.0f);
						matrix3x4_t HitboxMatrix = MatrixArray[8];
						BoneLocation = Vector(HitboxMatrix[0][3], HitboxMatrix[1][3], HitboxMatrix[2][3]);
						printf("%f		%f		%f\n", BoneLocation.x, BoneLocation.y, BoneLocation.z);
					}
				}*/
			}
		}
	}
}

#endif