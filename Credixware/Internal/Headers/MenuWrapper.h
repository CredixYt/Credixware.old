// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef MENUWRAPPER_H
#define MENUWRAPPER_H

#include "Interfaces.h"

int FONT_WEIGHT = 400;
int FONT_SIZE = 14;
int FONT_FLAGS = g_pSurface->FONTFLAG_OUTLINE;
const char* FONT_FAMILY_NAME = "Tahoma";

int MENU_X = 15;
int MENU_Y = 15;
int MENU_WIDTH = 500;
int MENU_HEIGHT = 325;
int MENU_TITLE_BAR_HEIGHT = 20;

int SCREEN_WIDTH = 0;
int SCREEN_HEIGHT = 0;

int color_primary[4] = { 26, 188, 156, 255 };
int color_light[4] = { 52, 73, 94, 255 };
int color_dark[4] = { 44, 62, 80, 255 };
int color_black[4] = { 0, 0, 0, 255 };
int color_white[4] = { 255, 255, 255, 255 };
int color_crosshair[4] = { 255, 0, 0, 255 };

HFont font;
HFont fontBig;
HFont fontSmall;

int wide = 0;
int tall = 0;

bool bDropdown = false;
bool bReload = false;

int cursor_x = 0;
int cursor_y = 0;
int prev_cursor_x = 0;
int prev_cursor_y = 0;

const wchar_t* GetWC(const char *c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

void DrawBox(int x, int y, int w, int h) {
	g_pSurface->DrawSetColor(color_dark[0], color_dark[1], color_dark[2], color_dark[3]);
	g_pSurface->DrawFilledRect(x, y, x + w, y + h);
}

void DrawBox(int x, int y, int w, int h, int color_input[]) {
	g_pSurface->DrawSetColor(color_input[0], color_input[1], color_input[2], color_input[3]);
	g_pSurface->DrawFilledRect(x, y, x + w, y + h);
}

void DrawOutlineBox(int x, int y, int w, int h) {
	g_pSurface->DrawSetColor(color_dark[0], color_dark[1], color_dark[2], color_dark[3]);
	g_pSurface->DrawOutlinedRect(x, y, x + w, y + h);
}

void DrawOutlineBox(int x, int y, int w, int h, int color_input[]) {
	g_pSurface->DrawSetColor(color_input[0], color_input[1], color_input[2], color_input[3]);
	g_pSurface->DrawOutlinedRect(x, y, x + w, y + h);
}

void DrawLine(int x, int y, int x2, int y2) {
	g_pSurface->DrawSetColor(color_dark[0], color_dark[1], color_dark[2], color_dark[3]);
	g_pSurface->DrawLine(x, y, x2, y2);
}

void DrawLine(int x, int y, int x2, int y2, int color_input[]) {
	g_pSurface->DrawSetColor(color_input[0], color_input[1], color_input[2], color_input[3]);
	g_pSurface->DrawLine(x, y, x2, y2);
}

void DrawString(int x, int y, const char* text) {
	const wchar_t* _text = GetWC(text);
	g_pSurface->DrawSetTextFont(font);
	g_pSurface->DrawSetTextColor(255, 255, 255, 255);
	g_pSurface->DrawSetTextPos(x, y);
	g_pSurface->DrawPrintText(_text, wcslen(_text));
}

void DrawString(int x, int y, const char* text, HFont input_font) {
	const wchar_t* _text = GetWC(text);
	g_pSurface->DrawSetTextFont(input_font);
	g_pSurface->DrawSetTextColor(255, 255, 255, 255);
	g_pSurface->DrawSetTextPos(x, y);
	g_pSurface->DrawPrintText(_text, wcslen(_text));
}

void DrawString(int x, int y, const char* text, int input_color[]) {
	const wchar_t* _text = GetWC(text);
	g_pSurface->DrawSetTextFont(font);
	g_pSurface->DrawSetTextColor(input_color[0], input_color[1], input_color[2], input_color[3]);
	g_pSurface->DrawSetTextPos(x, y);
	g_pSurface->DrawPrintText(_text, wcslen(_text));
}

void DrawString(int x, int y, const char* text, HFont input_font, int input_color[]) {
	const wchar_t* _text = GetWC(text);
	g_pSurface->DrawSetTextFont(input_font);
	g_pSurface->DrawSetTextColor(input_color[0], input_color[1], input_color[2], input_color[3]);
	g_pSurface->DrawSetTextPos(x, y);
	g_pSurface->DrawPrintText(_text, wcslen(_text));
}

void GetStringSize(int& w, int& h, const char* text) {
	const wchar_t* _text = GetWC(text);
	g_pSurface->GetTextSize(font, _text, w, h);
}

void GetStringSize(int& w, int& h, const char* text, HFont input_font) {
	const wchar_t* _text = GetWC(text);
	g_pSurface->GetTextSize(input_font, _text, w, h);
}

bool IsInBounds(int x, int y, int x2, int y2) {
	if (bDropdown) return false;
	if (cursor_x > x && cursor_x < x2 && cursor_y > y && cursor_y < y2) {
		return true;
	}
	return false;
}

bool bDragging = false;

void UpdateCursorPosition() {
	g_pEngineClient->GetScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	g_pSurface->SurfaceGetCursorPos(cursor_x, cursor_y);
	if (IsInBounds(MENU_X, MENU_Y, MENU_X + MENU_WIDTH, MENU_Y + MENU_TITLE_BAR_HEIGHT) && GetAsyncKeyState(VK_LBUTTON)) {
		bDragging = true;
	}
	if (!GetAsyncKeyState(VK_LBUTTON)) {
		bDragging = false;
	}
}

void ValueChanged() {
	bReload = true;
}

class GUIBox {
public:
	GUIBox(int X, int Y, int W, int H) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
		color[3] = 255;
	}
	GUIBox(int X, int Y, int W, int H, float R, float G, float B) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = R;
		color[1] = G;
		color[2] = B;
		color[3] = 255;
	}
	GUIBox(int X, int Y, int W, int H, int COLOR[4]) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = COLOR[0];
		color[1] = COLOR[1];
		color[2] = COLOR[2];
		color[3] = COLOR[3];
	}
	void Draw() {
		DrawBox(x, y, w, h, color);
	}
	void SetPos(int X, int Y) {
		x = X;
		y = Y;
	}
	void SetSize(int W, int H) {
		w = W;
		h = H;
	}
	void SetColor(int COLOR[4]) {
		color[0] = COLOR[0];
		color[1] = COLOR[1];
		color[2] = COLOR[2];
		color[3] = COLOR[3];
	}
	void GetPos(int& X, int& Y) {
		X = x;
		Y = y;
	}
	void GetSize(int& W, int& H) {
		W = w;
		H = h;
	}

	/* POSITION */
	int x;
	int y;
	/* SIZE */
	int w;
	int h;
	/* COLOR */
	int color[4];
};

