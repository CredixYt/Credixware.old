// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef IGAMEEVENT_H
#define IGAMEEVENT_H

class IGameEvent
{
public:
	virtual ~IGameEvent() {};
	const char* GetName() {
		typedef const char*(__thiscall* Fn)(void*);
		return Utils::GetVFunc<Fn>(this, 1)(this);
	}
	virtual bool  IsReliable() const = 0; 
	virtual bool  IsLocal() const = 0;
	bool IsEmpty(const char *keyName = NULL) {
		typedef bool(__thiscall* Fn)(void*, const char *);
		return Utils::GetVFunc<Fn>(this, 4)(this, keyName);
	}
	bool GetBool(const char *keyName = NULL, bool defaultValue = false) {
		typedef bool(__thiscall* Fn)(void*, const char *, bool);
		return Utils::GetVFunc<Fn>(this, 5)(this, keyName, defaultValue);
	}
	int GetInt(const char *keyName = NULL, int defaultValue = 0) {
		typedef int(__thiscall* Fn)(void*, const char *, int);
		return Utils::GetVFunc<Fn>(this, 6)(this, keyName, defaultValue);
	}
	float GetFloat(const char *keyName = NULL, float defaultValue = 0.0f) {
		typedef float(__thiscall* Fn)(void*, const char *, float);
		return Utils::GetVFunc<Fn>(this, 7)(this, keyName, defaultValue);
	}
	const char* GetString(const char *keyName = NULL, const char *defaultValue = "") {
		typedef const char*(__thiscall* Fn)(void*, const char *, const char*);
		return Utils::GetVFunc<Fn>(this, 8)(this, keyName, defaultValue);
	}
	virtual void SetBool(const char *keyName, bool value) = 0;
	virtual void SetInt(const char *keyName, int value) = 0;
	virtual void SetFloat(const char *keyName, float value) = 0;
	virtual void SetString(const char *keyName, const char *value) = 0;
};

#endif