// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef UTILS_H
#define UTILS_H

#include "Common.h"
#include <iostream>
#include <map>

std::map<int, bool> bPreviousKey;

namespace Utils {
	template <class Fn>
	Fn* CaptureInterface(const char* szModule, const char* szInterface)
	{
		auto create_interface_fn = reinterpret_cast<Fn* (*)(const char *pName, int *pReturnCode)>(GetProcAddress(GetModuleHandleA(szModule), "CreateInterface"));
		Fn* result =  create_interface_fn(szInterface, nullptr);
		std::cout << szInterface << ": 0x" << std::hex << std::uppercase << (DWORD)result << "\n";
		return result;
	}

	template<typename Fn>
	Fn GetVFunc(const void *v, int i)
	{
		return (Fn) *(*(const void ***)v + i);
	}

	void CreateConsole(const char* consoleTitle) {
#ifdef DEBUG_DLL
		AllocConsole();
		SetConsoleTitle((LPCSTR)consoleTitle);
		// Requires _CRT_SECURE_NO_WARNINGS
		freopen("CONOUT$", "w", stdout);
		freopen("CONIN$", "r", stdin);
#endif
	}

	void CloseConsole() {
#ifdef DEBUG_DLL
		fclose(stdin);
		fclose(stdout);
		FreeConsole();
		SetConsoleCtrlHandler(NULL, true);
#endif
	}

	bool GetKey(int vKey) {
		bool bReturn = (bPreviousKey[vKey] && !GetAsyncKeyState(vKey));
		bPreviousKey[vKey] = GetAsyncKeyState(vKey);
		return bReturn;
	}

	bool GetKeyDown(int vKey) {
		bool bReturn = (!bPreviousKey[vKey] && GetAsyncKeyState(vKey));
		bPreviousKey[vKey] = GetAsyncKeyState(vKey);
		return bReturn;
	}
	typedef struct RgbColor
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
	} RgbColor;

	typedef struct HsvColor
	{
		unsigned char h;
		unsigned char s;
		unsigned char v;
	} HsvColor;

	RgbColor HSV2RGB(HsvColor hsv)
	{
		RgbColor rgb;
		unsigned char region, remainder, p, q, t;

		if (hsv.s == 0)
		{
			rgb.r = hsv.v;
			rgb.g = hsv.v;
			rgb.b = hsv.v;
			return rgb;
		}

		region = hsv.h / 43;
		remainder = (hsv.h - (region * 43)) * 6;

		p = (hsv.v * (255 - hsv.s)) >> 8;
		q = (hsv.v * (255 - ((hsv.s * remainder) >> 8))) >> 8;
		t = (hsv.v * (255 - ((hsv.s * (255 - remainder)) >> 8))) >> 8;

		switch (region)
		{
		case 0:
			rgb.r = hsv.v; rgb.g = t; rgb.b = p;
			break;
		case 1:
			rgb.r = q; rgb.g = hsv.v; rgb.b = p;
			break;
		case 2:
			rgb.r = p; rgb.g = hsv.v; rgb.b = t;
			break;
		case 3:
			rgb.r = p; rgb.g = q; rgb.b = hsv.v;
			break;
		case 4:
			rgb.r = t; rgb.g = p; rgb.b = hsv.v;
			break;
		default:
			rgb.r = hsv.v; rgb.g = p; rgb.b = q;
			break;
		}

		return rgb;
	}

	HsvColor RGB2HSV(RgbColor rgb)
	{
		HsvColor hsv;
		unsigned char rgbMin, rgbMax;

		rgbMin = rgb.r < rgb.g ? (rgb.r < rgb.b ? rgb.r : rgb.b) : (rgb.g < rgb.b ? rgb.g : rgb.b);
		rgbMax = rgb.r > rgb.g ? (rgb.r > rgb.b ? rgb.r : rgb.b) : (rgb.g > rgb.b ? rgb.g : rgb.b);

		hsv.v = rgbMax;
		if (hsv.v == 0)
		{
			hsv.h = 0;
			hsv.s = 0;
			return hsv;
		}

		hsv.s = 255 * long(rgbMax - rgbMin) / hsv.v;
		if (hsv.s == 0)
		{
			hsv.h = 0;
			return hsv;
		}

		if (rgbMax == rgb.r)
			hsv.h = 0 + 43 * (rgb.g - rgb.b) / (rgbMax - rgbMin);
		else if (rgbMax == rgb.g)
			hsv.h = 85 + 43 * (rgb.b - rgb.r) / (rgbMax - rgbMin);
		else
			hsv.h = 171 + 43 * (rgb.r - rgb.g) / (rgbMax - rgbMin);

		return hsv;
	}
}

#endif