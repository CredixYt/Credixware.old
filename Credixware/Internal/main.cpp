// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#include "Hacks/Hacks.h"
#include "Headers/Common.h"
#include "Headers/Interfaces.h"
#include "Headers/Hooks.h"

int main() {
	Utils::CreateConsole("Credixware-Debug");
	Interfaces::Init();
	Hooks::Init();
	Hacks::Init();
	while (true) {
		if(exitButton->GetValue()) {
			Hooks::Reset();
			Hacks::Reset();
			Utils::CloseConsole();
			FreeLibraryAndExitThread(MyModule, 0);
		}
	}
	return 0;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
	if (dwReason == DLL_PROCESS_ATTACH) {
		MyModule = hModule;
		DisableThreadLibraryCalls(hModule);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, 0, 0, 0);
	}
	return TRUE;
}

/*
if (true)
    {
        if (!I::EntList->GetClientEntityFromHandle(hWearables[0]))
        {
            static ClientClass* pClass;
 
            if (!pClass)
                pClass = I::BaseClient->GetAllClasses();
                while (pClass)
                {
                    if (pClass->m_ClassID == CEconWearable)
                        break;
                    pClass = pClass->m_pNext;
                }
 
            int iEntry, iSerial;
 
            pClass->m_pCreateFn(iEntry = (I::EntList->GetHighestEntityIndex() + 1), iSerial = (RandomInt(0x0, 0xFFF)));
            hWearables[0] = iEntry | (iSerial << 16);
 
            IClientEntity* pEnt = I::EntList->GetClientEntityFromHandle(hWearables[0]);
 
            if (pEnt)
            {
                *MakePtr(int, pEnt, gOffset.m_iItemDefinitionIndex) = 5033;
                *MakePtr(int, pEnt, gOffset.m_iItemIDHigh) = -1;
                *MakePtr(int, pEnt, gOffset.m_iEntityQuality) = 4;
                *MakePtr(int, pEnt, gOffset.m_iAccountID) = info.xuidlow;
                *MakePtr(float, pEnt, gOffset.m_flFallbackWear) = 0.00000001f;
                *MakePtr(int, pEnt, gOffset.m_nFallbackSeed) = 0;
                *MakePtr(int, pEnt, gOffset.m_nFallbackStatTrak) = -1;
                *MakePtr(int, pEnt, gOffset.m_nFallbackPaintKit) = 10026;
                pEnt->SetModelIndex(I::ModelInfo->GetModelIndex("models/weapons/v_models/arms/glove_motorcycle/v_glove_motorcycle.mdl"));
                pEnt->GetClientNetworkable()->PreDataUpdate(DATA_UPDATE_CREATED);
            }
        }
        
    }
	*/