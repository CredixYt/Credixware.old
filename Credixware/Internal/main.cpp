// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#include "Hacks/Hacks.h"
#include "Headers/Common.h"
#include "Headers/Interfaces.h"
#include "Headers/Hooks.h"

HMODULE MyModule;

int main() {
	Interfaces::Init();
	Hooks::Init();
	Hacks::Init();
	while (true) {
		if (GetAsyncKeyState(VK_DELETE)) {
			Hooks::Reset();
			Utils::CloseConsole();
			FreeLibraryAndExitThread(MyModule, 0);
			return 0;
		}
		/*if (g_pEngineClient->IsInGame()) {
			g_pEngineClient->ClientCmd_Unrestricted("say TESTING UNTRUSTED by using thirdperson. If you are seeing this message VAC/VACnet probably hasn't banned me. It's sad :\\");
			Sleep(250);
			g_pEngineClient->ClientCmd_Unrestricted("say Anyways, there's not much we can do. Have fun playing with cheaters for approximately the next 2 years ;) -CredixYt");
			Sleep(5000);
		}*/
	}
	return 0;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
	if (dwReason == DLL_PROCESS_ATTACH) {
		MyModule = hModule;
		DisableThreadLibraryCalls(hModule);
		Utils::CreateConsole();
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, 0, 0, 0);
	}
	return TRUE;
}