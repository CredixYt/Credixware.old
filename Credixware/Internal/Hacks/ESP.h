// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef ESP_H
#define ESP_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

namespace ESP {
	void Init() {

	}
	void Draw() {
		for (int i = 0; i < /*g_pClientEntityList->GetMaxEntities();*/ 128; i++) {
			IClientEntity* Entity = g_pClientEntityList->GetClientEntity(i);
			if (Entity) {
				//Vector AbsOrigin = Entity->GetAbsOrigin();
				//printf("%.2f	%.2f	%.2f\n", AbsOrigin.x, AbsOrigin.y, AbsOrigin.z);
			}
		}
	}
};

#endif