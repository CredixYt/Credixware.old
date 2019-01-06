// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef INTERFACE_H
#define INTERFACE_H

typedef void* (*CreateInterfaceFn)(const char *pName, int *pReturnCode);
typedef void* (*InstantiateInterfaceFn)();

class IBaseInterface
{
public:
	virtual	~IBaseInterface() {}
};

#endif