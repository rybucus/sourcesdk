#ifndef CSGO_HUDDEATHNOTICE_H
#define CSGO_HUDDEATHNOTICE_H

#ifdef _WIN32
#pragma once
#endif

#include <panorama/controls/panel2d.h>
#include <cstrike15/panorama/hud/csgo_hudelement.h>

class CCSGO_HudDeathNotice : public panorama::CPanel2D, public CCSGOHudElement
{
public:
	panorama::CPanel2D *m_pVisibleNotices;
private:
	uint8 m_pad068[ 0x10 ];
public:
	float m_flLifetime;
	float m_flLocalPlayerLifetimeMod;
	float m_flFadeOutTime;
private:
	uint8 m_pad084[ 0x4 ];
};

COMPILE_TIME_ASSERT( sizeof( CCSGO_HudDeathNotice ) == 0x88 );

#endif