class GUIButton {
public:
	GUIButton(int X, int Y, int W, int H, const char* TEXT) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
		color[3] = 255;
		text = TEXT;
	}
	GUIButton(int X, int Y, int W, int H, float R, float G, float B, const char* TEXT) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = R;
		color[1] = G;
		color[2] = B;
		color[3] = 255;
		text = TEXT;
	}
	GUIButton(int X, int Y, int W, int H, int COLOR[4], const char* TEXT) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = COLOR[0];
		color[1] = COLOR[1];
		color[2] = COLOR[2];
		color[3] = COLOR[3];
		text = TEXT;
	}
	void Draw() {
		if (IsInBounds(x, y, x + w, y + h)) {
			DrawBox(x, y, w, h, color);
			if (Utils::GetKey(VK_LBUTTON)) {
				bPressed = true;
				ValueChanged();
			}
			else {
				bPressed = false;
				ValueChanged();
			}
		}
		else {
			DrawBox(x, y, w, h, color_light);
		}
		int wide;
		int tall;
		GetStringSize(wide, tall, text);
		DrawString(x + (w/2) - (wide/2), y + (h/2) - (tall/2), text);
	}
	void SetPos(int X, int Y) {
		x = X;
		y = Y;
	}
	void SetSize(int W, int H) {
		w = W;
		h = H;
	}
	void SetColor(int COLOR[4]) {
		color[0] = COLOR[0];
		color[1] = COLOR[1];
		color[2] = COLOR[2];
		color[3] = COLOR[3];
	}
	void SetText(const char* TEXT) {
		text = TEXT;
	}
	void GetPos(int& X, int& Y) {
		X = x;
		Y = y;
	}
	void GetSize(int& W, int& H) {
		W = w;
		H = h;
	}
	const char* GetText() {
		return text;
	}
	bool GetValue() {
		return bPressed;
	}

	/* POSITION */
	int x;
	int y;
	/* SIZE */
	int w;
	int h;
	/* COLOR */
	int color[4];
	/* TEXT */
	const char* text;
	/* VALUE */
	bool bPressed;
};

