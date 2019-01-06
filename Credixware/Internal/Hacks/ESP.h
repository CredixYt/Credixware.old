// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef ESP_H
#define ESP_H

#include "../Headers/Interfaces.h"

namespace ESP {
	void Init() {

	}
	void Draw() {
		/*g_pSurface->DrawSetColor(255, 255, 0, 255);
		g_pSurface->DrawOutlinedRect(5, 5, 400, 300);*/
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