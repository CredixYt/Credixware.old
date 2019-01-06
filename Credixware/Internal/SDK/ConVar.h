// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef CONVAR_H
#define CONVAR_H

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
	virtual void SetValue(const char *pValue) = 0;
	virtual void SetValue(float flValue) = 0;
	virtual void SetValue(int nValue) = 0;
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
	inline float				GetFloat(void) const;
	inline int					GetInt(void) const;
	inline bool					GetBool() const { return !!GetInt(); }
	inline char const*			GetString(void) const;
	virtual void				SetValue(const char *value);
	virtual void				SetValue(float value);
	virtual void				SetValue(int value);
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

#endif