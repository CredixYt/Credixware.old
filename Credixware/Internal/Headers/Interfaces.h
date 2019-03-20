// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef INTERFACES_H
#define INTERFACES_H

#include "Common.h"
#include "Utils.h"
#include "../SDK/SDK.h"
#include "Offsets.h"
#include <vector>
#include <sstream>

HMODULE MyModule;

CGlobalVars*		g_pGlobalVars;
CGlowObjectManager*	g_pGlowObjectManager;
CInput*				g_pInput;
IClientEntityList*	g_pClientEntityList;
ICvar*				g_pCvar;
IEngineTrace*		g_pEngineTrace;
IMaterialSystem*	g_pMaterialSystem;
IPanel*				g_pPanel;
ISurface*			g_pSurface;
IVEngineClient*		g_pEngineClient;
IVModelInfo*		g_pModelInfo;
IVModelRender*		g_pModelRender;
void*				g_pClient;
void*				g_pClientMode;
void*				g_pClientState;
void*				g_pGameEventManager;

namespace Interfaces {
	void Init() {
		g_pClientEntityList		= Utils::CaptureInterface<IClientEntityList>("client_panorama.dll", "VClientEntityList003");
		g_pCvar					= Utils::CaptureInterface<ICvar>("vstdlib.dll", "VEngineCvar007");
		g_pEngineTrace			= Utils::CaptureInterface<IEngineTrace>("engine.dll", "EngineTraceClient004");
		g_pMaterialSystem		= Utils::CaptureInterface<IMaterialSystem>("materialsystem.dll", "VMaterialSystem080");
		g_pPanel				= Utils::CaptureInterface<IPanel>("vgui2.dll", "VGUI_Panel009");
		g_pSurface				= Utils::CaptureInterface<ISurface>("vguimatsurface.dll", "VGUI_Surface031");
		g_pEngineClient			= Utils::CaptureInterface<IVEngineClient>("engine.dll", "VEngineClient014");
		g_pModelInfo			= Utils::CaptureInterface<IVModelInfo>("engine.dll", "VModelInfoClient004");
		g_pModelRender			= Utils::CaptureInterface<IVModelRender>("engine.dll", "VEngineModel016");
		g_pGameEventManager		= Utils::CaptureInterface<void>("engine.dll", "GAMEEVENTSMANAGER002");
		g_pClient				= Utils::CaptureInterface<void>("client_panorama.dll", "VClient018");
		g_pClientMode			= **(DWORD***)((*(uintptr_t**)g_pClient)[10] + 0x5);
		g_pClientState			= (void*)((DWORD)GetModuleHandle("engine.dll") + Offsets::dwClientState);
		printf("g_pClientState: %i\n", g_pClientState);
		g_pGlobalVars			= **reinterpret_cast<CGlobalVars***>((*reinterpret_cast<uintptr_t**>(g_pClient))[0] + 0x1B);
		g_pInput				= *(CInput**)((*(uintptr_t**)g_pClient)[16] + 0x1);
		g_pGlowObjectManager	= (CGlowObjectManager*)((DWORD)GetModuleHandle("client_panorama.dll") + Offsets::dwGlowObjectManager);
	}
}

Vector2D WorldToScreen(Vector point3D) {
	VMatrix viewMatrix = g_pEngineClient->WorldToScreenMatrix();
	int width, height;
	g_pEngineClient->GetScreenSize(width, height);
	float returnx = 1.0f;
	float returny = 1.0f;
	float w = viewMatrix[3][0] * point3D.x + viewMatrix[3][1] * point3D.y + viewMatrix[3][2] * point3D.z + viewMatrix[3][3];
	if (w >= 0.01f)
	{
		float inverseX = 1.0f / w;
		returnx =
			(width / 2.0f) +
			(0.5f * (
			(viewMatrix[0][0] * point3D.x + viewMatrix[0][1] * point3D.y + viewMatrix[0][2] * point3D.z + viewMatrix[0][3])
				* inverseX)
				* width + 0.5f);
		returny =
			(height / 2.0f) -
			(0.5f * (
			(viewMatrix[1][0] * point3D.x + viewMatrix[1][1] * point3D.y + viewMatrix[1][2] * point3D.z + viewMatrix[1][3])
				* inverseX)
				* height + 0.5f);
	}
	return Vector2D(returnx, returny);

}

