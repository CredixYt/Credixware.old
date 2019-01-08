// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/
#ifndef FRAMESTAGENOTIFY_H
#define FRAMESTAGENOTIFY_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Hacks.h"

typedef void(__thiscall* FrameStageNotify_t)(void*, ClientFrameStage_t curStage);
FrameStageNotify_t oFrameStageNotify;
unsigned int* oFrameStageNotifyFunc;

void __fastcall hkFrameStageNotify(void* ecx, void* edx, ClientFrameStage_t curStage) {
	oFrameStageNotify(ecx, curStage);
}

#endif