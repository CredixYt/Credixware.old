// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef GRENADEHELPER_H
#define GRENADEHELPER_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

enum ThrowType_t {
	NONE = 0,
	THROW = 1,
	LOB = 2,
	DROP = 3
};

ThrowType_t ThrowType = ThrowType_t::NONE;

namespace GrenadeHelper {
	void Tick(CUserCmd* pCmd) {
		/*if (!Settings::Visuals::bGrenadeTrajectoryEnabled) return;
		bool bAttack = pCmd->buttons & IN_ATTACK;
		bool bAttack2 = pCmd->buttons & IN_ATTACK2;
		if (bAttack && !bAttack2) {
			ThrowType = ThrowType_t::THROW;
		} else if (bAttack && bAttack2) {
			ThrowType = ThrowType_t::LOB;
		} else if (!bAttack && bAttack2) {
			ThrowType = ThrowType_t::DROP;
		} else {
			ThrowType = ThrowType_t::NONE;
		}*/
	}
	void View() {
		/*IClientEntity* LocalPlayer = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
		DWORD* MyWeapon = (DWORD*)(LocalPlayer + Offsets::m_hActiveWeapon);
		int WeaponID = *(int*)(MyWeapon + Offsets::m_iItemIDHigh);
		printf("%i: %i\n", MyWeapon, WeaponID);*/
	}
}

#endif