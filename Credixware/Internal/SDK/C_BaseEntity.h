// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef C_BASEENTITY_H
#define C_BASEENTITY_H

#include "IClientEntity.h"

struct FireBulletsInfo_t;
struct trace_t;
class CTakeDamageInfo;
class ITraceFilter;
class CDmgAccumulator;
class CEntityMapData;

class C_BaseEntity : public IClientEntity
{
public:
	void					SetModelIndex(int index) {
		typedef void(__thiscall* Fn)(void*, int);
		Utils::GetVFunc<Fn>(this, 75)(this, index);
	}
};

Vector GetBone(C_BaseEntity* BaseEntity, int index) {
	matrix3x4_t bonesMatrix[128];
	BaseEntity->SetupBones(bonesMatrix, 128, 0, 0.0f);
	matrix3x4_t boneMatrix = bonesMatrix[index];
	return Vector(boneMatrix[0][3], boneMatrix[1][3], boneMatrix[2][3]);
}

#endif