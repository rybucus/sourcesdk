#ifndef PANORAMA_UIPANELSTYLE_H
#define PANORAMA_UIPANELSTYLE_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/platform.h>
#include <tier0/utlstring.h>
#include <tier1/utlmap.h>
#include <panorama/iuipanelstyle.h>
#include <panorama/layout/stylesymbol.h>

namespace panorama
{

class IUIPanel;

class CPanelStyle : public IUIPanelStyle
{
public:
	IUIPanel *m_pPanel;
	uint64 m_nHasStyleDataBits[ 3 ];
private:
	uint8 m_pad028[ 0x18 ];
public:
	void *m_pFastProperties;
	int32 m_nFastPropertiesAlloc;
private:
	uint8 m_pad04C[ 0x14 ];
public:
	int32 m_nActiveTransitionCount;
private:
	uint8 m_pad064[ 0x4C ];
};

COMPILE_TIME_ASSERT( sizeof( CPanelStyle ) == 0xB0 );

typedef CUtlMap< CUtlString, CStyleSymbol, int > StylePropertySymbolMap_t;

} // namespace panorama

#endif
