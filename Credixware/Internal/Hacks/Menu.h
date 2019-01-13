// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef MENU_H
#define MENU_H

#include "../Hacks/Chams.h"
#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"
#include "../Headers/MenuWrapper.h"

const char* WATERMARK_TEXT = "Credixware | January 2019";
const char* MENU_TITLE_TEXT = "Credixware";

namespace Menu {
	int iCurrentPage = 0;
	bool bOpen = false;
	void Init() {
		/* INIT FONT */
		font = g_pSurface->_CreateFont();
		g_pSurface->SetFontGlyphSet(font, FONT_FAMILY_NAME, FONT_SIZE, FONT_WEIGHT, 0, 0, FONT_FLAGS);
		fontSmall = g_pSurface->_CreateFont();
		g_pSurface->SetFontGlyphSet(fontSmall, FONT_FAMILY_NAME, FONT_SIZE - 4, FONT_WEIGHT, 0, 0, FONT_FLAGS);
		fontBig = g_pSurface->_CreateFont();
		g_pSurface->SetFontGlyphSet(fontBig, FONT_FAMILY_NAME, FONT_SIZE + 4, FONT_WEIGHT, 0, 0, FONT_FLAGS);

		/* INIT ELEMENTS */
		backgroundBox = new GUIBox(MENU_X, MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH, MENU_HEIGHT - MENU_TITLE_BAR_HEIGHT, color_dark);
		titleBarBox = new GUIBox(MENU_X, MENU_Y, MENU_WIDTH, MENU_TITLE_BAR_HEIGHT, color_primary);
		exitButton = new GUIButton(MENU_X + (MENU_WIDTH / 2) - 50, MENU_Y + MENU_HEIGHT - 50, 100, 25, color_primary, "Quit");
		legitTab = new GUITab(MENU_X + ((MENU_WIDTH / 5) * 0), MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH / 5, 50, color_primary, &iCurrentPage, "Legit", 0);
		rageTab = new GUITab(MENU_X + ((MENU_WIDTH / 5) * 1), MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH / 5, 50, color_primary, &iCurrentPage, "Rage", 1);
		visualsTab = new GUITab(MENU_X + ((MENU_WIDTH / 5) * 2), MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH / 5, 50, color_primary, &iCurrentPage, "Visuals", 2);
		skinTab = new GUITab(MENU_X + ((MENU_WIDTH / 5) * 3), MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH / 5, 50, color_primary, &iCurrentPage, "Skin", 3);
		miscTab = new GUITab(MENU_X + ((MENU_WIDTH / 5) * 4), MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH / 5, 50, color_primary, &iCurrentPage, "Misc", 4);

		/*	LEGIT	*/

		/*	RAGE	*/

		/*	VISUALS	*/
		//	Chams
		chamsCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bChams);
		chamsOnlyEnemiesCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bChamsOnlyEnemies);
		chamsHandChamsCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bChamsHandChams);
		chamsEnemiesIgnoreZRSlider = new GUISlider(0, 0, 100, 15, color_primary, &Settings::Visuals::enemyIgnoreZR, 0.0f, 1.0f);
		chamsEnemiesIgnoreZGSlider = new GUISlider(0, 0, 100, 15, color_primary, &Settings::Visuals::enemyIgnoreZG, 0.0f, 1.0f);
		chamsEnemiesIgnoreZBSlider = new GUISlider(0, 0, 100, 15, color_primary, &Settings::Visuals::enemyIgnoreZB, 0.0f, 1.0f);
		chamsEnemiesNormalRSlider = new GUISlider(0, 0, 100, 15, color_primary, &Settings::Visuals::enemyBehindWallR, 0.0f, 1.0f);
		chamsEnemiesNormalGSlider = new GUISlider(0, 0, 100, 15, color_primary, &Settings::Visuals::enemyBehindWallG, 0.0f, 1.0f);
		chamsEnemiesNormalBSlider = new GUISlider(0, 0, 100, 15, color_primary, &Settings::Visuals::enemyBehindWallB, 0.0f, 1.0f);
		chamsHandChamsRSlider = new GUISlider(0, 0, 100, 15, color_primary, &Settings::Visuals::handChamsR, 0.0f, 1.0f);
		chamsHandChamsGSlider = new GUISlider(0, 0, 100, 15, color_primary, &Settings::Visuals::handChamsG, 0.0f, 1.0f);
		chamsHandChamsBSlider = new GUISlider(0, 0, 100, 15, color_primary, &Settings::Visuals::handChamsB, 0.0f, 1.0f);

		/*	SKIN	*/

		/*	MISC	*/
	}
	void Draw() {
		UpdateCursorPosition();
		if (Utils::GetKey(VK_INSERT)) {
			bOpen = !bOpen;
		}
		if (bOpen) {
			if (bDragging) {
				int newX = cursor_x - prev_cursor_x;
				int newY = cursor_y - prev_cursor_y;
				MENU_X += newX;
				MENU_Y += newY;
			}
			DrawLine(SCREEN_WIDTH / 2 - 5, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2 + 5, SCREEN_HEIGHT / 2, color_crosshair);
			DrawLine(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 5, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 5, color_crosshair);

			backgroundBox->SetPos(MENU_X, MENU_Y + MENU_TITLE_BAR_HEIGHT);
			titleBarBox->SetPos(MENU_X, MENU_Y);

			legitTab->SetPos(MENU_X + ((MENU_WIDTH / 5) * 0), MENU_Y + MENU_TITLE_BAR_HEIGHT);
			rageTab->SetPos(MENU_X + ((MENU_WIDTH / 5) * 1), MENU_Y + MENU_TITLE_BAR_HEIGHT);
			visualsTab->SetPos(MENU_X + ((MENU_WIDTH / 5) * 2), MENU_Y + MENU_TITLE_BAR_HEIGHT);
			skinTab->SetPos(MENU_X + ((MENU_WIDTH / 5) * 3), MENU_Y + MENU_TITLE_BAR_HEIGHT);
			miscTab->SetPos(MENU_X + ((MENU_WIDTH / 5) * 4), MENU_Y + MENU_TITLE_BAR_HEIGHT);

			backgroundBox->Draw();
			titleBarBox->Draw();
			
			legitTab->Draw();
			rageTab->Draw();
			visualsTab->Draw();
			skinTab->Draw();
			miscTab->Draw();

			if (iCurrentPage == legitTab->index) {

			}
			else if (iCurrentPage == rageTab->index) {

			}
			else if (iCurrentPage == visualsTab->index) {
				/*	VISUALS	*/
				//	Chams
				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 5, "Chams", fontBig, color_white);
				int wide;
				int tall;
				GetStringSize(wide, tall, "Chams", fontBig);
				chamsCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 5 + (tall/2) - (15/2));
				chamsCheckbox->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 1), "Only Enemies");
				chamsOnlyEnemiesCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 1));
				chamsOnlyEnemiesCheckbox->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 2), "Enemies IgnoreZ Red");
				chamsEnemiesIgnoreZRSlider->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 2));
				chamsEnemiesIgnoreZRSlider->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 3), "Enemies IgnoreZ Green");
				chamsEnemiesIgnoreZGSlider->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 3));
				chamsEnemiesIgnoreZGSlider->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 4), "Enemies IgnoreZ Blue");
				chamsEnemiesIgnoreZBSlider->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 4));
				chamsEnemiesIgnoreZBSlider->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 5), "Enemies Normal Red");
				chamsEnemiesNormalRSlider->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 5));
				chamsEnemiesNormalRSlider->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 6), "Enemies Normal Green");
				chamsEnemiesNormalGSlider->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 6));
				chamsEnemiesNormalGSlider->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 7), "Enemies Normal Blue");
				chamsEnemiesNormalBSlider->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 7));
				chamsEnemiesNormalBSlider->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 8), "Hand Chams");
				chamsHandChamsCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 8));
				chamsHandChamsCheckbox->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 9), "Hand Red");
				chamsHandChamsRSlider->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 9));
				chamsHandChamsRSlider->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 10), "Hand Green");
				chamsHandChamsGSlider->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 10));
				chamsHandChamsGSlider->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 11), "Hand Blue");
				chamsHandChamsBSlider->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 11));
				chamsHandChamsBSlider->Draw();
			}
			else if (iCurrentPage == skinTab->index) {

			}
			else if (iCurrentPage == miscTab->index) {
				exitButton->SetPos(MENU_X + (MENU_WIDTH / 2) - 50, MENU_Y + MENU_HEIGHT - 50);
				exitButton->Draw();
			}

			GetStringSize(wide, tall, MENU_TITLE_TEXT);
			DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT / 2 - tall / 2, MENU_TITLE_TEXT);
		}
		DrawString(5, 5, WATERMARK_TEXT);

		prev_cursor_x = cursor_x;
		prev_cursor_y = cursor_y;

		if (bReload) {
			bReload = false;
			Chams::Init();
		}
	}
};

#endif