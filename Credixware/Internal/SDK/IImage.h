// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef IIMAGE_H
#define IIMAGE_H

#include "basetypes.h"
#include "Color.h"

typedef unsigned long HTexture;
typedef uint32 RTime32;

class IImage
{
public:
	virtual void Paint() = 0;
	virtual void SetPos(int x, int y) = 0;
	virtual void GetContentSize(int &wide, int &tall) = 0;
	virtual void GetSize(int &wide, int &tall) = 0;
	virtual void SetSize(int wide, int tall) = 0;
	virtual void SetColor(Color col) = 0;
	virtual ~IImage() {}
	virtual bool Evict() = 0;
	virtual int GetNumFrames() = 0;
	virtual void SetFrame(int nFrame) = 0;
	virtual HTexture GetID() = 0;
	virtual void SetRotation(int iRotation) = 0;
};

#endif