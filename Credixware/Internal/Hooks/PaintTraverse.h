// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef PAINTTRAVERSE_H
#define PAINTTRAVERSE_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"

typedef void(__thiscall* PaintTraverse_t)(void*, VPANEL, bool, bool);
PaintTraverse_t oPaintTraverse;
unsigned int* oPaintTraverseFunc;

void __fastcall hkPaintTraverse(void* ecx, void* edx, VPANEL vguiPanel, bool bForceRepaint, bool bAllowForce) {
	const char* panelName = g_pPanel->GetName(vguiPanel);
	if (!strcmp(panelName, "MatSystemTopPanel")) {
		ESP::Draw();
		Events::Draw();
		Menu::Draw();
	}
	oPaintTraverse(ecx, vguiPanel, bForceRepaint, bAllowForce);
}

#endif