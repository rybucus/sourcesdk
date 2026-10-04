#ifndef PANORAMASYMBOL_H
#define PANORAMASYMBOL_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/utlsymbol.h>

namespace panorama
{

enum EPanoramaSymbolTable
{
	k_EPanoramaSymbolTableDefault,
	k_EPanoramaSymbolTableFilePath,
	k_EPanoramaSymbolTableCount,
};

class CPanoramaSymbol
{
public:
	CPanoramaSymbol() : m_Id( UTL_INVAL_SYMBOL ) {}
	CPanoramaSymbol( UtlSymId_t id ) : m_Id( id ) {}

	bool operator==( CPanoramaSymbol const &src ) const { return m_Id == src.m_Id; }
	bool operator!=( CPanoramaSymbol const &src ) const { return m_Id != src.m_Id; }
	bool operator<( CPanoramaSymbol const &src ) const { return m_Id < src.m_Id; }

	bool IsValid() const { return m_Id != UTL_INVAL_SYMBOL; }

	operator UtlSymId_t() const { return m_Id; }

private:
	UtlSymId_t m_Id;
};

COMPILE_TIME_ASSERT( sizeof( CPanoramaSymbol ) == 2 );

} // namespace panorama

#endif
