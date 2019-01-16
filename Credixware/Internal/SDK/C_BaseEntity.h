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

#endif