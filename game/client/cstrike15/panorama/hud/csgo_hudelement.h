#ifndef CSGO_HUDELEMENT_H
#define CSGO_HUDELEMENT_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/utlstring.h>
#include <gameeventlistener.h>

class CCSGOHudElement : public CGameEventListener
{
public:
	virtual void unk002() = 0;
	virtual void unk003() = 0;
	virtual void unk004() = 0;
	virtual void unk005() = 0;
	virtual void unk006() = 0;
	virtual void SetActive( bool bActive ) = 0;
	virtual bool IsActive() = 0;
	virtual bool ShouldDraw() = 0;
	virtual bool unk010( void *pUnknown ) = 0;

	bool m_bActive;
private:
	uint8 m_pad011[ 0x3 ];
public:
	int m_iHiddenBits;
private:
	uint8 m_pad018[ 0x20 ];
public:
	CUtlString m_strElementName;
};

COMPILE_TIME_ASSERT( sizeof( CCSGOHudElement ) == 0x40 );

#endif
