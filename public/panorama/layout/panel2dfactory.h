#ifndef PANORAMA_PANEL2DFACTORY_H
#define PANORAMA_PANEL2DFACTORY_H

#ifdef _WIN32
#pragma once
#endif

#include <panorama/panoramasymbol.h>

namespace panorama
{

class CPanel2D;

typedef CPanel2D *( *PANEL2DCREATEFUNC )( const char *pchID, CPanel2D *pParent );
typedef CPanoramaSymbol ( *PANELSYMBOLFUNC )();

struct CPanel2DClassInfo
{
	CPanoramaSymbol m_symbol;
	const char *m_pchName;
	const CPanel2DClassInfo *m_pParentClassInfo;
};

class CPanel2DFactory
{
public:
	PANELSYMBOLFUNC m_funcSymParent;
	PANEL2DCREATEFUNC m_funcCreate;
	const CPanel2DClassInfo *m_pClassInfo;
	void *m_pUserdata;
};

} // namespace panorama

#endif
