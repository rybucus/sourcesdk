#ifndef PANORAMA_PANELPTR_H
#define PANORAMA_PANELPTR_H

#ifdef _WIN32
#pragma once
#endif

#include <panorama/controls/panelhandle.h>

namespace panorama
{

template < class T >
class CPanelPtr
{
public:
	CPanelPtr() : m_handle( PanelHandle_t::InvalidHandle() ) {}
	explicit CPanelPtr( const PanelHandle_t &handle ) : m_handle( handle ) {}

	const PanelHandle_t &GetHandle() const { return m_handle; }
	bool IsValid() const { return m_handle.IsValid(); }

	bool operator==( const CPanelPtr< T > &rhs ) const { return m_handle == rhs.m_handle; }
	bool operator!=( const CPanelPtr< T > &rhs ) const { return m_handle != rhs.m_handle; }

private:
	PanelHandle_t m_handle;
};

} // namespace panorama

#endif
