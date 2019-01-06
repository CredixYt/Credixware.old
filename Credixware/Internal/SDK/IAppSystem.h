// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef IAPPSYSTEM_H
#define IAPPSYSTEM_H

#include "Interface.h"

enum InitReturnVal_t
{
	INIT_FAILED = 0,
	INIT_OK,
	INIT_LAST_VAL,
};

class IAppSystem
{
public:
	virtual bool Connect(CreateInterfaceFn factory) = 0;
	virtual void Disconnect() = 0;
	virtual void *QueryInterface(const char *pInterfaceName) = 0;
	virtual InitReturnVal_t Init() = 0;
	virtual void Shutdown() = 0;
};

#endif