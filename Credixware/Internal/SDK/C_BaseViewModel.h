// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef C_BASEVIEWMODEL_H
#define C_BASEVIEWMODEL_H

typedef int	string_t;

class CBaseCombatCharacter;

class CBaseEntity {

};

class Activity {

};

class CVGuiScreen {

};

class CBaseViewModel
{
public:
	CBaseViewModel(void);
	~CBaseViewModel(void);
	bool					IsViewable(void);
	virtual void			UpdateOnRemove(void);
	virtual void			SendViewModelMatchingSequence(int sequence);
	void					SetWeaponModel(const char *pszModelname, CBaseCombatWeapon *weapon) {
		typedef void(__thiscall* Fn)(void*, const char*, CBaseCombatWeapon*);
		Utils::GetVFunc<Fn>(this, 3)(this, pszModelname, weapon);
	}
	virtual void			CalcViewModelLag(Vector& origin, QAngle& angles, QAngle& original_angles);
	virtual void			CalcViewModelView(CBasePlayer *owner, const Vector& eyePosition, const QAngle& eyeAngles);
	virtual void			AddViewModelBob(CBasePlayer *owner, Vector& eyePosition, QAngle& eyeAngles) {};							
	void					SetOwner(CBaseEntity *pEntity);
	void					SetIndex(int nIndex);
	int						ViewModelIndex() const;
	virtual void			Precache(void);
	virtual void			Spawn(void);
	virtual CBaseEntity		*GetOwner(void);
	virtual void			AddEffects(int nEffects);
	virtual void			RemoveEffects(int nEffects);
	void					SpawnControlPanels();
	void					DestroyControlPanels();
	void					SetControlPanelsActive(bool bState);
	void					ShowControlPanells(bool show);
	virtual CBaseCombatWeapon *GetOwningWeapon(void);
	virtual CBaseEntity		*GetOwnerViaInterface(void) { return GetOwner(); }
	virtual bool			IsSelfAnimating();
	Vector					m_vecLastFacing;
private:
	int						m_nViewModelIndex;
	CBaseEntity				m_hOwner;
	float					m_flTimeWeaponIdle;
	Activity				m_Activity;
	int						m_nAnimationParity;
	string_t				m_sVMName;
	string_t				m_sAnimationPrefix;
	typedef CHandle< CBaseCombatWeapon > CBaseCombatWeaponHandle;
	CBaseCombatWeaponHandle	m_hWeapon;
	typedef CHandle<CVGuiScreen>	ScreenHandle_t;
	CUtlVector<ScreenHandle_t>	m_hScreens;
};

#endif