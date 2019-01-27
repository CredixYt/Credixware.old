// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef CGLOWOBJECTMANAGER_H
#define CGLOWOBJECTMANAGER_H

class C_BaseEntity;
class CViewSetup;
class CMatRenderContextPtr;

static const int GLOW_FOR_ALL_SPLIT_SCREEN_SLOTS = -1;

#include "C_BaseEntity.h"
#include "CViewSetup.h"

class CGlowObjectManager
{
public:
	int RegisterGlowObject(C_BaseEntity *pEntity, const Vector &vGlowColor, float flGlowAlpha, bool bRenderWhenOccluded, bool bRenderWhenUnoccluded, int nSplitScreenSlot) {
		typedef int(__thiscall* Fn)(void*, C_BaseEntity*, const Vector&, float, bool, bool, int);
		return Utils::GetVFunc<Fn>(this, 0)(this, pEntity, vGlowColor, flGlowAlpha, bRenderWhenOccluded, bRenderWhenUnoccluded, nSplitScreenSlot);
	}
	void UnregisterGlowObject(int nGlowObjectHandle) {
		typedef void(__thiscall* Fn)(void*, int);
		return Utils::GetVFunc<Fn>(this, 1)(this, nGlowObjectHandle);
	}
	void SetEntity(int nGlowObjectHandle, C_BaseEntity *pEntity) {
		typedef void(__thiscall* Fn)(void*, int, C_BaseEntity*);
		return Utils::GetVFunc<Fn>(this, 2)(this, nGlowObjectHandle, pEntity);
	}
	void SetColor(int nGlowObjectHandle, const Vector &vGlowColor) {
		typedef void(__thiscall* Fn)(void*, int, const Vector&);
		return Utils::GetVFunc<Fn>(this, 3)(this, nGlowObjectHandle, vGlowColor);
	}
	void SetAlpha(int nGlowObjectHandle, float flAlpha) {
		typedef void(__thiscall* Fn)(void*, int, float);
		return Utils::GetVFunc<Fn>(this, 4)(this, nGlowObjectHandle, flAlpha);
	}
	void SetRenderFlags(int nGlowObjectHandle, bool bRenderWhenOccluded, bool bRenderWhenUnoccluded) {
		typedef void(__thiscall* Fn)(void*, int, bool, bool);
		return Utils::GetVFunc<Fn>(this, 5)(this, nGlowObjectHandle, bRenderWhenOccluded, bRenderWhenUnoccluded);
	}
	bool IsRenderingWhenOccluded(int nGlowObjectHandle) {
		typedef bool(__thiscall* Fn)(void*, int);
		return Utils::GetVFunc<Fn>(this, 6)(this, nGlowObjectHandle);
	}
	bool IsRenderingWhenUnoccluded(int nGlowObjectHandle) {
		typedef bool(__thiscall* Fn)(void*, int);
		return Utils::GetVFunc<Fn>(this, 7)(this, nGlowObjectHandle);
	}
	bool HasGlowEffect(C_BaseEntity *pEntity) {
		typedef bool(__thiscall* Fn)(void*, C_BaseEntity*);
		return Utils::GetVFunc<Fn>(this, 8)(this, pEntity);
	}
	virtual void RenderGlowEffects(const CViewSetup *pSetup, int nSplitScreenSlot) = 0;
private:
	void RenderGlowModels(const CViewSetup *pSetup, int nSplitScreenSlot, CMatRenderContextPtr &pRenderContext);
	void ApplyEntityGlowEffects(const CViewSetup *pSetup, int nSplitScreenSlot, CMatRenderContextPtr &pRenderContext, float flBloomScale, int x, int y, int w, int h);
	struct GlowObjectDefinition_t
	{
		bool ShouldDraw(int nSlot) const;
		bool IsUnused() const;
		void DrawModel();
		void* m_hEntity;
		Vector m_vGlowColor;
		float m_flGlowAlpha;
		bool m_bRenderWhenOccluded;
		bool m_bRenderWhenUnoccluded;
		int m_nSplitScreenSlot;
		int m_nNextFreeSlot;
		static const int END_OF_FREE_LIST = -1;
		static const int ENTRY_IN_USE = -2;
	};
	CUtlVector< GlowObjectDefinition_t > m_GlowObjectDefinitions;
	int m_nFirstFreeSlot;
};


#endif