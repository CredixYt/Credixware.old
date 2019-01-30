// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef CLANTAGCHANGER_H
#define CLANTAGCHANGER_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"

typedef void(__fastcall* SendClanTag_t) (const char*, const char*);
SendClanTag_t oSendClanTag;
uintptr_t oSendClanTagFunc;
bool bClantagChangerInit = false;

namespace ClantagChanger {
	int index;
	int index_num;
	int char_limit = 15;
	void Init() {
		oSendClanTagFunc = Utils::FindPattern((uintptr_t)GetModuleHandle("engine.dll"), 0xFFFFFFFFF, (unsigned char*)"\x53\x56\x57\x8B\xDA\x8B\xF9\xFF\x15\x00\x00\x00\x00\x6A\x24\x8B\xC8\x8B\x30" , "xxxxxxxxx????xxxxxx");
		if (!oSendClanTagFunc)
			return;

		oSendClanTag = reinterpret_cast<SendClanTag_t>(oSendClanTagFunc);
		index = 0;
		index_num = 0;
		bClantagChangerInit = true;
	}
	void Set(const char* str) {
		if (bClantagChangerInit && Settings::Misc::bClanTagChangerEnabled && g_pEngineClient->IsInGame())
		{
			if (index_num % 150 == 0) {
				int charCount = index + 1;
				std::string buffer = "";
				if (charCount > strlen(str)) {
					for (int i = 0; i < charCount - strlen(str); i++) {
						buffer.append("_");
					}
					if (!(index + strlen(str) > 20)) {
						buffer.append(str);
					} else if (index <= 20) {
						for (int i = 0; i < 20 - index; i++) {
							buffer.push_back(str[i]);
						}
					}
				}
				else if (charCount <= strlen(str)) {
					for (int i = strlen(str) - charCount; i < strlen(str); i++) {
						buffer.push_back(str[i]);
					}
				}
				if (buffer.size() < 11) {
					for (int i = buffer.size(); i < 11; i++) {
						buffer.append("_");
					}
				}
				oSendClanTag(buffer.c_str(), "");
				index++;
				if (index > 20) {
					index = 0;
				}
			}
			index_num++;
		}
	}
}

#endif