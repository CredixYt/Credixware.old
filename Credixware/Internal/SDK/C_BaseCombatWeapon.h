// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef C_BASECOMBATWEAPON_H
#define C_BASECOMBATWEAPON_H

#include "math/vector.h"
#include "CInput.h"
#include "IClientRenderable.h"
#include "IClientNetworkable.h"

class C_BaseViewModel;
class CBaseCombatCharacter;
class CBasePlayer;
class CBaseEntity;
class CBaseViewModel;
class Activity;
class FileWeaponInfo_t;
class CHudTexture;
class KeyValues;
struct WeaponSound_t;
struct acttable_t;
struct poseparamtable_t;
struct constraint_breakableparams_t;
struct trace_t;

class EHANDLE {

};

typedef unsigned short WEAPON_FILE_INFO_HANDLE;

enum WeaponProficiency_t
{
	WEAPON_PROFICIENCY_POOR = 0,
	WEAPON_PROFICIENCY_AVERAGE,
	WEAPON_PROFICIENCY_GOOD,
	WEAPON_PROFICIENCY_VERY_GOOD,
	WEAPON_PROFICIENCY_PERFECT,
};

struct WeaponProficiencyInfo_t
{
	float	spreadscale;
	float	bias;
};

class IPhysicsConstraint
{
public:
	virtual					~IPhysicsConstraint(void) {}
	virtual void			Activate(void) = 0;
	virtual void			Deactivate(void) = 0;
	virtual void			SetGameData(void *gameData) = 0;
	virtual void			*GetGameData(void) const = 0;
	virtual void 			*GetReferenceObject(void) const = 0;
	virtual void			*GetAttachedObject(void) const = 0;
	virtual void			SetLinearMotor(float speed, float maxLinearImpulse) = 0;
	virtual void			SetAngularMotor(float rotSpeed, float maxAngularImpulse) = 0;
	virtual void			UpdateRagdollTransforms(const matrix3x4_t &constraintToReference, const matrix3x4_t &constraintToAttached) = 0;
	virtual bool			GetConstraintTransform(matrix3x4_t *pConstraintToReference, matrix3x4_t *pConstraintToAttached) const = 0;
	virtual bool			GetConstraintParams(constraint_breakableparams_t *pParams) const = 0;
	virtual void			OutputDebugInfo() = 0;
};

