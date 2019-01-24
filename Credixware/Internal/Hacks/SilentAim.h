// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef SILENTAIM_H
#define SILENTAIM_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

namespace SilentAim {
	void Shoot() {
		if (Settings::Rage::bSilentAim) {
			IClientEntity* LocalEntity = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
			if (!LocalEntity)
				return;

			int LocalTeam = *reinterpret_cast<int*>((DWORD)LocalEntity->GetBaseEntity() + Offsets::m_iTeamNum);

			C_BaseEntity* LocalBaseEntity = LocalEntity->GetBaseEntity();
			if (!LocalBaseEntity)
				return;

			float closestDistance = 360.0f;
			int closestIndex = -1;
			Vector LocalPlayerLoc = GetBone(LocalBaseEntity, 1);
			for (int i = 0; i < g_pClientEntityList->GetHighestEntityIndex(); i++) {
				IClientEntity* Entity = g_pClientEntityList->GetClientEntity(i);
				if (!Entity)
					continue;

				int EnemyHealth = *reinterpret_cast<int*>((DWORD)Entity->GetBaseEntity() + Offsets::m_iHealth);
				if (EnemyHealth < 1)
					continue;

				int EnemyTeam = *reinterpret_cast<int*>((DWORD)Entity->GetBaseEntity() + Offsets::m_iTeamNum);
				if (EnemyTeam == LocalTeam)
					continue;

				ClientClass* EntityClass = Entity->GetClientClass();
				if (!EntityClass)
					continue;

				if (_strcmpi(EntityClass->GetName(), "CCSPlayer") != 0 || Entity->entindex() == g_pEngineClient->GetLocalPlayer())
					continue;

				C_BaseEntity* BaseEntity = Entity->GetBaseEntity();
				if (!BaseEntity)
					continue;

				Vector EntityHead = GetBone(BaseEntity, 8);
				Vector EntityBase = GetBone(BaseEntity, 1);
				float Distance = sqrt(pow((EntityBase.x - LocalPlayerLoc.x), 2) + pow((EntityBase.y - LocalPlayerLoc.y), 2) + pow((EntityBase.z - LocalPlayerLoc.z), 2));
				float AngleX = ((asin((EntityBase.z - LocalPlayerLoc.z) / Distance) * 180 / 3.14159265358979323846) * -1);
				float AngleY = (atan2(EntityBase.x - LocalPlayerLoc.x, EntityBase.y - LocalPlayerLoc.y) / 3.14159265358979323846 * 180);
				AngleY = -AngleY + 90.0f;
				while (AngleY > 180.0f) {
					AngleY -= 360.0f;
				}

				QAngle ViewAngles;
				g_pEngineClient->GetViewAngles(ViewAngles);

				float dist = sqrt(pow((ViewAngles.x - AngleX), 2) + pow((ViewAngles.y - AngleY), 2));
				printf("%f	%f	|	%f\n", AngleX, AngleY, dist);

				if (dist < closestDistance) {
					closestDistance = dist;
					closestIndex = i;
				}
			}

			if (closestIndex < 0)
				return;

			IClientEntity* Entity = g_pClientEntityList->GetClientEntity(closestIndex);
			if (!Entity)
				return;

			int EnemyHealth = *reinterpret_cast<int*>((DWORD)Entity->GetBaseEntity() + Offsets::m_iHealth);
			if (EnemyHealth <= 0)
				return;

			int EnemyTeam = *reinterpret_cast<int*>((DWORD)Entity->GetBaseEntity() + Offsets::m_iTeamNum);
			if (EnemyTeam == LocalTeam)
				return;

			ClientClass* EntityClass = Entity->GetClientClass();
			if (!EntityClass)
				return;

			if (_strcmpi(EntityClass->GetName(), "CCSPlayer") != 0 || Entity->entindex() == g_pEngineClient->GetLocalPlayer())
				return;

			C_BaseEntity* BaseEntity = Entity->GetBaseEntity();
			if (!BaseEntity)
				return;

			Vector EntityHead = GetBone(BaseEntity, 8);
			Vector EntityBase = GetBone(BaseEntity, 1);
			int fFlags = *reinterpret_cast<int*>((DWORD)LocalEntity->GetBaseEntity() + Offsets::m_fFlags);
			if (fFlags & FL_DUCKING) {
				LocalPlayerLoc.z += 46.0f;
			}
			else {
				LocalPlayerLoc.z += 64.0f;
			}
			float Distance = sqrt(pow((EntityHead.x - LocalPlayerLoc.x), 2) + pow((EntityHead.y - LocalPlayerLoc.y), 2) + pow((EntityHead.z - LocalPlayerLoc.z), 2));
			float AngleX = ((asin((EntityHead.z - LocalPlayerLoc.z) / Distance) * 180 / 3.14159265358979323846) * -1);
			float AngleY = (atan2(EntityHead.x - LocalPlayerLoc.x, EntityHead.y - LocalPlayerLoc.y) / 3.14159265358979323846 * 180);
			AngleY = -AngleY + 90.0f;

			silentAimViewAngles.x = AngleX;
			silentAimViewAngles.y = AngleY;
			silentAimViewAngles.z = 0.0f;
			closestDistance = 360.0f;
			closestIndex = -1;
		}
	}
}

#endif