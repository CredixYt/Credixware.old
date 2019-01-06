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