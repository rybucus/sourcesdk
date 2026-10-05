#ifndef CSGO_HUDWEAPONSELECTION_H
#define CSGO_HUDWEAPONSELECTION_H

#ifdef _WIN32
#pragma once
#endif

#include <tier1/utlvector.h>
#include <entityhandle.h>
#include <panorama/controls/panel2d.h>
#include <cstrike15/panorama/hud/csgo_hudelement.h>

struct WeaponSelectionIcon_t
{
private:
	uint8 m_pad000[ 0x38 ];
public:
	CEntityHandle m_hWeapon;
private:
	uint8 m_pad03C[ 0xC ];
};

COMPILE_TIME_ASSERT( sizeof( WeaponSelectionIcon_t ) == 0x48 );

class CCSGO_WeaponSelectionView : public panorama::CPanel2D
{
public:
	panorama::CPanel2D *m_pWeaponSelectionList;
private:
	uint8 m_pad028[ 0x8 ];
public:
	panorama::CPanel2D *m_pArmsRaceList;
private:
	uint8 m_pad038[ 0x18 ];
public:
	CUtlVector< WeaponSelectionIcon_t > m_vecIcons;
private:
	uint8 m_pad068[ 0x30 ];
};

COMPILE_TIME_ASSERT( sizeof( CCSGO_WeaponSelectionView ) == 0x98 );

class CCSGO_HudWeaponSelection : public CCSGO_WeaponSelectionView, public CCSGOHudElement
{
private:
	uint8 m_pad0D8[ 0x20 ];
};

COMPILE_TIME_ASSERT( sizeof( CCSGO_HudWeaponSelection ) == 0xF8 );

#endif
