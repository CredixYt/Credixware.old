// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef SKINCHANGER_H
#define SKINCHANGER_H

#include "../SDK/SDK.h"
#include <map>

/* NOTE: Changed by FireEventClientSide.h */
bool bKnifeEquipped = false;
int iLocalID = 0;

bool IsKnife(int id) {
	for (int i = 0; i < 17; i++) {
		if (KnifeDefinitions_t[i] == id) {
			return true;
		}
	}
	return false;
}

std::map<int, int> KnifeDefinitions;

template <typename T>
auto GetEntityFromHandle(CBaseHandle h) -> T*
{
	return (T*)(g_pClientEntityList->GetClientEntityFromHandle(h));
}

void FixKnifeAnim(int OldDefinition, int NewDefinition, int sequence) {

}

WeaponSkinList_t WeaponSkinLists[65] = {
	WeaponSkinList_t()
};

WeaponSkinList_t KnifeSkinLists[521] = {
	WeaponSkinList_t()
};

namespace SkinChanger {
	int update_index = 0;
	IClientEntity* LocalEntity;
	void Init() {
		player_info_t localPlayer;
		LocalEntity = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
		if (g_pEngineClient->GetPlayerInfo(g_pEngineClient->GetLocalPlayer(), &localPlayer)) {
			iLocalID = localPlayer.user_id;
		}
		WeaponSkinLists[0].Init(0);
		WeaponSkinLists[WEAPON_DEAGLE].Init(25, 0, BLAZE, BRONZE_DECO, COBALT_DISRUPTION, CODE_RED, CONSPIRACY, CORINTHIAN, CRIMSON_WEB2, DIRECTIVE, GOLDEN_KOI, HAND_CANNON, HEIRLOOM, HYPNOTIC, KUMICHO_DRAGON, MECHA_INDUSTRIES3, METEORITE, MIDNIGHT_STORM, MUDDER, NAGA, NIGHT, OXIDE_BLAZE, PILOT, SUNSET_STORM, URBAN_DDPAT, URBAN_RUBBLE);
		WeaponSkinLists[WEAPON_ELITE].Init(23, 0, ANODIZED_NAVY, BLACK_LIMBA, BRIAR, CARTEL3, COBALT_QUARTZ, COBRA_STRIKE, COLONY, CONTRACTOR, DEMOLITION, DUALING_DRAGONS, DUELIST, HEMOGLOBIN, MARINA, MOON_IN_LIBRA, PANTHER, RETRIBUTION, ROYAL_CONSORTS, SHRED, STAINED, TWIN_TURBO, URBAN_SHOCK, VENTILATORS);
		WeaponSkinLists[WEAPON_FIVESEVEN].Init(26, 0, ANODIZED_GUNMETAL, CANDY_APPLE, CAPILLARY, CASE_HARDENED, CONTRACTOR, COOLANT, COPPER_GALAXY, FLAME_TEST, FOREST_NIGHT, FOWL_PLAY, HOT_SHOT, HYPER_BEAST4, JUNGLE, KAMI, MONKEY_BUSINESS, NEON_KIMONO, NIGHTSHADE, NITRO, ORANGE_PEEL, RETROBUTION, SCUMBRIA2, SILVER_QUARTZ, TRIUMVIRATE, URBAN_HAZARD2, VIOLENT_DAIMYO);
		WeaponSkinLists[WEAPON_GLOCK].Init(28, 0, BLUE_FISSURE, BRASS, BUNSEN_BURNER, CANDY_APPLE, CATACOMBS, DEATH_RATTLE, DRAGON_TATTOO, FADE, GRINDER, GROUNDWATER, HIGH_BEAM, IRONWORK, MOONRISE, NIGHT, NUCLEAR_GARDEN, OFF_WORLD, OXIDE_BLAZE3, REACTOR, ROYAL_LEGION, SAND_DUNE2, STEEL_DISRUPTION, TWILIGHT_GALAXY, WARHAWK, WASTELAND_REBEL2, WATER_ELEMENTAL, WEASEL, WRAITHS);
		WeaponSkinLists[WEAPON_AK47].Init(30, 0, AQUAMARINE_REVENGE, ASIIMOV5, BLACK_LAMINATE, BLOODSPORT2, BLUE_LAMINATE, CARTEL2, CASE_HARDENED, ELITE_BUILD, EMERALD_PINSTRIPE, FIRE_SERPENT, FIRST_CLASS, FRONTSIDE_MISTY, FUEL_INJECTOR, HYDROPONIC, JAGUAR, JET_SET, JUNGLE_SPRAY, NEON_REVOLUTION, NEON_RIDER2, ORBIT_MK01, POINT_DISARRAY, PREDATOR, RED_LAMINATE, REDLINE2, SAFARI_MESH, SAFETY_NET, THE_EMPRESS, VULCAN, WASTELAND_REBEL);
		WeaponSkinLists[WEAPON_AUG].Init(24, 0, AKIHABARA_ACCEPT, AMBER_SLIPSTREAM, ANODIZED_NAVY2, ARISTOCRAT, BENGAL_TIGER, CHAMELEON, COLONY, CONDEMNED, CONTRACTOR, COPPERHEAD, DAEDALUS, FLEET_FLOCK, HOT_ROD, RADIATION_HAZARD2, RANDOM_ACCESS, RICOCHET, STORM, STYMPHALIAN, SWEEPER, SYD_MEAD, TORQUE, TRIQUA, WINGS);
		WeaponSkinLists[WEAPON_AWP].Init(26, 0, ACHERON, ASIIMOV2, BOOM, CORTICERA, DRAGON_LORE, ELECTRIC_HIVE, ELITE_BUILD3, FEVER_DREAM, GRAPHITE, HYPER_BEAST2, LIGHTNING_STRIKE, MAN_O_WAR, MEDUSA, MORTIS, NEO_NOIR3, ONI_TAIJI, PAW, PHOBOS, PINK_DDPAT, PIT_VIPER, REDLINE, SAFARI_MESH, SNAKE_CAMO, SUN_IN_LEO, WORM_GOD);
		WeaponSkinLists[WEAPON_FAMAS].Init(20, 0, AFTERIMAGE, COLONY, CONTRAST_SPRAY, CYANOSPATTER, DJINN, DOOMKITTY, EYE_OF_ATHENA, HEXANE, MACABRE, MECHA_INDUSTRIES2, NEURAL_NET, PULSE, ROLL_CAGE, SERGEANT, SPITFIRE, STYX, SURVIVOR_Z, TEARDOWN, VALENCE2);
		WeaponSkinLists[WEAPON_G3SG1].Init(22, 0, ARCTIC_CAMO, AZURE_ZEBRA, CHRONOS, CONTRACTOR, DEMETER, DESERT_STORM, FLUX, GREEN_APPLE, HIGH_SEAS, HUNTER, JUNGLE_DASHED, MURKY, ORANGE_CRASH, ORANGE_KIMONO, POLAR_CAMO, SAFARI_MESH, SCAVENGER, STINGER, THE_EXECUTIONER, VARICAMO, VENTILATOR);
		WeaponSkinLists[WEAPON_GALILAR].Init(24, 0, AQUA_TERRACE, BLACK_SAND, BLUE_TITANIUM, CERBERUS, CHATTERBOX, COLD_FUSION, CRIMSON_TSUNAMI, ECO, FIREFIGHT, HUNTING_BLIND, KAMI2, ORANGE_DDPAT, ROCKET_POP, SAGE_SPRAY, SANDSTORM, SHATTERED, SIGNAL, STONE_COLD, SUGAR_RUSH, TUXEDO, URBAN_RUBBLE, VARICAMO, WINTER_FOREST);
		WeaponSkinLists[WEAPON_M249].Init(0);
		WeaponSkinLists[WEAPON_M4A1].Init(28, 0, ASIIMOV, BULLET_RAIN, BUZZ_KILL, CONVERTER, DAYBREAK, DESERT_STORM, DESERT_STRIKE, DESOLATE_SPACE, EVIL_DAIMYO, FADED_ZEBRA, GRIFFIN, HELLFIRE, HOWL, JUNGLE_TIGER, MAGNESIUM, MAINFRAME, MODERN_HUNTER, NEO_NOIR2, POSEIDON, RADIATION_HAZARD, ROYAL_PALADIN, THE_BATTLESTAR, TORNADO, URBAN_DDPAT, X_RAY, ZIRKA, DRAGON_KING);
		WeaponSkinLists[WEAPON_MAC10].Init(0);
		WeaponSkinLists[WEAPON_P90].Init(0);
		WeaponSkinLists[WEAPON_MP5SD].Init(0);
		WeaponSkinLists[WEAPON_UMP45].Init(0);
		WeaponSkinLists[WEAPON_XM1014].Init(0);
		WeaponSkinLists[WEAPON_BIZON].Init(0);
		WeaponSkinLists[WEAPON_MAG7].Init(0);
		WeaponSkinLists[WEAPON_NEGEV].Init(0);
		WeaponSkinLists[WEAPON_SAWEDOFF].Init(0);
		WeaponSkinLists[WEAPON_TEC9].Init(27, 0, ARMY_MESH, AVALANCHE, BAMBOO_FOREST, BLUE_TITANIUM, BRASS, CRACKED_OPAL, CUT_OUT, FUBAR, FUEL_INJECTOR2, GROUNDWATER, HADES, ICE_CAP, ISAAC, JAMBIYA, NUCLEAR_THREAT2, OSSIFIED, RE_ENTRY, RED_QUARTZ, REMOTE_CONTROL, SANDSTORM2, SNEK_9, TERRACE, TITANIUM_BIT, TORNADO2, TOXIC, URBAN_DDPAT, VARICAMO);
		WeaponSkinLists[WEAPON_HKP2000].Init(23, 0, AMBER_FADE, CHAINMAIL, COACH_CLASS, CORTICERA2, FIRE_ELEMENTAL, GRANITE_MARBLEIZED, GRASSLAND, GRASSLAND_LEAVES, HANDGUN, IMPERIAL, IMPERIAL_DRAGON, IVORY, OCEAN_FOAM, OCEANIC, PATHFINDER, PULSE3, RED_FRAGCAM, SCORPION, SILVER, TURF, URBAN_HAZARD3, WOODSMAN);
		WeaponSkinLists[WEAPON_MP7].Init(0);
		WeaponSkinLists[WEAPON_MP9].Init(0);
		WeaponSkinLists[WEAPON_NOVA].Init(0);
		WeaponSkinLists[WEAPON_P250].Init(33, 0, ASIIMOV4, BONE_MASK, BOREAL_FOREST, CARTEL, CONTAMINATION, CRIMSON_KIMONO, EXCHANGER, FACETS, FACILITY_DRAFT, FRANKLIN, GUNSMOKE, HIVE, IRON_CLAD, MEHNDI, METALLIC_DDPAT, MINT_KIMONO, MODERN_HUNTER, MUERTOS, NEVERMORE, NUCLEAR_THREAT, RED_ROCK, RIPPLE, SAND_DUNE, SEE_YA_LATER, SPLASH, STEEL_DISRUPTION, SUPERNOVA, UNDERTOW, VALENCE, VINO_PRIMO, WHITEOUT, WINGSHOT);
		WeaponSkinLists[WEAPON_SCAR20].Init(19, 0, ARMY_SHEEN, BLOODSPORT, BLUEPRINT, CARBON_FIBER, CARDIAC, CONTRACTOR, CRIMSON_WEB2, CYREX, EMERALD, GREEN_MARINE, GROTTO, JUNGLE_SLIPSTREAM2, OUTBREAK, PALM, POWERCORE, SAND_MESH, SPLASH_JAM, STORM);
		WeaponSkinLists[WEAPON_SG556].Init(22, 0, AERIAL, ALOHA2, ANODIZED_NAVY, ARMY_SHEEN, ATLAS, BULLDOZER, CYREX3, DAMASCUS_STEEL, DANGER_CLOSE, FALLOUT_WARNING2, GATOR_MESH, INTEGRALE, PHANTOM, PULSE2, TIGER_MOTH, TORNADO, TRAVELER, TRIARCH, ULTRAVIOLET, WAVE_SPRAY, WAVES_PERFORATED);
		WeaponSkinLists[WEAPON_SSG08].Init(18, 0, ABYSS, ACID_FADE, BIG_IRON, BLOOD_IN_THE_WATER, BLUE_SPRUCE, DARK_WATER, DEATHS_HEAD, DETOUR, DRAGONFIRE, GHOST_CRUSADER, HAND_BRAKE, LICHEN_DASHED, MAYAN_DREAMS, NECROPOS, SAND_DUNE, SLASHED, TROPICAL_STORM);
		WeaponSkinLists[WEAPON_M4A1_SILENCER].Init(25, 0, ATOMIC_ALLOY, BASILISK, BLOOD_TIGER, BOREAL_FOREST, BRIEFING2, BRIGHT_WATER, CHANTICOS_FIRE, CONTROL_PANEL, CYREX2, DARK_WATER, DECIMATOR, FLASHBACK, GOLDEN_COIL, GUARDIAN, HOT_ROD2, HYPER_BEAST, ICARUS_FELL, KNIGHT, LEADED_GLASS, MASTER_PIECE, MECHA_INDUSTRIES, NIGHTMARE, NITRO, VARICAMO);
		WeaponSkinLists[WEAPON_USP_SILENCER].Init(24, 0, BLOOD_TIGER, BLUEPRINT2, BUSINESS_CLASS, CAIMAN, CHECK_ENGINE, CORTEX, CYREX4, DARK_WATER, FLASHBACK, FOREST_LEAVES, GUARDIAN2, KILL_CONFIRMED, LEAD_CONDUIT, NEO_NOIR2, NIGHT_OPS, ORION, OVERGROWTH, PARA_GREEN, ROAD_RASH, ROYAL_BLUE, SERUM, STAINLESS, TORQUE);
		WeaponSkinLists[WEAPON_CZ75A].Init(23, 0, ARMY_SHEEN, CHALICE, CRIMSON_WEB, ECO2, EMERALD2, GREEN_PLAID, HEXANE, IMPRINT, NITRO2, POISON_DART, POLE_POSITION, POLYMER, RED_ASTOR, TACTICAT, THE_FUSCHIA_IS_NOW, TIGRIS, TREAD_PLATE, TUXEDO, TWIST, VICTORIA, XIANGLIU, YELLOW_JACKET);
		WeaponSkinLists[WEAPON_REVOLVER].Init(10, 0, AMBER_FADE2, BONE_MASK, CRIMSON_WEB, FADE2, GRIP, LLAMA_CANNON, NITRO3, REBOOT, SURVIVALIST);

		KnifeSkinLists[WEAPON_KNIFEGG].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_T].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE].Init(1, 0);
		KnifeSkinLists[WEAPON_BAYONET].Init(35, 0, AUTOTRONIC, BLACK_LAMINATE2, BLUE_STEEL, BOREAL_FOREST, BRIGHT_WATER2, CASE_HARDENED, CRIMSON_WEB, DAMASCUS_STEEL2, DOPPLER, DOPPLER2, DOPPLER3, DOPPLER4, DOPPLER5, DOPPLER6, DOPPLER7, FADE, FREEHAND, FOREST_DDPAT, GAMMA_DOPPLER, GAMMA_DOPPLER2, GAMMA_DOPPLER3, GAMMA_DOPPLER4, GAMMA_DOPPLER5, LORE, NIGHT, MARBLE_FADE, RUST_COAT3, SAFARI_MESH, SLAUGHTER, SCORCHED, STAINED, TIGER_TOOTH, URBAN_MASKED, ULTRAVIOLET);
		KnifeSkinLists[WEAPON_KNIFE_FLIP].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_GUT].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_KARAMBIT].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_M9_BAYONET].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_TACTICAL].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_FALCHION].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_SURVIVAL_BOWIE].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_BUTTERFLY].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_PUSH].Init(25, 0, BLUE_STEEL, BOREAL_FOREST, CASE_HARDENED, CRIMSON_WEB, DAMASCUS_STEEL2, DOPPLER, DOPPLER2, DOPPLER3, DOPPLER4, DOPPLER5, DOPPLER6, DOPPLER7, FADE, FOREST_DDPAT, MARBLE_FADE, NIGHT, RUST_COAT3, SAFARI_MESH, SCORCHED, SLAUGHTER, STAINED, TIGER_TOOTH, ULTRAVIOLET, URBAN_MASKED);
		KnifeSkinLists[WEAPON_KNIFE_WIDOWMAKER].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_URSUS].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_STILETTO].Init(1, 0);
		KnifeSkinLists[WEAPON_KNIFE_GYPSY_JACKKNIFE].Init(1, 0);
	}
	void ForceFullUpdate() {
		g_pEngineClient->ClientCmd_Unrestricted("cl_fullupdate");
	}
	void Update() {
		update_index++;
		IClientEntity* LocalPlayer = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
		int Health = *(int*)((DWORD)LocalPlayer->GetBaseEntity() + Offsets::m_iHealth);
		if (Settings::SkinChanger::bKnifeChangerEnabled && Settings::SkinChanger::Knife != 0 && Health > 0) {
			for (int i = 0; i < g_pClientEntityList->GetHighestEntityIndex(); i++) {
				IClientEntity* Entity = g_pClientEntityList->GetClientEntity(i);
				if (Entity) {
					ClientClass* EntityClass = Entity->GetClientClass();
					if (EntityClass->m_ClassID == CPREDICTEDVIEWMODEL) {
						C_BaseEntity* BaseEntity = Entity->GetBaseEntity();
						if (BaseEntity && bKnifeEquipped) {
							int karam = g_pModelInfo->GetModelIndex(KnifeModels[Settings::SkinChanger::Knife].c_str());
							BaseEntity->SetModelIndex(karam);
						}
					}
					/*RecvTable* pClassTable = EntityClass->m_pRecvTable;
					for (int nIndex = 0; nIndex < pClassTable->m_nProps; nIndex++) {
						RecvProp* pProp = &pClassTable->m_pProps[nIndex];
						printf("%s: %s\n", EntityClass->GetName(), pProp->m_pVarName);
					}*/
				}
			}
		}
		if (Settings::SkinChanger::bSkinChangerEnabled && g_pEngineClient->IsInGame() && Health > 0) {
			IClientEntity* LocalEntity = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
			for (int i = 0; i < 16; i++) {
				int WeaponIndex = *(int*)((DWORD)LocalEntity->GetBaseEntity() + Offsets::m_hMyWeapons + ((i - 1) * 0x4)) & 0xFFF;
				if (WeaponIndex >= 4095 || WeaponIndex < 1) {
					continue;
				}
				int WeaponEntity = (int)g_pClientEntityList->GetClientEntity(WeaponIndex);
				int WeaponDefinition = *(int*)(WeaponEntity + Offsets::m_iItemDefinitionIndex);
				if (IsKnife(WeaponDefinition)) {
					*(int*)(WeaponEntity + Offsets::m_nFallbackSeed) = 0;
					*(int*)(WeaponEntity + Offsets::m_iItemDefinitionIndex) = KnifeDefinitions_t[Settings::SkinChanger::Knife];
					*(int*)(WeaponEntity + Offsets::m_nFallbackPaintKit) = Settings::SkinChanger::KnifeModelSkin;
				} else if (Settings::SkinChanger::WeaponSkins[WeaponDefinition] != 0) {
					*(int*)(WeaponEntity + Offsets::m_nFallbackSeed) = 0;
					*(int*)(WeaponEntity + Offsets::m_nFallbackPaintKit) = Settings::SkinChanger::WeaponSkins[WeaponDefinition];
				}

				if (Settings::SkinChanger::WeaponWears[WeaponDefinition] < 1.0f && Settings::SkinChanger::WeaponWears[WeaponDefinition] && !IsKnife(WeaponDefinition)) {
					*(float*)(WeaponEntity + Offsets::m_flFallbackWear) = Settings::SkinChanger::WeaponWears[WeaponDefinition];
				} else if (Settings::SkinChanger::KnifeWear < 1.0f && Settings::SkinChanger::KnifeWear && IsKnife(WeaponDefinition)) {
					*(float*)(WeaponEntity + Offsets::m_flFallbackWear) = Settings::SkinChanger::KnifeWear;
				}
				*(int*)(WeaponEntity + Offsets::m_iItemIDHigh) = -1;
			}
		}

		/*case KNIFE_URSUS:
	switch (iSequence)
	{
	case SEQUENCE_DEFAULT_DRAW:
		iSequence = RandomInt(SEQUENCE_BUTTERFLY_DRAW, SEQUENCE_BUTTERFLY_DRAW2);
		break;
	case SEQUENCE_DEFAULT_LOOKAT01:
		iSequence = RandomInt(SEQUENCE_BUTTERFLY_LOOKAT01, SEQUENCE_BUTTERFLY_LOOKAT03);
 		break;
 	default:
 		iSequence++;
 		break;
 	}
 	break;
case KNIFE_STILETTO:
 	switch (iSequence)
 	{
 	case SEQUENCE_DEFAULT_LOOKAT01:
 		iSequence = RandomInt(12, 13);
 		break;
 	}
 	break;
case KNIFE_WIDOWMAKER:
 	switch (iSequence)
 	{
 	case SEQUENCE_DEFAULT_LOOKAT01:
 		iSequence = RandomInt(14, 15);
 		break;
 	}
 	break*/
	}
	void SetCurrentWeaponSkinList() {
		weaponSkin->ClearValues();
		if (!g_pEngineClient->IsInGame()) return;
		for (int i = 0; i < WeaponSkinLists[WeaponDefinitions[Settings::SkinChanger::CurrentWeapon]].Size; i++) {
			int index = 0;
			for (int x = 0; x < 740; x++) {
				if (PaintKitList[x] == WeaponSkinLists[WeaponDefinitions[Settings::SkinChanger::CurrentWeapon]].List[i]) {
					index = x;
				}
			}
			weaponSkin->AddValue(PaintKitNames[index].c_str(), i);
		}
	}
	void SetCurrentKnifeSkinList() {
		knifeSkin->ClearValues();
		if (!g_pEngineClient->IsInGame()) return;
		for (int i = 0; i < KnifeSkinLists[KnifeDefinitions_t[Settings::SkinChanger::Knife]].Size; i++) {
			int index = 0;
			for (int x = 0; x < 740; x++) {
				if (PaintKitList[x] == KnifeSkinLists[KnifeDefinitions_t[Settings::SkinChanger::Knife]].List[i]) {
					index = x;
				}
			}
			knifeSkin->AddValue(PaintKitNames[index].c_str(), i);
		}
	}
	void UpdateSkin() {
		Settings::SkinChanger::WeaponSkins[WeaponDefinitions[*weaponSelected->pValue]] = WeaponSkinLists[WeaponDefinitions[*weaponSelected->pValue]].List[*weaponSkin->pValue];
		Settings::SkinChanger::KnifeModelSkin = KnifeSkinLists[KnifeDefinitions_t[*knifeModel->pValue]].List[*knifeSkin->pValue];
	}
}

#endif