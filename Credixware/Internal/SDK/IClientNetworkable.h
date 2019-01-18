// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef ICLIENTNETWORKABLE_H
#define ICLIENTNETWORKABLE_H

class IClientEntity;
class ClientClass;
class bf_read;
class bf_write;
class IClientUnknown;

enum ShouldTransmitState_t
{
	SHOULDTRANSMIT_START = 0,
	SHOULDTRANSMIT_END
};

enum DataUpdateType_t
{
	DATA_UPDATE_CREATED = 0,
	DATA_UPDATE_DATATABLE_CHANGED,
};

class IClientNetworkable
{
public:
	virtual IClientUnknown*	GetIClientUnknown() = 0;									// 0
	virtual void			Release() = 0;												// 1
	ClientClass*			GetClientClass() {
		typedef ClientClass*(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 2)(this);
	}
	virtual void			NotifyShouldTransmit(ShouldTransmitState_t state) = 0;		// 3
	virtual void			OnPreDataChanged(DataUpdateType_t updateType) = 0;			// 4
	virtual void			OnDataChanged(DataUpdateType_t updateType) = 0;				// 5
	virtual void			PreDataUpdate(DataUpdateType_t updateType) = 0;				// 6
	virtual void			PostDataUpdate(DataUpdateType_t updateType) = 0;			// 7
	bool					IsDormant() {
		typedef bool(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 9)(this);
	}
	int						entindex() {
		typedef int(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 10)(this);
	}
	virtual void			ReceiveMessage(int classID, bf_read &msg) = 0;
	virtual void*			GetDataTableBasePtr() = 0;
	virtual void			SetDestroyedOnRecreateEntities(void) = 0;
};

#endif