class GUICheckbox {
public:
	GUICheckbox(int X, int Y, int W, int H, bool *bValue) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
		color[3] = 255;
		pValue = bValue;
	}
	GUICheckbox(int X, int Y, int W, int H, float R, float G, float B, bool *bValue) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = R;
		color[1] = G;
		color[2] = B;
		color[3] = 255;
		pValue = bValue;
	}
	GUICheckbox(int X, int Y, int W, int H, int COLOR[4], bool *bValue) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = COLOR[0];
		color[1] = COLOR[1];
		color[2] = COLOR[2];
		color[3] = COLOR[3];
		pValue = bValue;
	}
	void Draw() {
		if (IsInBounds(x, y, x + w, y + h) && Utils::GetKey(VK_LBUTTON)) {
			*pValue = !*pValue;
			ValueChanged();
		}
		DrawBox(x, y, w, h, color_light);
		if (*pValue) {
			DrawBox(x + 3, y + 3, w - 6, h - 6, color);
		}
	}
	void SetPos(int X, int Y) {
		x = X;
		y = Y;
	}
	void SetSize(int W, int H) {
		w = W;
		h = H;
	}
	void SetColor(int COLOR[4]) {
		color[0] = COLOR[0];
		color[1] = COLOR[1];
		color[2] = COLOR[2];
		color[3] = COLOR[3];
	}
	void SetValue(bool *bValue) {
		pValue = pValue;
	}
	void GetPos(int& X, int& Y) {
		X = x;
		Y = y;
	}
	void GetSize(int& W, int& H) {
		W = w;
		H = h;
	}
	bool GetValue() {
		return *pValue;
	}

	/* POSITION */
	int x;
	int y;
	/* SIZE */
	int w;
	int h;
	/* COLOR */
	int color[4];
	/* TEXT */
	/* VALUE */
	bool *pValue;
};

class GUITab {
public:
	GUITab(int X, int Y, int W, int H, int *iValue, const char* TEXT, int INDEX) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
		color[3] = 255;
		pValue = iValue;
		text = TEXT;
		index = INDEX;
	}
	GUITab(int X, int Y, int W, int H, float R, float G, float B, int *iValue, const char* TEXT, int INDEX) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = R;
		color[1] = G;
		color[2] = B;
		color[3] = 255;
		pValue = iValue;
		text = TEXT;
		index = INDEX;
	}
	GUITab(int X, int Y, int W, int H, int COLOR[4], int *iValue, const char* TEXT, int INDEX) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = COLOR[0];
		color[1] = COLOR[1];
		color[2] = COLOR[2];
		color[3] = COLOR[3];
		pValue = iValue;
		text = TEXT;
		index = INDEX;
	}
	void Draw() {
		if (index == *pValue) {
			DrawBox(x, y, w, h, color);
		}
		else {
			if (IsInBounds(x, y, x + w, y + h)) {
				DrawBox(x, y, w, h, color_dark);
				if (Utils::GetKey(VK_LBUTTON)) {
					*pValue = index;
					ValueChanged();
				}
			}
			else {
				DrawBox(x, y, w, h, color_light);
			}
		}
		int wide;
		int tall;
		GetStringSize(wide, tall, text);
		DrawString(x + (w/2) - (wide/2), y + (h/2) - (tall/2), text);
	}
	void SetPos(int X, int Y) {
		x = X;
		y = Y;
	}
	void SetSize(int W, int H) {
		w = W;
		h = H;
	}
	void SetColor(int COLOR[4]) {
		color[0] = COLOR[0];
		color[1] = COLOR[1];
		color[2] = COLOR[2];
		color[3] = COLOR[3];
	}
	void SetValue(int *bValue) {
		pValue = bValue;
	}
	void GetPos(int& X, int& Y) {
		X = x;
		Y = y;
	}
	void GetSize(int& W, int& H) {
		W = w;
		H = h;
	}
	int GetValue() {
		return *pValue;
	}

	/* POSITION */
	int x;
	int y;
	/* SIZE */
	int w;
	int h;
	/* COLOR */
	int color[4];
	/* TEXT */
	const char* text;
	/* VALUE */
	int *pValue;
	int index;
};

