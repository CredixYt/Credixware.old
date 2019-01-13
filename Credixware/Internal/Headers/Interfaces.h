// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef INTERFACES_H
#define INTERFACES_H

#include "Common.h"
#include "Utils.h"
#include "../SDK/SDK.h"

HMODULE MyModule;

IPanel* g_pPanel;
ISurface* g_pSurface;
IClientEntityList* g_pClientEntityList;
IVEngineClient* g_pEngineClient;
CInput* g_pInput;
IVModelRender* g_pModelRender;
IVModelInfo* g_pModelInfo;
IMaterialSystem* g_pMaterialSystem;
void* g_pClient;
void* g_pClientMode;

namespace Interfaces {
	void Init() {
		g_pPanel = Utils::CaptureInterface<IPanel>("vgui2.dll", "VGUI_Panel009");
		g_pSurface = Utils::CaptureInterface<ISurface>("vguimatsurface.dll", "VGUI_Surface031");
		g_pClientEntityList = Utils::CaptureInterface<IClientEntityList>("client_panorama.dll", "VClientEntityList003");
		g_pEngineClient = Utils::CaptureInterface<IVEngineClient>("engine.dll", "VEngineClient014");
		g_pModelRender = Utils::CaptureInterface<IVModelRender>("engine.dll", "VEngineModel016");
		g_pModelInfo = Utils::CaptureInterface<IVModelInfo>("engine.dll", "VModelInfoClient004");
		g_pMaterialSystem = Utils::CaptureInterface<IMaterialSystem>("materialsystem.dll", "VMaterialSystem080");
		g_pClient = Utils::CaptureInterface<void>("client_panorama.dll", "VClient018");
		g_pClientMode = **(DWORD***)((*(uintptr_t**)g_pClient)[10] + 0x5);
#ifndef NO_CINPUT_HOOK
		g_pInput = *(CInput**)((*(uintptr_t**)g_pClient)[16] + 0x1);
#else
		g_pInput = nullptr;
#endif
	}
}

Vector2D WorldToScreen(Vector point3D) {
	VMatrix viewMatrix = g_pEngineClient->WorldToViewMatrix();
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
IMaterial* CreateMaterial(bool bIgnorez, bool bFlat, const char* pType) {
	char matName[128] = { 0 };
	sprintf(matName, "credixware_custom_%i", matCount);
	matCount++;
	const char* materialName = matName;
	char fileName[128] = { 0 };
	sprintf(fileName, "csgo\\materials\\%s.vmt", materialName);
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
	if (bFlat)														//
		contentStream << "\"$flat\"         \"1\"\n";				//	"$flat"				"1"
	else															//	^ OR ¢
		contentStream << "\"$flat\"         \"0\"\n";				//	"$flat"				"0"
	contentStream << "}\n";											// }
	std::ofstream(fileName) << contentStream.str();
	IMaterial* createdMaterial = g_pMaterialSystem->FindMaterial(materialName, "Model textures");
	if (createdMaterial) {
		return createdMaterial;
	}
	return nullptr;
}

#endif