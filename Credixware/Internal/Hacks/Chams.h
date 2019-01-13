// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef CHAMS_H
#define CHAMS_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

namespace Chams {
	IMaterial* enemyBehindWall;
	IMaterial* enemyIgnoreZ;
	IMaterial* allyBehindWall;
	IMaterial* allyIgnoreZ;
	IMaterial* handChams;

	bool bFinished = false;

	void Init() {
		if (!g_pEngineClient->IsInGame() || !g_pEngineClient->IsConnected()) return;
		enemyBehindWall = CreateMaterial(false, false, "VertexLitGeneric");
		enemyBehindWall->ColorModulate(Settings::Visuals::enemyBehindWallR, Settings::Visuals::enemyBehindWallG, Settings::Visuals::enemyBehindWallB);
		enemyIgnoreZ = CreateMaterial(true, false, "VertexLitGeneric");
		enemyIgnoreZ->ColorModulate(Settings::Visuals::enemyIgnoreZR, Settings::Visuals::enemyIgnoreZG, Settings::Visuals::enemyIgnoreZB);
		allyBehindWall = CreateMaterial(false, false, "VertexLitGeneric");
		allyBehindWall->ColorModulate(Settings::Visuals::allyBehindWallR, Settings::Visuals::allyBehindWallG, Settings::Visuals::allyBehindWallB);
		allyIgnoreZ = CreateMaterial(true, false, "VertexLitGeneric");
		allyIgnoreZ->ColorModulate(Settings::Visuals::allyIgnoreZR, Settings::Visuals::allyIgnoreZG, Settings::Visuals::allyIgnoreZB);
		handChams = CreateMaterial(false, false, "VertexLitGeneric");
		handChams->ColorModulate(Settings::Visuals::handChamsR, Settings::Visuals::handChamsG, Settings::Visuals::handChamsB);
		bFinished = true;
	}
}

#endif