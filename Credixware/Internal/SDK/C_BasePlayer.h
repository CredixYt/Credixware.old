// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef C_BASEPLAYER_H
#define C_BASEPLAYER_H

#define IN_ATTACK				(1 << 0)
#define IN_JUMP					(1 << 1)
#define IN_DUCK					(1 << 2)
#define IN_FORWARD				(1 << 3)
#define IN_BACK					(1 << 4)
#define IN_USE					(1 << 5)
#define IN_CANCEL				(1 << 6)
#define IN_LEFT					(1 << 7)
#define IN_RIGHT				(1 << 8)
#define IN_MOVELEFT				(1 << 9)
#define IN_MOVERIGHT			(1 << 10)
#define IN_ATTACK2				(1 << 11)
#define IN_RUN					(1 << 12)
#define IN_RELOAD				(1 << 13)
#define IN_ALT1					(1 << 14)
#define IN_ALT2					(1 << 15)
#define IN_SCORE				(1 << 16)
#define IN_SPEED				(1 << 17)
#define IN_WALK					(1 << 18)
#define IN_ZOOM					(1 << 19)
#define IN_WEAPON1				(1 << 20)
#define IN_WEAPON2				(1 << 21)
#define IN_BULLRUSH				(1 << 22)
#define	FL_ONGROUND				(1 << 0)
#define FL_DUCKING				(1 << 1)
#define	FL_WATERJUMP			(1 << 3)
#define FL_ONTRAIN				(1 << 4)
#define FL_INRAIN				(1 << 5)
#define FL_FROZEN				(1 << 6)
#define FL_ATCONTROLS			(1 << 7)
#define	FL_CLIENT				(1 << 8)
#define FL_FAKECLIENT			(1 << 9)
#define	FL_INWATER				(1 << 10)
#define FL_HIDEHUD_SCOPE		(1 << 11)

class C_BasePlayer
{
public:
	C_BasePlayer();
	virtual			~C_BasePlayer();
	virtual void	Spawn(void);
	virtual void	SharedSpawn();
	virtual bool	GetSteamID(void *pID);
	virtual void	OnPreDataChanged(DataUpdateType_t updateType);
	virtual void	OnDataChanged(DataUpdateType_t updateType);
	virtual void	PreDataUpdate(DataUpdateType_t updateType);
	virtual void	PostDataUpdate(DataUpdateType_t updateType);
	virtual void	ReceiveMessage(int classID, bf_read &msg);
	virtual void	OnRestore();
	virtual void	AddEntity(void);
	virtual void	MakeTracer(const Vector &vecTracerSrc, const trace_t &tr, int iTracerType);
	virtual void	GetToolRecordingState(KeyValues *msg);
	float			GetPlayerMaxSpeed() {
		typedef float(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 13)(this);
	}
	void			SetAnimationExtension(const char *pExtension);
	C_BaseViewModel	*GetViewModel(int viewmodelindex = 0, bool bObserverOK = true) {
		typedef C_BaseViewModel*(__thiscall* Fn)(void*, int, bool);
		return Utils::GetVFunc<Fn>(this, 14)(this, viewmodelindex, bObserverOK);
	}
};


#endif