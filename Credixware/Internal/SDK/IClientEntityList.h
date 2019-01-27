// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef ICLIENTENTITYLIST_H
#define ICLIENTENTITYLIST_H

#include "Interface.h"
#include "../Headers/Utils.h"

#include "IClientThinkable.h"

class IClientEntity;
class ClientClass;
class IClientNetworkable;
class IClientUnknown;
class IClientEntityList
{
public:
	virtual IClientNetworkable*	GetClientNetworkable(int entnum) = 0;
	virtual IClientNetworkable*	GetClientNetworkableFromHandle(CBaseHandle hEnt) = 0;
	virtual IClientUnknown*		GetClientUnknownFromHandle(CBaseHandle hEnt) = 0;
	virtual IClientEntity*		GetClientEntity(int entnum) = 0;
	/*IClientEntity*					GetClientEntity(int entnum) {
		typedef IClientEntity*(__thiscall* Fn)(void*, int);
		return Utils::GetVFunc<Fn>(this, 3)(this, entnum);
	}*/
	virtual IClientEntity*		GetClientEntityFromHandle(CBaseHandle hEnt) = 0;
	/*IClientEntity*				GetClientEntityFromHandle(CBaseHandle hEnt) {
		typedef IClientEntity*(__thiscall* Fn)(void*, CBaseHandle);
		return Utils::GetVFunc<Fn>(this, 4)(this, hEnt);
	}*/
	virtual int					NumberOfEntities(bool bIncludeNonNetworkable) = 0;
	int							GetHighestEntityIndex() {
		typedef int(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 6)(this);
	}
	//virtual int					GetHighestEntityIndex(void) = 0;
	virtual void				SetMaxEntities(int maxents) = 0;
	virtual int					GetMaxEntities() = 0;
};

#endif