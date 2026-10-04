#ifndef PANORAMA_IMAGE_H
#define PANORAMA_IMAGE_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/utlstring.h>
#include <panorama/controls/panel2d.h>
#include <panorama/data/iimagesource.h>

namespace panorama
{

class CImageProxySource;

class CImagePanel : public CPanel2D
{
private:
	uint8 m_pad020[ 0x20 ];
public:
	UIImageLoadParams_t m_LoadParams;
private:
	uint8 m_pad090[ 0x08 ];
public:
	CUtlString m_strSource;
	CUtlString m_strUnknown0A0;
private:
	uint8 m_pad0A8[ 0x20 ];
public:
	CImageProxySource *m_pImageProxySource;
private:
	uint8 m_pad0D0[ 0x08 ];
};

COMPILE_TIME_ASSERT( sizeof( CImagePanel ) == 0xD8 );

} // namespace panorama

#endif
