// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef CONVAR_H
#define CONVAR_H

#include "IAppSystem.h"

class IConVar;
typedef void(*FnChangeCallback_t)(IConVar *var, const char *pOldValue, float flOldValue);

class ConVar;
class CCommand;
class ConCommand;
class ConCommandBase;
class CVarDLLIdentifier_t;
struct characterset_t;

class IConCommandBaseAccessor
{
public:
	virtual bool RegisterConCommandBase(ConCommandBase *pVar) = 0;
};

class ConCommandBase
{
	friend class CCvar;
	friend class ConVar;
	friend class ConCommand;
	friend void ConVar_Register(int nCVarFlag, IConCommandBaseAccessor *pAccessor);
	friend void ConVar_PublishToVXConsole();
	friend class CDefaultCvar;
public:
	ConCommandBase(void);
	ConCommandBase(const char *pName, const char *pHelpString = 0, int flags = 0);
	virtual						~ConCommandBase(void);
	virtual	bool				IsCommand(void) const;
	virtual bool				IsFlagSet(int flag) const;
	virtual void				AddFlags(int flags);
	virtual const char			*GetName(void) const;
	virtual const char			*GetHelpText(void) const;
	const ConCommandBase		*GetNext(void) const;
	ConCommandBase				*GetNext(void);
	virtual bool				IsRegistered(void) const;
	virtual CVarDLLIdentifier_t	GetDLLIdentifier() const;
protected:
	virtual void				CreateBase(const char *pName, const char *pHelpString = 0, int flags = 0);
	virtual void				Init();
	void						Shutdown();
	char						*CopyString(const char *from);
private:
	ConCommandBase				*m_pNext;
	bool						m_bRegistered;
	const char 					*m_pszName;
	const char 					*m_pszHelpString;
	int							m_nFlags;
protected:
	static ConCommandBase		*s_pConCommandBases;
	static IConCommandBaseAccessor	*s_pAccessor;
};

class IConVar
{
public:
	const char* GetString()
	{
		typedef const char*(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 11)(this);
	}
	float GetFloat()
	{
		typedef float(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 12)(this);
	}
	int GetInt()
	{
		typedef int(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 13)(this);
	}

	void SetValue(const char *pValue) {
		typedef void(__thiscall* Fn)(void*, const char*);
		return Utils::GetVFunc<Fn>(this, 15)(this, pValue);
	}
	void SetValue(float flValue) {
		typedef void(__thiscall* Fn)(void*, float);
		return Utils::GetVFunc<Fn>(this, 16)(this, flValue);
	}
	void SetValue(int nValue) {
		typedef void(__thiscall* Fn)(void*, int);
		return Utils::GetVFunc<Fn>(this, 19)(this, nValue);
	}
	virtual const char *GetName(void) const = 0;
	virtual bool IsFlagSet(int nFlag) const = 0;
};

class ConVar : public ConCommandBase, public IConVar
{
	friend class CCvar;
	friend class ConVarRef;
public:
	typedef ConCommandBase BaseClass;
	ConVar(const char *pName, const char *pDefaultValue, int flags = 0);
	ConVar(const char *pName, const char *pDefaultValue, int flags, const char *pHelpString);
	ConVar(const char *pName, const char *pDefaultValue, int flags, const char *pHelpString, bool bMin, float fMin, bool bMax, float fMax);
	ConVar(const char *pName, const char *pDefaultValue, int flags, const char *pHelpString, FnChangeCallback_t callback);
	ConVar(const char *pName, const char *pDefaultValue, int flags, const char *pHelpString, bool bMin, float fMin, bool bMax, float fMax, FnChangeCallback_t callback);
	virtual						~ConVar(void);
	virtual bool				IsFlagSet(int flag) const;
	virtual const char*			GetHelpText(void) const;
	virtual bool				IsRegistered(void) const;
	virtual const char*			GetName(void) const;
	virtual void				AddFlags(int flags);
	virtual	bool				IsCommand(void) const;
	void						InstallChangeCallback(FnChangeCallback_t callback);
	float						GetFloat(void) {
		typedef float(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 13)(this);
	}
	inline int					GetInt(void) const;
	inline bool					GetBool() const { return !!GetInt(); }
	inline char const*			GetString(void) const;
	virtual void				SetValue(const char *value);
	void						SetValue(float value) {
		typedef void(__thiscall* Fn)(void*, float);
		return Utils::GetVFunc<Fn>(this, 15)(this, value);
	}
	void						SetValue(int value) {
		typedef void(__thiscall* Fn)(void*, int);
		return Utils::GetVFunc<Fn>(this, 16)(this, value);
	}
	void						Revert(void);
	bool						GetMin(float& minVal) const;
	bool						GetMax(float& maxVal) const;
	const char*					GetDefault(void) const;
	void						SetDefault(const char *pszDefault);
private:
	virtual void				InternalSetValue(const char *value);
	virtual void				InternalSetFloatValue(float fNewValue);
	virtual void				InternalSetIntValue(int nValue);
	virtual bool				ClampValue(float& value);
	virtual void				ChangeStringValue(const char *tempVal, float flOldValue);
	virtual void				Create(const char *pName, const char *pDefaultValue, int flags = 0, const char *pHelpString = 0, bool bMin = false, float fMin = 0.0, bool bMax = false, float fMax = false, FnChangeCallback_t callback = 0);
	virtual void				Init();
	int GetFlags() { return m_pParent->m_nFlags; }
private:
	ConVar						*m_pParent;
	const char					*m_pszDefaultValue;
	char						*m_pszString;
	int							m_StringLength;
	float						m_fValue;
	int							m_nValue;
	bool						m_bHasMin;
	float						m_fMinVal;
	bool						m_bHasMax;
	float						m_fMaxVal;
	FnChangeCallback_t			m_fnChangeCallback;
};

