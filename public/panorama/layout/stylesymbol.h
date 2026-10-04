#ifndef STYLESYMBOL_H
#define STYLESYMBOL_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/platform.h>

namespace panorama
{

const uint8 STYLE_SYMBOL_INVALID = 0xFF;

class CStyleSymbol
{
public:
	CStyleSymbol() : m_Id( STYLE_SYMBOL_INVALID ) {}
	CStyleSymbol( uint8 id ) : m_Id( id ) {}

	bool operator==( CStyleSymbol const &src ) const { return m_Id == src.m_Id; }
	bool operator!=( CStyleSymbol const &src ) const { return m_Id != src.m_Id; }
	bool operator<( const CStyleSymbol &rhs ) const { return m_Id < rhs.m_Id; }

	uint8 GetID() const { return m_Id; }
	bool IsValid() const { return m_Id != STYLE_SYMBOL_INVALID; }

private:
	uint8 m_Id;
};

COMPILE_TIME_ASSERT( sizeof( CStyleSymbol ) == 1 );

} // namespace panorama

#endif