int matCount = 0;
std::vector<const char*> createdMaterials;
IMaterial* CreateMaterial(bool bIgnorez, bool bFlat, bool bMetalic, const char* pType) {
	char matName[128] = { 0 };
	sprintf(matName, "credixware_custom_%i", matCount);
	matCount++;
	const char* materialName = matName;
	char fileName[128] = { 0 };
	sprintf(fileName, "csgo\\materials\\%s.vmt", materialName);
	std::stringstream contentStream;
	contentStream << "\"" << pType << "\"\n";
	contentStream << "{\n";
	contentStream << "\"$basetexture\" \"vgui/white_additive\"\n";
	if (bIgnorez)
		contentStream << "\"$ignorez\"      \"1\"\n";
	else
		contentStream << "\"$ignorez\"      \"0\"\n";
	if (bMetalic) {
		contentStream << "\"$envmap\"       \"env_cubemap\"\n";
		contentStream << "\"$normalmapalphaenvmapmask\"       \"1\"\n";
		contentStream << "\"$envmapcontrast\"       \"1\"\n";
	}
	else {
		contentStream << "\"$envmap\"       \"\"\n";
	}
	contentStream << "\"$nofog\"        \"1\"\n";
	contentStream << "\"$model\"        \"1\"\n";
	contentStream << "\"$nocull\"       \"0\"\n";
	contentStream << "\"$selfillum\"    \"1\"\n";
	contentStream << "\"$halflambert\"  \"1\"\n";
	contentStream << "\"$znearer\"      \"0\"\n";
	if (bFlat)
		contentStream << "\"$flat\"         \"1\"\n";
	else
		contentStream << "\"$flat\"         \"0\"\n";
	contentStream << "}\n";
	std::ofstream(fileName) << contentStream.str();
	IMaterial* createdMaterial = g_pMaterialSystem->FindMaterial(materialName, "Model textures");
	if (createdMaterial) {
		return createdMaterial;
	}
	return nullptr;
}

IMaterial* CreateCustomMaterial(const char* szFileName, bool bIgnorez, bool bFlat, bool bMetalic, const char* pType) {
	char fileName[255] = { 0 };
	sprintf(fileName, "csgo\\materials\\%s.vmt", szFileName);
	remove(fileName);
	std::stringstream contentStream;
	contentStream << "\"" << pType << "\"\n";						// "VertexLitGeneric" or "UnlitGeneric"
	contentStream << "{\n";											// {
	contentStream << "\"$basetexture\" \"vgui/white_additive\"\n";	//	"$basetexture"      "vgui/white_additive"
	if (bIgnorez)													//
		contentStream << "\"$ignorez\"      \"1\"\n";				//	"$ignorez"			"1"		
	else															//	 ^ OR ¢
		contentStream << "\"$ignorez\"      \"0\"\n";				//	"$ignorez"			"0"
	contentStream << "\"$envmap\"       \"\"\n";					//	"$envmap"			""		
	contentStream << "\"$nofog\"        \"1\"\n";					//	"$nofog"			"1"	
	contentStream << "\"$model\"        \"1\"\n";					//	"$model"			"1"
	contentStream << "\"$nocull\"       \"0\"\n";					//	"$nocull"			"0"
	contentStream << "\"$selfillum\"    \"1\"\n";					//	"$selfillum"		"1"
	contentStream << "\"$halflambert\"  \"1\"\n";					//	"$halflambert"		"1"
	contentStream << "\"$znearer\"      \"0\"\n";					//	"$znearer"			"0"
	if (bFlat) {													//
		contentStream << "\"$flat\"         \"1\"\n";				//	"$flat"				"1"
	}																//
	else {															//	^ OR ¢
		contentStream << "\"$flat\"         \"0\"\n";				//	"$flat"				"0"
	}																//
	if (bMetalic == true) {											//
		contentStream << "\"$surfaceprop\"  \"metal\"\n";			//	"$surfaceprop"		"metal"
	}																//
	contentStream << "}\n";											// }
	std::ofstream(fileName) << contentStream.str();
	createdMaterials.push_back(fileName);
	IMaterial* createdMaterial = g_pMaterialSystem->FindMaterial(szFileName, "Model textures");
	if (createdMaterial) {
		return createdMaterial;
	}
	return nullptr;
}

void DeleteMaterials() {
	for (int i = 0; i <= matCount; i++) {
		char matName[128] = { 0 };
		sprintf(matName, "credixware_custom_%i", i);
		const char* materialName = matName;
		char fileName[128] = { 0 };
		sprintf(fileName, "csgo\\materials\\%s.vmt", materialName);
		remove(fileName);
	}
	for (int i = 0; i < createdMaterials.size(); i++) {
		remove(createdMaterials.at(i));
	}
}

#endif