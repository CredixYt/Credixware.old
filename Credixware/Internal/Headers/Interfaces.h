// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef INTERFACES_H
#define INTERFACES_H

#include "Common.h"
#include "Utils.h"
#include "../SDK/SDK.h"

IPanel* g_pPanel;
ISurface* g_pSurface;
IClientEntityList* g_pClientEntityList;
IVEngineClient* g_pEngineClient;
void* g_pClient;
void* g_pClientMode;

namespace Interfaces {
	void Init() {
		g_pPanel = Utils::CaptureInterface<IPanel>("vgui2.dll", "VGUI_Panel009");
		g_pSurface = Utils::CaptureInterface<ISurface>("vguimatsurface.dll", "VGUI_Surface031");
		g_pClientEntityList = Utils::CaptureInterface<IClientEntityList>("client_panorama.dll", "VClientEntityList003");
		g_pEngineClient = Utils::CaptureInterface<IVEngineClient>("engine.dll", "VEngineClient014");
		g_pClient = Utils::CaptureInterface<void>("client_panorama.dll", "VClient018");
		g_pClientMode = **(DWORD***)((*(uintptr_t**)g_pClient)[10] + 0x5);
	}
}

#endif