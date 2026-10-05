#ifndef CSGO_HUDRADAR_H
#define CSGO_HUDRADAR_H

#ifdef _WIN32
#pragma once
#endif

#include <panorama/controls/panel2d.h>
#include <cstrike15/panorama/hud/csgo_hudelement.h>

class CCSGO_HudRadar : public panorama::CPanel2D, public CCSGOHudElement
{
public:
	virtual bool unk084( void *pIcon ) = 0;

private:
	uint8 m_pad060[ 0x177A8 ];
public:
	uint8 m_nRadarFlags;
private:
	uint8 m_pad17809[ 0x837 ];
};

COMPILE_TIME_ASSERT( sizeof( CCSGO_HudRadar ) == 0x18040 );

#endif