class CBaseCombatWeapon
{
public:
	CBaseCombatWeapon();
	virtual 				~CBaseCombatWeapon();
	virtual bool			IsBaseCombatWeapon(void) const { return true; }
	virtual CBaseCombatWeapon *MyCombatWeaponPointer(void) { return this; }
	virtual bool			IsPredicted(void) const { return false; }
	virtual void			Spawn(void);
	virtual void			Precache(void);
	void					MakeTracer(const Vector &vecTracerSrc, const trace_t &tr, int iTracerType);
	virtual int				GetSubType(void) { return m_iSubType; }
	virtual void			SetSubType(int iType) { m_iSubType = iType; }
	virtual void			Equip(CBaseCombatCharacter *pOwner);
	virtual void			Drop(const Vector &vecVelocity);
	virtual	int				UpdateClientData(CBasePlayer *pPlayer);
	virtual bool			IsAllowedToSwitch(void);
	virtual bool			CanBeSelected(void);
	virtual bool			VisibleInWeaponSelection(void);
	virtual bool			HasAmmo(void);
	virtual void			SetPickupTouch(void);
	virtual void 			DefaultTouch(CBaseEntity *pOther);
	virtual void			GiveTo(CBaseEntity *pOther);
	virtual bool			ShouldDisplayAltFireHUDHint();
	virtual void			DisplayAltFireHudHint();
	virtual void			RescindAltFireHudHint();
	virtual bool			ShouldDisplayReloadHUDHint();
	virtual void			DisplayReloadHudHint();
	virtual void			RescindReloadHudHint();
	virtual void			SetViewModelIndex(int index = 0);
	virtual bool			SendWeaponAnim(int iActivity);
	virtual void			SendViewModelAnim(int nSequence);
	float					GetViewModelSequenceDuration();
	bool					IsViewModelSequenceFinished(void) const;
	virtual void			SetViewModel();
	virtual bool			HasWeaponIdleTimeElapsed(void);
	virtual void			SetWeaponIdleTime(float time);
	virtual float			GetWeaponIdleTime(void);
	virtual bool			HasAnyAmmo(void);
	virtual bool			HasPrimaryAmmo(void);
	virtual bool			HasSecondaryAmmo(void);
	bool					UsesPrimaryAmmo(void);
	bool					UsesSecondaryAmmo(void);
	void					GiveDefaultAmmo(void);
	virtual bool			CanHolster(void) const { return TRUE; };
	virtual bool			DefaultDeploy(char *szViewModel, char *szWeaponModel, int iActivity, char *szAnimExt);
	virtual bool			CanDeploy(void) { return true; }
	virtual bool			Deploy(void);
	virtual bool			Holster(CBaseCombatWeapon *pSwitchingTo = NULL);
	virtual CBaseCombatWeapon *GetLastWeapon(void) { return this; }
	virtual void			SetWeaponVisible(bool visible);
	virtual bool			IsWeaponVisible(void);
	virtual bool			ReloadOrSwitchWeapons(void);
	virtual void			OnActiveStateChanged(int iOldState) { return; }
	virtual bool			HolsterOnDetach() { return false; }
	virtual bool			IsHolstered() { return false; }
	virtual void			Detach() {}
	virtual void			ItemPreFrame(void);
	virtual void			ItemPostFrame(void);
	virtual void			ItemBusyFrame(void);
	virtual void			ItemHolsterFrame(void) {};
	virtual void			WeaponIdle(void);
	virtual void			HandleFireOnEmpty();				
	virtual bool			CanPerformSecondaryAttack() const;
	virtual bool			ShouldBlockPrimaryFire() { return false; }
	virtual bool			IsWeaponZoomed() { return false; }
	virtual	void			CheckReload(void);
	virtual void			FinishReload(void);
	virtual void			AbortReload(void);
	virtual bool			Reload(void);
	bool					DefaultReload(int iClipSize1, int iClipSize2, int iActivity);
	bool					ReloadsSingly(void) const;
	virtual bool			AutoFiresFullClip(void) const { return false; }
	virtual void			UpdateAutoFire(void);
	virtual void			PrimaryAttack(void);
	virtual void			SecondaryAttack(void) { return; }
	virtual Activity		GetPrimaryAttackActivity(void);
	virtual Activity		GetSecondaryAttackActivity(void);
	virtual Activity		GetDrawActivity(void);
	virtual float			GetDefaultAnimSpeed(void) { return 1.0; }
	virtual int				GetBulletType(void);
	virtual const Vector&	GetBulletSpread(void);
	virtual Vector			GetBulletSpread(WeaponProficiency_t proficiency) { return GetBulletSpread(); }
	virtual float			GetSpreadBias(WeaponProficiency_t proficiency) { return 1.0; }
	virtual float			GetFireRate(void);
	virtual int				GetMinBurst() { return 1; }
	virtual int				GetMaxBurst() { return 1; }
	virtual float			GetMinRestTime();
	virtual float			GetMaxRestTime();
	virtual int				GetRandomBurst();
	virtual void			WeaponSound(WeaponSound_t sound_type, float soundtime = 0.0f);
	virtual void			StopWeaponSound(WeaponSound_t sound_type);
	virtual const WeaponProficiencyInfo_t *GetProficiencyValues();
	virtual float			GetMaxAutoAimDeflection() { return 0.99f; }
	virtual float			WeaponAutoAimScale() { return 1.0f; }
	virtual bool			StartSprinting(void) { return false; };
	virtual bool			StopSprinting(void) { return false; };
	virtual float			GetDamage(float flDistance, int iLocation) { return 0.0; };
	virtual void			SetActivity(Activity act, float duration);
	inline void				SetActivity(Activity eActivity);
	inline Activity			GetActivity(void) const;
	virtual void			AddViewKick(void);
	virtual char			*GetDeathNoticeName(void);
	CBaseCombatCharacter	*GetOwner() const;
	void					SetOwner(CBaseCombatCharacter *owner);
	virtual void			OnPickedUp(CBaseCombatCharacter *pNewOwner);
	virtual void			AddViewmodelBob(CBaseViewModel *viewmodel, Vector &origin, QAngle &angles) {};
	virtual float			CalcViewmodelBob(void) { return 0.0f; };
	virtual void 			GetControlPanelInfo(int nPanelIndex, const char *&pPanelName);
	virtual void			GetControlPanelClassName(int nPanelIndex, const char *&pPanelName);
	virtual bool			ShouldShowControlPanels(void) { return true; }
	void					Lock(float lockTime, CBaseEntity *pLocker);
	bool					IsLocked(CBaseEntity *pAsker);
	virtual bool			CanBePickedUpByNPCs(void) { return true; }
	virtual int				GetSkinOverride() const { return -1; }
public:
	const FileWeaponInfo_t	&GetWpnData(void) const;
	virtual const char		*GetViewModel(int viewmodelindex = 0) const;
	virtual const char		*GetWorldModel(void) const;
	virtual const char		*GetAnimPrefix(void) const;
	virtual int				GetMaxClip1(void) const;
	virtual int				GetMaxClip2(void) const;
	virtual int				GetDefaultClip1(void) const;
	virtual int				GetDefaultClip2(void) const;
	virtual int				GetWeight(void) const;
	virtual bool			AllowsAutoSwitchTo(void) const;
	virtual bool			AllowsAutoSwitchFrom(void) const;
	virtual bool			ForceWeaponSwitch(void) const { return false; }
	virtual int				GetWeaponFlags(void) const;
	virtual int				GetSlot(void) const;
	virtual int				GetPosition(void) const;
	virtual char const		*GetName(void) const;
	virtual char const		*GetPrintName(void) const;
	virtual char const		*GetShootSound(int iIndex) const;
	virtual int				GetRumbleEffect() const;
	virtual bool			UsesClipsForAmmo1(void) const;
	virtual bool			UsesClipsForAmmo2(void) const;
	bool					IsMeleeWeapon() const;
	virtual const unsigned char *GetEncryptionKey(void);
	virtual int				GetPrimaryAmmoType(void)  const;
	virtual int				GetSecondaryAmmoType(void)  const;
	virtual int				Clip1() { return m_iClip1; }
	virtual int				Clip2() { return m_iClip2; }
	int GetPrimaryAmmoCount();
	void SetPrimaryAmmoCount(int count);
	int GetSecondaryAmmoCount();
	void SetSecondaryAmmoCount(int count);
	virtual CHudTexture const	*GetSpriteActive(void) const;
	virtual CHudTexture const	*GetSpriteInactive(void) const;
	virtual CHudTexture const	*GetSpriteAmmo(void) const;
	virtual CHudTexture const	*GetSpriteAmmo2(void) const;
	virtual CHudTexture const	*GetSpriteCrosshair(void) const;
	virtual CHudTexture const	*GetSpriteAutoaim(void) const;
	virtual CHudTexture const	*GetSpriteZoomedCrosshair(void) const;
	virtual CHudTexture const	*GetSpriteZoomedAutoaim(void) const;
	virtual Activity		ActivityOverride(Activity baseAct, bool *pRequired);
	virtual	acttable_t*		ActivityList(int &iActivityCount) { return NULL; }
	virtual void			PoseParameterOverride(bool bReset);
	virtual poseparamtable_t* PoseParamList(int &iPoseParamCount) { return NULL; }
	virtual void			Activate(void);
	virtual bool ShouldUseLargeViewModelVROverride() { return false; }
public:
	virtual void			BoneMergeFastCullBloat(Vector &localMins, Vector &localMaxs, const Vector &thisEntityMins, const Vector &thisEntityMaxs) const;

