// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef HITCHANCE_H
#define HITCHANCE_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

namespace HitChance {
	float GetHitChance(Vector EyePos, IClientEntity* Entity) {
		/*Ray_t ray;
		ray.Init(EyePos, GetBone(Entity->GetBaseEntity(), 1));
		ITraceFilter* pFilter;
		trace_t* pTrace;
		g_pEngineTrace->TraceRay(ray, (0xFFFFFFFF), pFilter, pTrace);*/
		return 0.0f;
	}
}

#endif