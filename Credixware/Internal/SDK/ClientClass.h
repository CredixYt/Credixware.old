// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H

#include "IClientNetworkable.h"

typedef IClientNetworkable*	(*CreateClientClassFn)(int entnum, int serialNum);
typedef IClientNetworkable*	(*CreateEventFn)();

typedef enum
{
	DPT_Int = 0,
	DPT_Float,
	DPT_Vector,
	DPT_VectorXY,
	DPT_String,
	DPT_Array,
	DPT_DataTable,
	DPT_Int64,
	DPT_NUMSendPropTypes

} SendPropType;

class DVariant
{
public:
	DVariant() { m_Type = DPT_Float; }
	DVariant(float val) { m_Type = DPT_Float; m_Float = val; }
	const char *ToString();
	union
	{
		float	m_Float;
		int		m_Int;
		const char	*m_pString;
		void	*m_pData;
		float	m_Vector[3];
	};
	SendPropType	m_Type;
};

class RecvProp;

class CRecvProxyData
{
public:
	const RecvProp	*m_pRecvProp;
	DVariant		m_Value;
	int				m_iElement;
	int				m_ObjectID;
};

class CRecvDecoder;

class RecvTable
{
public:
	typedef RecvProp	PropType;
	RecvTable();
	RecvTable(RecvProp *pProps, int nProps, char *pNetTableName);
	~RecvTable();
	void		Construct(RecvProp *pProps, int nProps, char *pNetTableName);
	int			GetNumProps();
	RecvProp*	GetProp_(int i);
	const char*	GetName();
	void		SetInitialized(bool bInitialized);
	bool		IsInitialized() const;
	void		SetInMainList(bool bInList);
	bool		IsInMainList() const;
public:
	RecvProp		*m_pProps;
	int				m_nProps;
	CRecvDecoder	*m_pDecoder;
	char			*m_pNetTableName;
private:
	bool			m_bInitialized;
	bool			m_bInMainList;
};

typedef void(*RecvVarProxyFn)(const CRecvProxyData *pData, void *pStruct, void *pOut);
typedef void(*ArrayLengthRecvProxyFn)(void *pStruct, int objectID, int currentArrayLength);
typedef void(*DataTableRecvVarProxyFn)(const RecvProp *pProp, void **pOut, void *pData, int objectID);

class RecvProp
{
public:
	RecvProp();
	void					InitArray(int nElements, int elementStride);
	int						GetNumElements() const;
	void					SetNumElements(int nElements);
	int						GetElementStride() const;
	void					SetElementStride(int stride);
	int						GetFlags() const;
	const char*				GetName() const;
	SendPropType			GetType() const;
	RecvTable*				GetDataTable() const;
	void					SetDataTable(RecvTable *pTable);
	RecvVarProxyFn			GetProxyFn() const;
	void					SetProxyFn(RecvVarProxyFn fn);
	DataTableRecvVarProxyFn	GetDataTableProxyFn() const;
	void					SetDataTableProxyFn(DataTableRecvVarProxyFn fn);
	int						GetOffset() const;
	void					SetOffset(int o);
	RecvProp*				GetArrayProp() const;
	void					SetArrayProp(RecvProp *pProp);
	void					SetArrayLengthProxy(ArrayLengthRecvProxyFn proxy);
	ArrayLengthRecvProxyFn	GetArrayLengthProxy() const;
	bool					IsInsideArray() const;
	void					SetInsideArray();
	const void*			GetExtraData() const;
	void				SetExtraData(const void *pData);
	const char*			GetParentArrayPropName();
	void				SetParentArrayPropName(const char *pArrayPropName);
public:
	char					*m_pVarName;
	SendPropType			m_RecvType;
	int						m_Flags;
	int						m_StringBufferSize;
private:
	bool					m_bInsideArray;
	const void *m_pExtraData;
	RecvProp				*m_pArrayProp;
	ArrayLengthRecvProxyFn	m_ArrayLengthProxy;
	RecvVarProxyFn			m_ProxyFn;
	DataTableRecvVarProxyFn	m_DataTableProxyFn;
	RecvTable				*m_pDataTable;
	int						m_Offset;
	int						m_ElementStride;
	int						m_nElements;
	const char				*m_pParentArrayPropName;
};

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