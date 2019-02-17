// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef OFFSETS_H
#define OFFSETS_H

#include "Common.h"

namespace Offsets {
	DWORD m_fFlags = 0x104;
	DWORD m_flFallbackWear = 0x31C0;
	DWORD m_hMyWeapons = 0x2DF8;
	DWORD m_hMyWearables = 0x2EF4;
	DWORD m_hActiveWeapon = 0x2EF8;
	DWORD m_nFallbackPaintKit = 0x31B8;
	DWORD m_nFallbackSeed = 0x31BC;
	DWORD m_nFallbackStatTrak = 0x31C4;
	DWORD m_iHealth = 0x100;
	DWORD m_iTeamNum = 0xF4;
	DWORD m_iGlowIndex = 0xA3F8;
	DWORD m_iItemDefinitionIndex = 0x2FAA;
	DWORD m_iItemIDHigh = 0x2FC0;
	DWORD m_iCompetitiveRanking = 0x1A84;
	DWORD m_iCompetitiveWins = 0x1B88;
	DWORD dwClientState = 0x58BCFC;
	DWORD dwGlowObjectManager = 0x5219F40;
	DWORD dwPlayerResource = 0x30FD71C;
}

#endif