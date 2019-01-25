// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef FIREEVENT_H
#define FIREEVENT_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"

typedef bool(__thiscall* FireEvent_t)(void*, IGameEvent*, bool);
FireEvent_t oFireEvent;
unsigned int* oFireEventFunc;

bool __fastcall hkFireEvent(void* ecx, void* edx, IGameEvent* pEvent, bool bDontBroadcast) {
	return oFireEvent(ecx, pEvent, bDontBroadcast);
}

#endif