	virtual bool			OnFireEvent(C_BaseViewModel *pViewModel, const Vector& origin, const QAngle& angles, int event, const char *options)
	{
		return false;
	}
	virtual ShadowType_t	ShadowCastType();
	virtual void			SetDormant(bool bDormant);
	virtual void			OnDataChanged(DataUpdateType_t updateType);
	virtual void			OnRestore();
	virtual void			RestartParticleEffect(void) {}
	virtual void			Redraw(void);
	virtual void			ViewModelDrawn(CBaseViewModel *pViewModel);
	bool					GetShootPosition(Vector &vOrigin, QAngle &vAngles);
	virtual void			DrawCrosshair(void);
	virtual bool			ShouldDrawCrosshair(void) { return true; }
	virtual bool			IsCarriedByLocalPlayer(void);
	virtual bool			ShouldDrawUsingViewModel(void);
	virtual bool			IsActiveByLocalPlayer(void);
	bool					IsBeingCarried() const;
	bool					IsCarrierAlive() const;
	virtual int				DrawModel(int flags);
	virtual bool			ShouldDraw(void);
	virtual bool			ShouldDrawPickup(void);
	virtual void			HandleInput(void) { return; };
	virtual void			OverrideMouseInput(float *x, float *y) { return; };
	virtual int				KeyInput(int down, ButtonCode_t keynum, const char *pszCurrentBinding) { return 1; }
	virtual bool			AddLookShift(void) { return true; };
	virtual void			GetViewmodelBoneControllers(C_BaseViewModel *pViewModel, float controllers[4]) { return; }
	virtual void			NotifyShouldTransmit(ShouldTransmitState_t state);
	WEAPON_FILE_INFO_HANDLE	GetWeaponFileInfoHandle();
	virtual int				GetWorldModelIndex(void);
	virtual void			GetToolRecordingState(KeyValues *msg);
	virtual void			GetWeaponCrosshairScale(float &flScale) { flScale = 1.f; }
	virtual bool			ViewModel_IsTransparent(void);
	virtual bool			ViewModel_IsUsingFBTexture(void);
	virtual bool			IsOverridingViewmodel(void) { return false; };
	virtual int				DrawOverriddenViewmodel(C_BaseViewModel *pViewmodel, int flags) { return 0; };
	bool					WantsToOverrideViewmodelAttachments(void);
	virtual bool			CanLower(void) { return false; }
	virtual bool			Ready(void) { return false; }
	virtual bool			Lower(void) { return false; }
	virtual void			HideThink(void);
	virtual bool			CanReload(void);
private:
	typedef CHandle< CBaseCombatCharacter > CBaseCombatCharacterHandle;
	CBaseCombatCharacterHandle				m_hOwner;
public:
	int							m_nViewModelIndex;
	float						m_flNextPrimaryAttack;
	float						m_flNextSecondaryAttack;	
	float						m_flTimeWeaponIdle;		
	bool					m_bInReload;
	bool					m_bFireOnEmpty;
	bool					m_bFiringWholeClip;
	int						m_iViewModelIndex;
	int						m_iWorldModelIndex;
	float					m_flNextEmptySoundTime;
	Activity				GetIdealActivity(void);
	int						GetIdealSequence(void);
	bool					SetIdealActivity(Activity ideal);
	void					MaintainIdealActivity(void);
	int						WeaponState() const { return m_iState; }
	int						m_iState;
	const char*				m_iszName;
	int						m_iPrimaryAmmoType;
	int						m_iSecondaryAmmoType;
	int						m_iClip1;
	int						m_iClip2;
	bool					m_bFiresUnderwater;	
	bool					m_bAltFiresUnderwater;
	float					m_fMinRange1;
	float					m_fMinRange2;
	float					m_fMaxRange1;
	float					m_fMaxRange2;
	bool					m_bReloadsSingly;
	float					m_fFireDuration;
	int						m_iSubType;
	float					m_flUnlockTime;
	EHANDLE					m_hLocker;
	bool					m_bFlipViewModel;
	IPhysicsConstraint		*GetConstraint();
};

#endif