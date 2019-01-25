// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H

#include "IClientNetworkable.h"

typedef IClientNetworkable*	(*CreateClientClassFn)(int entnum, int serialNum);
typedef IClientNetworkable*	(*CreateEventFn)();

class RecvTable;

enum ClientClassType_t {
	CAK47 = 1,
	CCSPLAYER = 38,
	CKNIFE = 105,
	CPREDICTEDVIEWMODEL = 136
};

class ClientClass
{
public:
	ClientClass( const char *pNetworkName, CreateClientClassFn createFn, CreateEventFn createEventFn, RecvTable *pRecvTable )
	{
		m_pNetworkName	= pNetworkName;
		m_pCreateFn		= createFn;
		m_pCreateEventFn= createEventFn;
		m_pRecvTable	= pRecvTable;
	}
	const char* GetName()
	{
		return m_pNetworkName;
	}
public:
	CreateClientClassFn		m_pCreateFn;
	CreateEventFn			m_pCreateEventFn;
	const char				*m_pNetworkName;
	RecvTable				*m_pRecvTable;
	ClientClass				*m_pNext;
	int						m_ClassID;
};

#endif