class GUISlider {
public:
	GUISlider(int X, int Y, int W, int H, float* fValue, int MIN, int MAX) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
		color[3] = 255;
		pValue = fValue;
		min = MIN;
		max = MAX;
	}
	GUISlider(int X, int Y, int W, int H, float R, float G, float B, float* fValue, int MIN, int MAX) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = R;
		color[1] = G;
		color[2] = B;
		color[3] = 255;
		pValue = fValue;
		min = MIN;
		max = MAX;
	}
	GUISlider(int X, int Y, int W, int H, int COLOR[4], float* fValue, int MIN, int MAX) {
		x = X;
		y = Y;
		w = W;
		h = H;
		color[0] = COLOR[0];
		color[1] = COLOR[1];
		color[2] = COLOR[2];
		color[3] = COLOR[3];
		pValue = fValue;
		min = MIN;
		max = MAX;
	}
	void Draw() {
		if (bHoldingDown) {
			int relative_x = cursor_x - x;
			float percent = (float)relative_x / (float)w;
			*pValue = ((max - min) * percent) + min;
			ValueChanged();
		}

		DrawBox(x, y, w, h, color_light);
		if (*pValue > max) {
			*pValue = max;
		}
		if (*pValue < min) {
			*pValue = min;
		}
		if (IsInBounds(x, y, x + w, y + h) && Utils::GetKeyDown(VK_LBUTTON)) {
			bHoldingDown = true;
		}
		if (!GetAsyncKeyState(VK_LBUTTON)) {
			bHoldingDown = false;
		}
		float percent = (*pValue - min) / (max - min);
		float width = w * percent;
		DrawBox(x, y, width, h, color_primary);
		int wide;
		int tall;
		char text[52] = { 0 };
		sprintf(text, "%.2f", *pValue);
		GetStringSize(wide, tall, text);
		if ((x + width - wide - 5) > x + 5) {
			DrawString(x + width - wide - 5, y + (h / 2) - (tall / 2), text);
		}
		else {
			DrawString(x + 5, y + (h / 2) - (tall / 2), text);
		}

	}
	void SetPos(int X, int Y) {
		x = X;
		y = Y;
	}
	void SetSize(int W, int H) {
		w = W;
		h = H;
	}
	void SetColor(int COLOR[4]) {
		color[0] = COLOR[0];
		color[1] = COLOR[1];
		color[2] = COLOR[2];
		color[3] = COLOR[3];
	}
	void SetValue(float* fValue) {
		pValue = fValue;
	}
	void GetPos(int& X, int& Y) {
		X = x;
		Y = y;
	}
	void GetSize(int& W, int& H) {
		W = w;
		H = h;
	}
	float GetValue() {
		return *pValue;
	}

	/* POSITION */
	int x;
	int y;
	/* SIZE */
	int w;
	int h;
	/* COLOR */
	int color[4];
	/* VALUE */
	float *pValue;
	int min;
	int max;
private:
	bool bHoldingDown = false;
};

GUIBox* backgroundBox;
GUIBox* titleBarBox;
GUIButton* exitButton;
GUITab* legitTab;
GUITab* rageTab;
GUITab* visualsTab;
GUITab* skinTab;
GUITab* miscTab;

/*	LEGIT	*/

/*	RAGE	*/

/*	VISUALS	*/
//	Chams
GUICheckbox* chamsCheckbox;
GUICheckbox* chamsOnlyEnemiesCheckbox;
GUICheckbox* chamsHandChamsCheckbox;
GUISlider* chamsEnemiesIgnoreZRSlider;
GUISlider* chamsEnemiesIgnoreZGSlider;
GUISlider* chamsEnemiesIgnoreZBSlider;
GUISlider* chamsEnemiesNormalRSlider;
GUISlider* chamsEnemiesNormalGSlider;
GUISlider* chamsEnemiesNormalBSlider;
GUISlider* chamsHandChamsRSlider;
GUISlider* chamsHandChamsGSlider;
GUISlider* chamsHandChamsBSlider;

/*	SKIN	*/

/*	MISC	*/

#endif