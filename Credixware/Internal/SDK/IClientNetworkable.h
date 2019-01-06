// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef ICLIENTNETWORKABLE_H
#define ICLIENTNETWORKABLE_H

class IClientEntity;
class ClientClass;
class bf_read;
class bf_write;
class IClientUnknown;

enum DataUpdateType_t
{
	DATA_UPDATE_CREATED = 0,
	DATA_UPDATE_DATATABLE_CHANGED,
};

enum ShouldTransmitState_t
{
	SHOULDTRANSMIT_START = 0,
	SHOULDTRANSMIT_END
};

class IClientNetworkable
{
public:
	virtual IClientUnknown*	GetIClientUnknown() = 0;
	virtual void			Release() = 0;
	virtual ClientClass*	GetClientClass() = 0;
	virtual void			NotifyShouldTransmit(ShouldTransmitState_t state) = 0;
	virtual void			OnPreDataChanged(DataUpdateType_t updateType) = 0;
	virtual void			OnDataChanged(DataUpdateType_t updateType) = 0;
	virtual void			PreDataUpdate(DataUpdateType_t updateType) = 0;
	virtual void			PostDataUpdate(DataUpdateType_t updateType) = 0;
	virtual bool			IsDormant(void) = 0;
	virtual int				entindex(void) const = 0;
	virtual void			ReceiveMessage(int classID, bf_read &msg) = 0;
	virtual void*			GetDataTableBasePtr() = 0;
	virtual void			SetDestroyedOnRecreateEntities(void) = 0;
};

#endif