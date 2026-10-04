#ifndef FILLBRUSH_H
#define FILLBRUSH_H

#ifdef _WIN32
#pragma once
#endif

#include <color.h>
#include <tier0/platform.h>
#include <tier1/utlleanvector.h>

namespace panorama
{

class CLinearGradient;
class CRadialGradient;

class CFillBrush
{
public:
	enum EStrokeType : uint32
	{
		k_EStrokeTypeFillColor,
		k_EStrokeTypeLinearGradient,
		k_EStrokeTypeRadialGradient,
	};

	CFillBrush() : m_eType( k_EStrokeTypeFillColor ), m_FillColor( 0 ) {}
	CFillBrush( Color color ) : m_eType( k_EStrokeTypeFillColor ), m_FillColor( color ) {}

	EStrokeType m_eType;

	union
	{
		Color m_FillColor;
		CLinearGradient *m_pLinearGradient;
		CRadialGradient *m_pRadialGradient;
	};
};

COMPILE_TIME_ASSERT( sizeof( CFillBrush ) == 16 );

class CFillBrushCollection
{
public:
	struct FillBrush_t
	{
		CFillBrush m_Brush;
		float m_Opacity;
	};

	CUtlLeanVectorFixedGrowable< FillBrush_t, 1 > m_vecFillBrushes;
};

COMPILE_TIME_ASSERT( sizeof( CFillBrushCollection::FillBrush_t ) == 24 );
COMPILE_TIME_ASSERT( sizeof( CFillBrushCollection ) == 32 );

} // namespace panorama

#endif
