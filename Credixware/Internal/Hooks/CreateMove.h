// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ û
#ifndef CREATEMOVE_H
#define CREATEMOVE_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"

typedef void(__thiscall* CreateMove_t)(void*, float, CUserCmd*);
CreateMove_t oCreateMove;
unsigned int* oCreateMoveFunc;

bool __fastcall hkCreateMove(void* ecx, void* edx, float sampleTime, CUserCmd* UserCmd) {
	ViewangleX = UserCmd->viewangles.x;
	ViewangleY = UserCmd->viewangles.y;
	ViewangleZ = UserCmd->viewangles.z;
	oCreateMove(ecx, sampleTime, UserCmd);
	return true;
}

#endif