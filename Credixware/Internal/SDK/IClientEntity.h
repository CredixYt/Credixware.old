// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef ICLIENTENTITY_H
#define ICLIENTENTITY_H

#include "IClientRenderable.h"
#include "IClientNetworkable.h"
#include "IClientThinkable.h"
#include "math/vector.h"

struct SpatializationInfo_t;
class CMouthInfo;
class C_BaseEntity;
class ICollideable;

class IClientEntity : public IClientUnknown, public IClientRenderable, public IClientNetworkable, public IClientThinkable
{
public:
	virtual void			Release(void) = 0;
	virtual const Vector&	GetAbsOrigin(void) const = 0;
	virtual const QAngle&	GetAbsAngles(void) const = 0;
	virtual CMouthInfo		*GetMouth(void) = 0;
	virtual bool			GetSoundSpatialization(SpatializationInfo_t& info) = 0;
};


#endif