// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef BACKTRACK_H
#define BACKTRACK_H

#include "../Headers/Interfaces.h"
#include "../Headers/Offsets.h"
#include "../Hacks/Settings.h"
#include "../Headers/MenuWrapper.h"

#include <vector>

#define TICK_INTERVAL			( g_pGlobalVars->interval_per_tick )
#define TIME_TO_TICKS( dt )		( (int)( 0.5f + (float)(dt) / TICK_INTERVAL ) )
#define TICKS_TO_TIME(t) (g_pGlobalVars->interval_per_tick * (t) )

struct BacktrackData_t {
	float time;
	int sequence;
	int tick;
	Vector HeadPos;
};

float clamp(float num, float min, float max) {
	if (num < min) {
		return min;
	} else if (num > max) {
		return max;
	}
	return num;
}

float lerpTime()
{
	float ud_rate = g_pCvar->FindVar("cl_updaterate")->GetFloat();
	ConVar *min_ud_rate = g_pCvar->FindVar("sv_minupdaterate");
	ConVar *max_ud_rate = g_pCvar->FindVar("sv_maxupdaterate");

	if (min_ud_rate && max_ud_rate)
		ud_rate = max_ud_rate->GetFloat();

	float ratio = g_pCvar->FindVar("cl_interp_ratio")->GetFloat();

	if (ratio == 0)
		ratio = 1.0f;

	float lerp = g_pCvar->FindVar("cl_interp")->GetFloat();

	ConVar *c_min_ratio = g_pCvar->FindVar("sv_client_min_interp_ratio");
	ConVar *c_max_ratio = g_pCvar->FindVar("sv_client_max_interp_ratio");
	//printf("lerp(): %f	%f	%f\n", lerp, ratio, ud_rate);
	return max(lerp, (ratio / ud_rate));
}

namespace Backtrack {
	BacktrackData_t Data[128][64];
	void Init() {

	}

	void Reset() {

	}

	void Tick(CUserCmd* pCmd) {
		/*ConVar* FakeLag = g_pCvar->FindVar("net_fakelag");
		FakeLag->SetValue(0.0f);
		IClientEntity* LocalEntity = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
		Vector LocalPlayerLoc = GetBone(LocalEntity->GetBaseEntity(), 1);
		int LocalTeam = *reinterpret_cast<int*>((DWORD)LocalEntity + Offsets::m_iTeamNum);
		for (int i = 0; i < g_pClientEntityList->GetHighestEntityIndex(); i++) {
			IClientEntity* Entity = g_pClientEntityList->GetClientEntity(i);
			if (!Entity)
				continue;

			if (Entity->entindex() == g_pEngineClient->GetLocalPlayer())
				continue;

			if (Entity->GetClientClass()->m_ClassID != CCSPLAYER)
				continue;

			int EntityTeam = *reinterpret_cast<int*>((DWORD)Entity + Offsets::m_iTeamNum);
			if (LocalTeam == EntityTeam)
				continue;

			int EntityHealth = *reinterpret_cast<int*>((DWORD)LocalEntity + Offsets::m_iHealth);
			if (EntityHealth < 1)
				continue;

			C_BaseEntity* BaseEntity = Entity->GetBaseEntity();
			if (!BaseEntity)
				continue;

			Vector HitboxPosition = GetBone(BaseEntity, 8);
			BacktrackData_t data;
			data.HeadPos = HitboxPosition;
			data.sequence = pCmd->command_number;
			data.tick = pCmd->tick_count;
			data.time = g_pEngineClient->Time();
			Data[Entity->entindex()][pCmd->command_number % 64] = data;

			int closestIndex = -1;
			float closestDistance = 360.0f;

			if (pCmd->buttons & IN_ATTACK) {
				for (int x = 0; x < 64; x++) {
					BacktrackData_t cData = Data[Entity->entindex()][x];

					LocalPlayerLoc.z += 64.0f;
					float Distance = sqrt(pow((cData.HeadPos.x - LocalPlayerLoc.x), 2) + pow((cData.HeadPos.y - LocalPlayerLoc.y), 2) + pow((cData.HeadPos.z - LocalPlayerLoc.z), 2));
					float AngleX = ((asin((cData.HeadPos.z - LocalPlayerLoc.z) / Distance) * 180 / 3.14159265358979323846) * -1);
					float AngleY = (atan2(cData.HeadPos.x - LocalPlayerLoc.x, cData.HeadPos.y - LocalPlayerLoc.y) / 3.14159265358979323846 * 180);
					AngleY = -AngleY + 90.0f;
					while (AngleY > 180.0f) {
						AngleY -= 360.0f;
					}

					QAngle ViewAngles;
					g_pEngineClient->GetViewAngles(ViewAngles);

					float dist = AngleY - ViewAngles.y;
					if (dist < closestDistance) {
						closestDistance = dist;
						closestIndex = x;
					}
				}
				INetChannelInfo* pNetChannel = g_pEngineClient->GetNetChannelInfo();
				//*(int*)((DWORD)pNetChannel + 0x1C) -= TIME_TO_TICKS(0.1f);

				ConVar* FakeLag = g_pCvar->FindVar("net_fakelag");
				const float SV_MAXUNLAG = 1.0f;
				float latency = pNetChannel->GetLatency(1);
				float m_flLerpTime = lerpTime();
				printf("%f\n", m_flLerpTime);
				int lerpTicks = TIME_TO_TICKS(m_flLerpTime);
				printf("5\n");
				float correct = clamp(latency + TICKS_TO_TIME(lerpTicks), 0.0f, SV_MAXUNLAG);
				printf("6\n");
				float deltaTime = correct - TICKS_TO_TIME(pCmd->tick_count - Data[Entity->entindex()][closestIndex].tick + 1);
				printf("7\n");
				float Value = (fabs(deltaTime) * 1000) - 200;

				printf("Lagged by %f\n", Value);
				FakeLag->SetValue(Value);
				
				closestIndex = -1;
				closestDistance = 360.0f;
			}
		}*/
	}
}

#endif