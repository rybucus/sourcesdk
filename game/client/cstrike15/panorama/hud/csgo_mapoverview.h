#ifndef CSGO_MAPOVERVIEW_H
#define CSGO_MAPOVERVIEW_H

#ifdef _WIN32
#pragma once
#endif

#include <mathlib/vector.h>
#include <tier0/utlstring.h>
#include <panorama/controls/image.h>
#include <panorama/controls/panel2d.h>
#include <cstrike15/panorama/hud/csgo_hudelement.h>

struct MapOverviewInfo_t
{
	int m_nPosX;
	int m_nPosY;
	float m_flScale;
private:
	uint8 m_pad00C[ 0x4 ];
public:
	CUtlString m_strImage;
};

COMPILE_TIME_ASSERT( sizeof( MapOverviewInfo_t ) == 0x18 );

class CCSGO_MapOverview : public panorama::CPanel2D, public CCSGOHudElement
{
public:
	virtual bool unk084( void *pIcon ) = 0;

private:
	uint8 m_pad060[ 0x1A8 ];
public:
	MapOverviewInfo_t m_MapInfo;
	Vector m_vecMapOrigin;
private:
	uint8 m_pad22C[ 0x8 ];
public:
	float m_flMapScale;
	float m_flTextureSize;
private:
	uint8 m_pad23C[ 0x134 ];
public:
	panorama::CImagePanel *m_pMapPanel;
private:
	uint8 m_pad378[ 0x1D880 ];
};

COMPILE_TIME_ASSERT( sizeof( CCSGO_MapOverview ) == 0x1DBF8 );

#endif
