#include "entityinstance.h"
#include "entityclass.h"
#include "server_class.h"

CGameNetworkableClass *CEntityInstance::GetNetworkableClass() const
{
	if ( !m_pEntity || !m_pEntity->m_pClass )
		return nullptr;

	return m_pEntity->m_pClass->m_pServerClass;
}

int CEntityInstance::GetClassID() const
{
	CGameNetworkableClass *pClass = GetNetworkableClass();
	return pClass ? pClass->m_ClassID : -1;
}
