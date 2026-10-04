#ifndef PANORAMA_RENDERPANEL_H
#define PANORAMA_RENDERPANEL_H

#ifdef _WIN32
#pragma once
#endif

#include <panorama/controls/panel2d.h>

namespace panorama
{

class CRenderPanel : public CPanel2D
{
public:
	virtual bool unk084() = 0;

private:
	uint8 m_pad020[ 0x10 ];
};

COMPILE_TIME_ASSERT( sizeof( CRenderPanel ) == 0x30 );

} // namespace panorama

#endif
