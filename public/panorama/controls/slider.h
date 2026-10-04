#ifndef PANORAMA_SLIDER_H
#define PANORAMA_SLIDER_H

#ifdef _WIN32
#pragma once
#endif

#include <panorama/controls/panel2d.h>

namespace panorama
{

class CSlider : public CPanel2D
{
public:
	virtual void SetValue( float flValue ) = 0;
	virtual void SetValueNoEvents( float flValue ) = 0;
	virtual void SetDirection( int eDirection ) = 0;
	virtual bool unk087() = 0;
	virtual void unk088() = 0;
	virtual void unk089() = 0;

private:
	uint8 m_pad020[ 0x20 ];
public:
	float m_flMin;
	float m_flMax;
	float m_flDefault;
	float m_flCur;
	float m_flLast;
private:
	uint8 m_pad054[ 0x04 ];
public:
	float m_flIncrement;
	bool m_bRequiresSelection;
	bool m_bDraggingThumb;
	bool m_bShowDefault;
	bool m_bMouseDown;
	double m_flMouseDownTime;
	int32 m_eDirection;
	float m_flLastMouseX;
	float m_flLastMouseY;
	float m_flMouseDownValueOffset;
};

COMPILE_TIME_ASSERT( sizeof( CSlider ) == 0x78 );

} // namespace panorama

#endif
