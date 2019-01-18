// Created by Credix - Licence: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
#ifndef ESP_H
#define ESP_H

#include "../Headers/Interfaces.h"
#include "../Hacks/Settings.h"
#include "../Headers/MenuWrapper.h"

static BYTE iBoneLegL[] = { 24, 23, 22, 1 };
static BYTE iBoneLegR[] = { 27, 26, 25, 1 };

static BYTE iBoneBody[] = { 5, 4, 3, 2, 1 };

static BYTE iBoneArmL[] = { 9, 8, 7, 5 };
static BYTE iBoneArmR[] = { 15, 14, 13, 5 };

Vector GetBone(C_BaseEntity* BaseEntity, int index) {
	matrix3x4_t bonesMatrix[128];
	BaseEntity->SetupBones(bonesMatrix, 128, 0, 0.0f);
	matrix3x4_t boneMatrix = bonesMatrix[index];
	return Vector(boneMatrix[0][3], boneMatrix[1][3], boneMatrix[2][3]);
}

Vector2D GetBoneScreen(C_BaseEntity* BaseEntity, int index) {
	matrix3x4_t bonesMatrix[128];
	BaseEntity->SetupBones(bonesMatrix, 128, 0, 0.0f);
	matrix3x4_t boneMatrix = bonesMatrix[index];
	Vector boneVector = Vector(boneMatrix[0][3], boneMatrix[1][3], boneMatrix[2][3]);
	return WorldToScreen(boneVector);
}

void DrawBoneLine(C_BaseEntity* BaseEntity,int i1, int i2) {
	Vector2D boneScreen = GetBoneScreen(BaseEntity, i1);
	Vector2D boneScreen2 = GetBoneScreen(BaseEntity, i2);
	DrawLine(boneScreen.x, boneScreen.y, boneScreen2.x, boneScreen2.y, color_white);
}

namespace ESP {
	void Init() {

	}
	void Draw() {
		IClientEntity* LocalEntity = g_pClientEntityList->GetClientEntity(g_pEngineClient->GetLocalPlayer());
		if (!LocalEntity)
			return;

		ClientClass* LocalEntityClass = LocalEntity->GetClientClass();
		if (!LocalEntityClass)
			return;

		C_BaseEntity* LocalBaseEntity = LocalEntity->GetBaseEntity();
		if (!LocalBaseEntity)
			return;

		Vector LocalPlayerLoc = GetBone(LocalBaseEntity, 1);

		for (int i = 0; i < g_pClientEntityList->GetHighestEntityIndex(); i++) {
			IClientEntity* Entity = g_pClientEntityList->GetClientEntity(i);
			if (!Entity)
				continue;

			ClientClass* EntityClass = Entity->GetClientClass();
			if (!EntityClass)
				continue;

			const char* EntityType = EntityClass->GetName();
			if (_strcmpi(EntityType, "CCSPlayer") == 0 && Entity->entindex() != g_pEngineClient->GetLocalPlayer()) {
				C_BaseEntity* BaseEntity = Entity->GetBaseEntity();
				if (!BaseEntity)
					continue;

				if (Entity->entindex() == g_pEngineClient->GetLocalPlayer())
					continue;

				C_BaseEntity* EntityBase = (C_BaseEntity*)g_pClientEntityList->GetClientEntity(i);
				int health = *reinterpret_cast<int*>((DWORD)Entity->GetBaseEntity() + Offsets::m_iHealth);

				if (health > 0 && !EntityBase->IsDormant()) {
					const char* modelName = g_pModelInfo->GetModelName(Entity->GetModel());
					Vector2D boneScreen;
					int w, h;
					/*for (int boneID = 0; boneID < 99; boneID++) {
						boneScreen = GetBoneScreen(BaseEntity, boneID);
						char buf[52] = { 0 };
						sprintf(buf, "%i", boneID);
						GetStringSize(w, h, buf, fontSmall);
						DrawString(boneScreen.x - w / 2, boneScreen.y - h / 2, buf, fontSmall, color_white);
					}*/

					Vector top = GetBone(BaseEntity, 8);
					Vector bottom = GetBone(BaseEntity, 1);
					Vector2D topScreen = WorldToScreen(top);
					Vector2D bottomScreen = WorldToScreen(bottom);
					float height = topScreen.y - bottomScreen.y;
					float width = height / 3;
					int centery = topScreen.y + (height / 2);
					int topx = bottomScreen.x - width;
					int topy = bottomScreen.x += width;
					int botx = centery - ((height - 2) * 1.3);
					int boty = (centery + ((height / 2) * 1.2));

					player_info_t EntityInfo;
					g_pEngineClient->GetPlayerInfo(Entity->entindex(), &EntityInfo);

					DrawLine(topx, topScreen.y, topy, topScreen.y, color_white);
					DrawLine(topx, bottomScreen.y, topy, bottomScreen.y, color_white);
					DrawLine(topx, bottomScreen.y, topx, topScreen.y, color_white);
					DrawLine(topy, bottomScreen.y, topy, topScreen.y, color_white);
					GetStringSize(w, h, EntityInfo.player_name);
					DrawString(topScreen.x - (w/2), topScreen.y - h, EntityInfo.player_name);
				}
			}
		}
	}
};

#endif