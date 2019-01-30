// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef MENU_H
#define MENU_H

#include "../Hacks/Chams.h"
#include "../Hacks/Nightmode.h"
#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"
#include "../Headers/MenuWrapper.h"

const char* WATERMARK_TEXT = "Credixware | Beta v0.4";
const char* MENU_TITLE_TEXT = "Credixware";

namespace Menu {
	int iCurrentPage = 0;
	bool bNightmodeBefore = Settings::Misc::bNightmodeEnabled;
	bool bOpen = false;
	void CreateConfig(int id) {
		_wmkdir(L"csgo\\cfg\\Credixware");
		if (id == 0) {
			std::ofstream myfile;
			myfile.open("csgo\\cfg\\Credixware\\Default.cfg");
			myfile << "// Credixware Config - By CredixYt\n";
			myfile << "// DEFAULT CONFIG\n";
			myfile.close();
		} else if (id == 1) {
			std::ofstream myfile;
			myfile.open("csgo\\cfg\\Credixware\\Legit.cfg");
			myfile << "// Credixware Config - By CredixYt\n";
			myfile << "// LEGIT CONFIG\n";
			myfile.close();
		} else if (id == 2) {
			std::ofstream myfile;
			myfile.open("csgo\\cfg\\Credixware\\HvH.cfg");
			myfile << "// Credixware Config - By CredixYt\n";
			myfile << "// HVH CONFIG\n";
			myfile.close();
		} else if (id == 3) {
			std::ofstream myfile;
			myfile.open("csgo\\cfg\\Credixware\\Custom_1.cfg");
			myfile << "// Credixware Config - By CredixYt\n";
			myfile << "// CUSTOM CONFIG 1\n";
			myfile.close();
		} else if (id == 4) {
			std::ofstream myfile;
			myfile.open("csgo\\cfg\\Credixware\\Custom_2.cfg");
			myfile << "// Credixware Config - By CredixYt\n";
			myfile << "// CUSTOM CONFIG 2\n";
			myfile.close();
		}
	}
	void CreateConfig() {
		std::stringstream contentStream;
		std::ifstream DefaultConfig("csgo\\cfg\\Credixware\\Default.cfg");
		std::ifstream LegitConfig("csgo\\cfg\\Credixware\\Legit.cfg");
		std::ifstream HvHConfig("csgo\\cfg\\Credixware\\HvH.cfg");
		std::ifstream CustomConfig("csgo\\cfg\\Credixware\\Custom_1.cfg");
		std::ifstream CustomConfig2("csgo\\cfg\\Credixware\\Custom_2.cfg");
		if (!DefaultConfig.good()) {
			CreateConfig(0);
		}
		if (!LegitConfig.good()) {
			CreateConfig(1);
		}
		if (!HvHConfig.good()) {
			CreateConfig(2);
		}
		if (!CustomConfig.good()) {
			CreateConfig(3);
		}
		if (!CustomConfig2.good()) {
			CreateConfig(4);
		}
	}
	void LoadConfig(int id) {
		if (id == 0) {

		}
	}
	void Init() {
		/* INIT FONT */
		font = g_pSurface->_CreateFont();
		g_pSurface->SetFontGlyphSet(font, FONT_FAMILY_NAME, FONT_SIZE, FONT_WEIGHT, 0, 0, FONT_FLAGS);
		fontSmall = g_pSurface->_CreateFont();
		g_pSurface->SetFontGlyphSet(fontSmall, FONT_FAMILY_NAME, FONT_SIZE - 2, FONT_WEIGHT, 0, 0, FONT_FLAGS);
		fontBig = g_pSurface->_CreateFont();
		g_pSurface->SetFontGlyphSet(fontBig, FONT_FAMILY_NAME, FONT_SIZE + 4, FONT_WEIGHT, 0, 0, FONT_FLAGS);

		/* INIT ELEMENTS */
		backgroundBox = new GUIBox(MENU_X, MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH, MENU_HEIGHT - MENU_TITLE_BAR_HEIGHT, color_dark);
		titleBarBox = new GUIBox(MENU_X, MENU_Y, MENU_WIDTH, MENU_TITLE_BAR_HEIGHT, color_primary);
		legitTab = new GUITab(MENU_X + ((MENU_WIDTH / 5) * 0), MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH / 5, 50, color_primary, &iCurrentPage, "Legit", 0);
		rageTab = new GUITab(MENU_X + ((MENU_WIDTH / 5) * 1), MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH / 5, 50, color_primary, &iCurrentPage, "Rage", 1);
		visualsTab = new GUITab(MENU_X + ((MENU_WIDTH / 5) * 2), MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH / 5, 50, color_primary, &iCurrentPage, "Visuals", 2);
		skinTab = new GUITab(MENU_X + ((MENU_WIDTH / 5) * 3), MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH / 5, 50, color_primary, &iCurrentPage, "Skin", 3);
		miscTab = new GUITab(MENU_X + ((MENU_WIDTH / 5) * 4), MENU_Y + MENU_TITLE_BAR_HEIGHT, MENU_WIDTH / 5, 50, color_primary, &iCurrentPage, "Misc", 4);

		/*	LEGIT	*/

		/*	RAGE	*/
		// SilentAim
		silentAimCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Rage::bSilentAim);