class IConsoleDisplayFunc;
class ICvarQuery;

class ICvar : public IAppSystem
{
public:
	virtual CVarDLLIdentifier_t AllocateDLLIdentifier() = 0;						// 0
	virtual void			RegisterConCommand(ConCommandBase *pCommandBase) = 0;	// 1
	virtual void			UnregisterConCommand(ConCommandBase *pCommandBase) = 0;	// 2
	virtual void			UnregisterConCommands(CVarDLLIdentifier_t id) = 0;		// 3
	virtual const char*		GetCommandLineValue(const char *pVariableName) = 0;		// 4
	virtual ConCommandBase *FindCommandBase(const char *name) = 0;					// 5
	virtual const ConCommandBase *FindCommandBase(const char *name) const = 0;		// 6
	ConVar*					FindVar(const char *var_name) {
		typedef ConVar*(__thiscall* Fn)(void*, const char*);
		return Utils::GetVFunc<Fn>(this, 16)(this, var_name);
	}
	virtual const ConVar	*FindVar(const char *var_name) const = 0;				// 8
	virtual ConCommand		*FindCommand(const char *name) = 0;
	virtual const ConCommand *FindCommand(const char *name) const = 0;
	virtual ConCommandBase	*GetCommands(void) = 0;
	virtual const ConCommandBase *GetCommands(void) const = 0;
	virtual void			InstallGlobalChangeCallback(FnChangeCallback_t callback) = 0;
	virtual void			RemoveGlobalChangeCallback(FnChangeCallback_t callback) = 0;
	virtual void			CallGlobalChangeCallbacks(ConVar *var, const char *pOldString, float flOldValue) = 0;

	// Install a console printer
	virtual void			InstallConsoleDisplayFunc(IConsoleDisplayFunc* pDisplayFunc) = 0;
	virtual void			RemoveConsoleDisplayFunc(IConsoleDisplayFunc* pDisplayFunc) = 0;
	virtual void			ConsoleColorPrintf(const Color& clr, const char *pFormat, ...) const = 0;
	virtual void			ConsolePrintf(const char *pFormat, ...) const = 0;
	virtual void			ConsoleDPrintf(const char *pFormat, ...) const = 0;
	virtual void			RevertFlaggedConVars(int nFlag) = 0;
	virtual void			InstallCVarQuery(ICvarQuery *pQuery) = 0;
	virtual bool			IsMaterialThreadSetAllowed() const = 0;
	virtual void			QueueMaterialThreadSetValue(ConVar *pConVar, const char *pValue) = 0;
	virtual void			QueueMaterialThreadSetValue(ConVar *pConVar, int nValue) = 0;
	virtual void			QueueMaterialThreadSetValue(ConVar *pConVar, float flValue) = 0;
	virtual bool			HasQueuedMaterialThreadConVarSets() const = 0;
	virtual int				ProcessQueuedMaterialThreadConVarSets() = 0;

protected:	class ICVarIteratorInternal;
public:
	class Iterator
	{
	public:
		inline Iterator(ICvar *icvar);
		inline ~Iterator(void);
		inline void		SetFirst(void);
		inline void		Next(void);
		inline bool		IsValid(void);
		inline ConCommandBase *Get(void);
	private:
		ICVarIteratorInternal *m_pIter;
	};

protected:
	class ICVarIteratorInternal
	{
	public:
		virtual ~ICVarIteratorInternal() {}
		virtual void		SetFirst(void) = 0;
		virtual void		Next(void) = 0;
		virtual	bool		IsValid(void) = 0;
		virtual ConCommandBase *Get(void) = 0;
	};

	virtual ICVarIteratorInternal	*FactoryInternalIterator(void) = 0;
	friend class Iterator;
};

#endif