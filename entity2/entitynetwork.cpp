#include "entityidentity.h"
#include "entityinstance.h"
#include "entityclass.h"
#include "entitynetwork.h"
#include "server_class.h"
#include "kv3lib/kv3transfer.h"

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

void CNetworkTransmitComponent::KV3TransferSave( CKV3TransferSaveContext *pContext ) const
{
	KV3TransferSave_CNetworkTransmitComponent( pContext );
}

void CNetworkTransmitComponent::KV3TransferLoad( CKV3TransferLoadContext *pContext )
{
	KV3TransferLoad_CNetworkTransmitComponent( pContext );
}

void CNetworkTransmitComponent::KV3TransferSave_CNetworkTransmitComponent( CKV3TransferSaveContext *pContext ) const
{
	// Saved as a uint32
	if ( pContext->ShouldSaveField( false ) )
		pContext->SaveValueToMember( "m_nTransmitStateOwnedCounter", static_cast< uint32 >( m_nTransmitStateOwnedCounter ) );
}

void CNetworkTransmitComponent::KV3TransferLoad_CNetworkTransmitComponent( CKV3TransferLoadContext *pContext )
{
	pContext->LoadSchemaField( "m_nTransmitStateOwnedCounter", m_nTransmitStateOwnedCounter, static_cast< uint8 >( 0 ) );
}
