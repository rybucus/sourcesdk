#ifndef PANORAMA_PANELHANDLE_H
#define PANORAMA_PANELHANDLE_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/platform.h>

namespace panorama
{

const uint64 k_ulInvalidPanelHandle64 = 0x00000000FFFFFFFF;

struct PanelHandle_t
{
	constexpr PanelHandle_t() : m_iPanelIndex( static_cast< int32 >( k_ulInvalidPanelHandle64 >> 32 ) ), m_unSerialNumber( static_cast< uint32 >( k_ulInvalidPanelHandle64 & 0xFFFFFFFF ) ) {}
	constexpr PanelHandle_t( int32 iPanelIndex, uint32 unSerialNumber ) : m_iPanelIndex( iPanelIndex ), m_unSerialNumber( unSerialNumber ) {}

	bool operator<( const PanelHandle_t &rhs ) const { return m_iPanelIndex != rhs.m_iPanelIndex ? m_iPanelIndex < rhs.m_iPanelIndex : m_unSerialNumber < rhs.m_unSerialNumber; }
	bool operator==( const PanelHandle_t &rhs ) const { return m_iPanelIndex == rhs.m_iPanelIndex && m_unSerialNumber == rhs.m_unSerialNumber; }
	bool operator!=( const PanelHandle_t &rhs ) const { return !operator==( rhs ); }

	bool IsValid() const { return operator!=( InvalidHandle() ); }

	static constexpr PanelHandle_t InvalidHandle() { return PanelHandle_t(); }

	int32 m_iPanelIndex;
	uint32 m_unSerialNumber;
};

COMPILE_TIME_ASSERT( sizeof( PanelHandle_t ) == 8 );

} // namespace panorama

#endif
