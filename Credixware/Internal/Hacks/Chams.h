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
		enemyBehindWall->ColorModulate(Settings::Visuals::enemyBehindWallR / 255.0f, Settings::Visuals::enemyBehindWallG / 255.0f, Settings::Visuals::enemyBehindWallB / 255.0f);
		enemyIgnoreZ = CreateMaterial(true, false, "VertexLitGeneric");
		enemyIgnoreZ->ColorModulate(Settings::Visuals::enemyIgnoreZR / 255.0f, Settings::Visuals::enemyIgnoreZG / 255.0f, Settings::Visuals::enemyIgnoreZB / 255.0f);
		allyBehindWall = CreateMaterial(false, false, "VertexLitGeneric");
		allyBehindWall->ColorModulate(Settings::Visuals::allyBehindWallR / 255.0f, Settings::Visuals::allyBehindWallG / 255.0f, Settings::Visuals::allyBehindWallB / 255.0f);
		allyIgnoreZ = CreateMaterial(true, false, "VertexLitGeneric");
		allyIgnoreZ->ColorModulate(Settings::Visuals::allyIgnoreZR / 255.0f, Settings::Visuals::allyIgnoreZG / 255.0f, Settings::Visuals::allyIgnoreZB / 255.0f);
		handChams = CreateMaterial(false, false, "VertexLitGeneric");
		handChams->ColorModulate(Settings::Visuals::handChamsR/255.0f, Settings::Visuals::handChamsG / 255.0f, Settings::Visuals::handChamsB / 255.0f);
		bFinished = true;
	}
}

#endif