		/*	VISUALS	*/
		//	Chams
		chamsCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bChamsEnabled);
		chamsMaterialDropdown = new GUIDropdown(0, 0, 100, 15, color_primary, &Settings::Visuals::chamsMaterial);
		chamsEnemiesNormalCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bChamsEnemiesNormal);
		chamsEnemiesNormalColor = new GUIColor(0, 0, 100, 15, color_primary, &Settings::Visuals::chamsEnemiesNormalR, &Settings::Visuals::chamsEnemiesNormalG, &Settings::Visuals::chamsEnemiesNormalB);
		chamsEnemiesIgnoreZCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bChamsEnemiesIgnoreZ);
		chamsEnemiesIgnoreZColor = new GUIColor(0, 0, 100, 15, color_primary, &Settings::Visuals::chamsEnemiesIgnoreZR, &Settings::Visuals::chamsEnemiesIgnoreZG, &Settings::Visuals::chamsEnemiesIgnoreZB);
		chamsAlliesNormalCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bChamsAlliesNormal);
		chamsAlliesNormalColor = new GUIColor(0, 0, 100, 15, color_primary, &Settings::Visuals::chamsAlliesNormalR, &Settings::Visuals::chamsAlliesNormalG, &Settings::Visuals::chamsAlliesNormalB);
		chamsAlliesIgnoreZCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bChamsAlliesIgnoreZ);
		chamsAlliesIgnoreZColor = new GUIColor(0, 0, 100, 15, color_primary, &Settings::Visuals::chamsAlliesIgnoreZR, &Settings::Visuals::chamsAlliesIgnoreZG, &Settings::Visuals::chamsAlliesIgnoreZB);
		chamsHandChamsCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bChamsHandChamsEnabled);
		chamsHandChamsColor = new GUIColor(0, 0, 100, 15, color_primary, &Settings::Visuals::chamsHandChamsR, &Settings::Visuals::chamsHandChamsG, &Settings::Visuals::chamsHandChamsB);
		chamsWeaponChamsCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bChamsWeaponChamsEnabled);
		chamsWeaponChamsColor = new GUIColor(0, 0, 100, 15, color_primary, &Settings::Visuals::chamsWeaponChamsR, &Settings::Visuals::chamsWeaponChamsG, &Settings::Visuals::chamsWeaponChamsB);
		
		chamsMaterialDropdown->AddValue("None", MATERIAL_NONE);
		chamsMaterialDropdown->AddValue("Lit", MATERIAL_LIT);
		chamsMaterialDropdown->AddValue("Unlit", MATERIAL_UNLIT);
		chamsMaterialDropdown->AddValue("Metalic", MATERIAL_METALIC);

		// Glow
		glowCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bGlowEnabled);
		glowOnlyEnemiesCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bGlowOnlyEnemies);
		glowIgnoreZCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bGlowIgnoreZ);
		glowEnemiesIgnoreZColor = new GUIColor(0, 0, 100, 15, color_primary, &Settings::Visuals::glowEnemiesIgnoreZR, &Settings::Visuals::glowEnemiesIgnoreZG, &Settings::Visuals::glowEnemiesIgnoreZB);
		glowEnemiesNormalColor = new GUIColor(0, 0, 100, 15, color_primary, &Settings::Visuals::glowEnemiesNormalR, &Settings::Visuals::glowEnemiesNormalG, &Settings::Visuals::glowEnemiesNormalB);
		glowAllyColor = new GUIColor(0, 0, 100, 15, color_primary, &Settings::Visuals::glowAllyR, &Settings::Visuals::glowAllyG, &Settings::Visuals::glowAllyB);
		
		// ESP
		espCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bEspEnabled);
		espBoxDropdown = new GUIDropdown(0, 0, 100, 15, color_primary, &Settings::Visuals::espBoxType);
		espEnemiesNormalCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bESPEnemiesNormal);
		espEnemiesNormalColor = new GUIColor(MENU_X + 275, 0, 100, 15, color_primary, &Settings::Visuals::espEnemiesNormalR, &Settings::Visuals::espEnemiesNormalG, &Settings::Visuals::espEnemiesNormalB);
		espEnemiesIgnoreZCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bESPEnemiesIgnoreZ);
		espEnemiesIgnoreZColor = new GUIColor(MENU_X + 275, 0, 100, 15, color_primary, &Settings::Visuals::espEnemiesIgnoreZR, &Settings::Visuals::espEnemiesIgnoreZG, &Settings::Visuals::espEnemiesIgnoreZB);
		espAlliesNormalCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bESPAlliesNormal);
		espAlliesNormalColor = new GUIColor(MENU_X + 275, 0, 100, 15, color_primary, &Settings::Visuals::espAlliesNormalR, &Settings::Visuals::espAlliesNormalG, &Settings::Visuals::espAlliesNormalB);
		espAlliesIgnoreZCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bESPAlliesIgnoreZ);
		espAlliesIgnoreZColor = new GUIColor(MENU_X + 275, 0, 100, 15, color_primary, &Settings::Visuals::espAlliesIgnoreZR, &Settings::Visuals::espAlliesIgnoreZG, &Settings::Visuals::espAlliesIgnoreZB);
		espBoneCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bESPBone);
		espNameCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bESPName);
		espHealthCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bESPHealth);
		espHealthbarDropdown = new GUIDropdown(0, 0, 100, 15, color_primary, &Settings::Visuals::espHealtBar);
		espWeaponCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Visuals::bChamsWeaponChamsEnabled);

		espBoxDropdown->AddValue("None", ESPBOX_NONE);
		espBoxDropdown->AddValue("Rectangle", ESPBOX_DEFAULT);
		espBoxDropdown->AddValue("Cornered", ESPBOX_CORNERED);
		espBoxDropdown->AddValue("Vertical", ESPBOX_VERTICALLINE);
		espBoxDropdown->AddValue("Horizontal", ESPBOX_HORIZONTALLINE);
		espBoxDropdown->AddValue("Lines", ESPBOX_LINES);

		espHealthbarDropdown->AddValue("None", HEALTHBAR_NONE);
		espHealthbarDropdown->AddValue("Bar", HEALTHBAR_BAR);
		espHealthbarDropdown->AddValue("Bar & Text", HEALTHBAR_TEXT);

		// Grenade Trajectory
		grenadeTrajectory = new GUICheckbox(MENU_X + 275, 0, 15, 15, color_primary, &Settings::Visuals::bGrenadeTrajectoryEnabled);
		grenadeTrajectoryShowDamage = new GUICheckbox(MENU_X + 275, 0, 15, 15, color_primary, &Settings::Visuals::bGrenadeTrajectoryShowDamage);
		grenadeTrajectoryColor = new GUIColor(0, 0, 100, 15, color_primary, &Settings::Visuals::grenadeTrajectoryR, &Settings::Visuals::grenadeTrajectoryG, &Settings::Visuals::grenadeTrajectoryB);

		/*	SKIN	*/
		// KnifeChanger
		knifeChangerEnabled = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::SkinChanger::bKnifeChangerEnabled);
		knifeModel = new GUIDropdown(0, 0, 100, 15, color_primary, &Settings::SkinChanger::Knife);
		knifeSkin = new GUIDropdown(0, 0, 100, 15, color_primary, &Settings::SkinChanger::KnifeSkin);
		knifeWear = new GUISlider(0, 0, 100, 15, color_primary, &Settings::SkinChanger::KnifeWear, 0, 1);
		knifeStattrakCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::SkinChanger::bKnifeStattrak);
		//knifeStattrak = new GUISlider(0, 0, 15, 15, color_primary, &Settings::SkinChanger::KnifeStattrak, 0, 9999);
		// TODO: Add input field

		knifeModel->AddValue("Default", 0);
		knifeModel->AddValue("Default T", KNIFE_DEFAULT_T);
		knifeModel->AddValue("Default CT", KNIFE_DEFAULT_CT);
		knifeModel->AddValue("Bayonet", KNIFE_BAYONET);
		knifeModel->AddValue("Flip Knife", KNIFE_FLIP);
		knifeModel->AddValue("Gut Knife", KNIFE_GUT);
		knifeModel->AddValue("Karambit", KNIFE_KARAM);
		knifeModel->AddValue("M9 Bayonet", KNIFE_M9_BAY);
		knifeModel->AddValue("Huntsman", KNIFE_TACTICAL);
		knifeModel->AddValue("Falchion", KNIFE_FALCHION_ADVANCED);
		knifeModel->AddValue("Bowie", KNIFE_SURVIVAL_BOWIE);
		knifeModel->AddValue("Butterfly", KNIFE_BUTTERFLY);
		knifeModel->AddValue("Shadow Daggers", KNIFE_PUSH);
		knifeModel->AddValue("Talon", KNIFE_WIDOWMAKER);
		knifeModel->AddValue("Ursus", KNIFE_URSUS);
		knifeModel->AddValue("Stiletto", KNIFE_STILETTO);
		knifeModel->AddValue("Navaja", KNIFE_GYPSY_JACKKNIFE);

		// SkinChanger
		skinChangerEnabled = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::SkinChanger::bSkinChangerEnabled);
		weaponSelected = new GUIDropdown(0, 0, 100, 15, color_primary, &Settings::SkinChanger::CurrentWeapon);
		weaponSkin = new GUIDropdown(0, 0, 100, 15, color_primary, &Settings::SkinChanger::WeaponSkin);
		weaponWear = new GUISlider(0, 0, 100, 15, color_primary, &Settings::SkinChanger::WeaponWear, 0, 1);
		weaponStattrakCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::SkinChanger::bWeaponStattrak);
		//weaponStattrak = new GUISlider(0, 0, 100, 15, color_primary, &Settings::SkinChanger::weapon);
		// TODO: Add input field

		/*	MISC	*/
		nightmodeCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Misc::bNightmodeEnabled);
		bunnyhopCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Misc::bBunnyhop);
		thirdpersonCheckbox = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Misc::bThirdpersonEnabled);
		thirdpersonDistanceSlider = new GUISlider(0, 0, 100, 15, color_primary, &Settings::Misc::ThirdpersonDistance, 0, 10);
		clantagChangerEnabled = new GUICheckbox(0, 0, 15, 15, color_primary, &Settings::Misc::bClanTagChangerEnabled);
		saveConfigButton = new GUIButton(MENU_X + (MENU_WIDTH / 2) - 52.5, MENU_Y + MENU_HEIGHT - 80, 100, 25, color_primary, "Save");
		loadConfigButton = new GUIButton(MENU_X + (MENU_WIDTH / 2) + 52.5, MENU_Y + MENU_HEIGHT - 80, 100, 25, color_primary, "Load");
		exitButton = new GUIButton(MENU_X + (MENU_WIDTH / 2) - 50, MENU_Y + MENU_HEIGHT - 50, 100, 25, color_primary, "Quit");
		configDropdown = new GUIDropdown(MENU_X + (MENU_WIDTH / 2) - 52.5, MENU_Y + MENU_HEIGHT - 80, 100, 25, color_primary, &Settings::Misc::SelectedConfig);
		configDropdown->AddValue("Default", 0);
		configDropdown->AddValue("Legit", 1);
		configDropdown->AddValue("HvH", 2);
		configDropdown->AddValue("Custom 1", 3);
		configDropdown->AddValue("Custom 2", 4);

		CreateConfig();
		LoadConfig(0);
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
				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + rageTab->h + (20 * 1), "Silent Aim");
				silentAimCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + rageTab->h + (20 * 1));
				silentAimCheckbox->Draw();
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

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 1), "Material");
				chamsMaterialDropdown->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 1));

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 2), "Enemies Normal");
				chamsEnemiesNormalCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 2));
				chamsEnemiesNormalCheckbox->Draw();
				chamsEnemiesNormalColor->SetPos(MENU_X + 170, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 2));
				chamsEnemiesNormalColor->DrawButton();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 3), "Enemies Ignore Z");
				chamsEnemiesIgnoreZCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 3));
				chamsEnemiesIgnoreZCheckbox->Draw();
				chamsEnemiesIgnoreZColor->SetPos(MENU_X + 170, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 3));
				chamsEnemiesIgnoreZColor->DrawButton();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 4), "Allies Normal");
				chamsAlliesNormalCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 4));
				chamsAlliesNormalCheckbox->Draw();
				chamsAlliesNormalColor->SetPos(MENU_X + 170, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 4));
				chamsAlliesNormalColor->DrawButton();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 5), "Allies Ignore Z");
				chamsAlliesIgnoreZCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 5));
				chamsAlliesIgnoreZCheckbox->Draw();
				chamsAlliesIgnoreZColor->SetPos(MENU_X + 170, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 5));
				chamsAlliesIgnoreZColor->DrawButton();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 6), "Hand Chams");
				chamsHandChamsCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 6));
				chamsHandChamsCheckbox->Draw();
				chamsHandChamsColor->SetPos(MENU_X + 170, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 6));
				chamsHandChamsColor->DrawButton();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 7), "Weapon Chams");
				chamsWeaponChamsCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 7));
				chamsWeaponChamsCheckbox->Draw();
				chamsWeaponChamsColor->SetPos(MENU_X + 170, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 7));
				chamsWeaponChamsColor->DrawButton();
				//	Glow
				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 8), "Glow", fontBig, color_white);
				GetStringSize(wide, tall, "Glow", fontBig);
				glowCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 8) + (tall / 2) - (15 / 2));
				glowCheckbox->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 9) + (tall / 2) - (15 / 2), "Only Enemies");
				glowOnlyEnemiesCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 9) + (tall / 2) - (15 / 2));
				glowOnlyEnemiesCheckbox->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 10) + (tall / 2) - (15 / 2), "Ignore Z");
				glowIgnoreZCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 10) + (tall / 2) - (15 / 2));
				glowIgnoreZCheckbox->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 11) + (tall / 2) - (15 / 2), "Enemies Ignore Z");
				glowEnemiesIgnoreZColor->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 11) + (tall / 2) - (15 / 2));
				glowEnemiesIgnoreZColor->DrawButton();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 12) + (tall / 2) - (15 / 2), "Enemies Normal");
				glowEnemiesNormalColor->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 12) + (tall / 2) - (15 / 2));
				glowEnemiesNormalColor->DrawButton();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 13) + (tall / 2) - (15 / 2), "Allies Normal");
				glowAllyColor->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 13) + (tall / 2) - (15 / 2));
				glowAllyColor->DrawButton();

				//	ESP
				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 5, "ESP", fontBig, color_white);
				GetStringSize(wide, tall, "ESP", fontBig);
				espCheckbox->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 5 + (tall / 2) - (15 / 2));
				espCheckbox->Draw();

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 1), "Box Type");
				espBoxDropdown->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 1));

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 2), "Enemies Normal");
				espEnemiesNormalCheckbox->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 2));
				espEnemiesNormalCheckbox->Draw();
				espEnemiesNormalColor->SetPos(MENU_X + 405, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 2));
				espEnemiesNormalColor->DrawButton();

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 3), "Enemies Ignore Z");
				espEnemiesIgnoreZCheckbox->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 3));
				espEnemiesIgnoreZCheckbox->Draw();
				espEnemiesIgnoreZColor->SetPos(MENU_X + 405, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 3));
				espEnemiesIgnoreZColor->DrawButton();

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 4), "Allies Normal");
				espAlliesNormalCheckbox->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 4));
				espAlliesNormalCheckbox->Draw();
				espAlliesNormalColor->SetPos(MENU_X + 405, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 4));
				espAlliesNormalColor->DrawButton();

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 5), "Allies Ignore Z");
				espAlliesIgnoreZCheckbox->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 5));
				espAlliesIgnoreZCheckbox->Draw();
				espAlliesIgnoreZColor->SetPos(MENU_X + 405, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 5));
				espAlliesIgnoreZColor->DrawButton();

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 6), "Bone");
				espBoneCheckbox->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 6));
				espBoneCheckbox->Draw();

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 7), "Name");
				espNameCheckbox->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 7));
				espNameCheckbox->Draw();

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 8), "Health");
				espHealthCheckbox->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 8));
				espHealthCheckbox->Draw();

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 9), "Healthbar");
				espHealthbarDropdown->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 9));

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 10), "Weapon");
				espWeaponCheckbox->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 10));
				espWeaponCheckbox->Draw();

				chamsMaterialDropdown->Draw();
				chamsEnemiesNormalColor->Draw();
				chamsEnemiesIgnoreZColor->Draw();
				chamsAlliesNormalColor->Draw();
				chamsAlliesIgnoreZColor->Draw();
				chamsHandChamsColor->Draw();
				chamsWeaponChamsColor->Draw();

				glowEnemiesNormalColor->Draw();
				glowEnemiesIgnoreZColor->Draw();
				glowAllyColor->Draw();

				// Grenade Trajectory
				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 11), "Grenade Helper", fontBig, color_white);
				GetStringSize(wide, tall, "Grenade Helper", fontBig);
				grenadeTrajectory->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 11) + (tall / 2) - (15 / 2));
				grenadeTrajectory->Draw();

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 12) + (tall / 2) - (15 / 2), "Show Damage");
				grenadeTrajectoryShowDamage->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 12) + (tall / 2) - (15 / 2));
				grenadeTrajectoryShowDamage->Draw();

				DrawString(MENU_X + 275, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 13) + (tall / 2) - (15 / 2), "Color");
				grenadeTrajectoryColor->SetPos(MENU_X + 385, MENU_Y + MENU_TITLE_BAR_HEIGHT + visualsTab->h + 10 + (20 * 13) + (tall / 2) - (15 / 2));
				grenadeTrajectoryColor->DrawButton();

				espBoxDropdown->Draw();
				espEnemiesNormalColor->Draw();
				espEnemiesIgnoreZColor->Draw();
				espAlliesNormalColor->Draw();
				espAlliesIgnoreZColor->Draw();
				espHealthbarDropdown->Draw();

				grenadeTrajectoryColor->Draw();
			}
			else if (iCurrentPage == skinTab->index) {
				/*	SKIN	*/
				// Knife Changer
				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 5, "Knife Changer", fontBig, color_white);
				int wide;
				int tall;
				GetStringSize(wide, tall, "Knife Changer", fontBig);
				knifeChangerEnabled->SetPos(MENU_X + 125, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 5 + (tall / 2) - (15 / 2));
				knifeChangerEnabled->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 1), "Model");
				knifeModel->SetPos(MENU_X + 125, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 1));
				//knifeModel->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 2), "Skin");
				knifeSkin->SetPos(MENU_X + 125, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 2));
				//knifeSkin->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 3), "Wear");
				knifeWear->SetPos(MENU_X + 125, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 3));
				knifeWear->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 4), "StatTrak");
				knifeStattrakCheckbox->SetPos(MENU_X + 125, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 4));
				knifeStattrakCheckbox->Draw();

				DrawString(MENU_X + 250, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 5, "Skin Changer", fontBig, color_white);
				GetStringSize(wide, tall, "Skin Changer", fontBig);
				skinChangerEnabled->SetPos(MENU_X + 350, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 5 + (tall / 2) - (15 / 2));
				skinChangerEnabled->Draw();

				DrawString(MENU_X + 250, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 1), "Weapon");
				weaponSelected->SetPos(MENU_X + 350, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 1));
				//weaponSelected->Draw();

				DrawString(MENU_X + 250, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 2), "Skin");
				weaponSkin->SetPos(MENU_X + 350, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 2));
				//weaponSkin->Draw();

				DrawString(MENU_X + 250, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 3), "Wear");
				weaponWear->SetPos(MENU_X + 350, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 3));
				weaponWear->Draw();

				DrawString(MENU_X + 250, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 4), "StatTrak");
				weaponStattrakCheckbox->SetPos(MENU_X + 350, MENU_Y + MENU_TITLE_BAR_HEIGHT + skinTab->h + 10 + (20 * 4));
				weaponStattrakCheckbox->Draw();

				weaponSkin->Draw();
				weaponSelected->Draw();
				knifeSkin->Draw();
				knifeModel->Draw();
			}
			else if (iCurrentPage == miscTab->index) {

				saveConfigButton->SetPos(MENU_X + (MENU_WIDTH / 2) - 52.5, MENU_Y + MENU_HEIGHT - 80);
				saveConfigButton->Draw();

				loadConfigButton->SetPos(MENU_X + (MENU_WIDTH / 2) + 52.5, MENU_Y + MENU_HEIGHT - 80);
				loadConfigButton->Draw();

				exitButton->SetPos(MENU_X + (MENU_WIDTH / 2) - 50, MENU_Y + MENU_HEIGHT - 50);
				exitButton->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + miscTab->h + (20 * 1), "Nightmode");
				nightmodeCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + miscTab->h + (20 * 1));
				nightmodeCheckbox->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + miscTab->h + (20 * 2), "Bunnyhop");
				bunnyhopCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + miscTab->h + (20 * 2));
				bunnyhopCheckbox->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + miscTab->h + (20 * 3), "Thirdperson");
				thirdpersonCheckbox->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + miscTab->h + (20 * 3));
				thirdpersonCheckbox->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + miscTab->h + (20 * 4), "Thirdperson Offset");
				thirdpersonDistanceSlider->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + miscTab->h + (20 * 4));
				thirdpersonDistanceSlider->Draw();

				DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT + miscTab->h + (20 * 5), "Clantag Changer");
				clantagChangerEnabled->SetPos(MENU_X + 150, MENU_Y + MENU_TITLE_BAR_HEIGHT + miscTab->h + (20 * 5));
				clantagChangerEnabled->Draw();

				configDropdown->SetPos(MENU_X + (MENU_WIDTH / 2) - 100, MENU_Y + MENU_HEIGHT - 80);
				configDropdown->Draw();
			}

			GetStringSize(wide, tall, MENU_TITLE_TEXT);
			DrawString(MENU_X + 5, MENU_Y + MENU_TITLE_BAR_HEIGHT / 2 - tall / 2, MENU_TITLE_TEXT);
		}

		DrawString(5, 5, WATERMARK_TEXT);

		prev_cursor_x = cursor_x;
		prev_cursor_y = cursor_y;

		if (bReload) {
			bReload = false;
			ESP::Init();
			Chams::Init();
			if (bNightmodeBefore != Settings::Misc::bNightmodeEnabled) {
				if (Settings::Misc::bNightmodeEnabled) {
					Nightmode::Perform();
					Chams::Init();
					Menu::Init();
				}
				else {
					Nightmode::Reset();
					Chams::Init();
					Menu::Init();
				}
			}
			bNightmodeBefore = Settings::Misc::bNightmodeEnabled;
		}
	}
};

#endif