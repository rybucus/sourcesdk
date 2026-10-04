#ifndef PANORAMA_IIMAGESOURCE_H
#define PANORAMA_IIMAGESOURCE_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/platform.h>
#include <tier0/utlstring.h>
#include <tier0/utlsymbol.h>

namespace panorama
{

enum ESvgAttribute
{
	k_ESvgAttributeFill,
	k_ESvgAttributeFill_opacity,
	k_ESvgAttributeStroke,
	k_ESvgAttributeStroke_width,
	k_ESvgAttributeStroke_linecap,
	k_ESvgAttributeStroke_linejoin,
	k_ESvgAttributeStroke_opacity,
	k_ESvgAttributeOpacity,
	k_ESvgAttributeFill_rule,
	k_ESvgAttributeClip_path,
	k_ESvgAttributeClip_rule,
	k_ESvgAttributeMax
};

enum ESvgStrokeLineCap
{
	k_ESvgButt,
	k_ESvgCapRound,
	k_ESvgSquare
};

enum ESvgStrokeLineJoin
{
	k_ESvgMiter,
	k_ESvgJoinRound,
	k_ESvgBevel
};

enum ESvgFillRule
{
	k_ESvgNonzero,
	k_ESvgEvenodd
};

struct SvgAttributeValue_t
{
	union
	{
		unsigned char m_color[ 4 ];
		float m_opacity;
		float m_length;
		ESvgStrokeLineCap m_strokeLineCap;
		ESvgStrokeLineJoin m_strokeLineJoin;
		ESvgFillRule m_fillRule;
		UtlSymId_t m_id;
	};
};

struct SvgAttributeOverrides_t
{
	SvgAttributeValue_t m_overrides[ k_ESvgAttributeMax ];
	uint32 m_nFlags;
};

const int k_ResizeNone = -1;

struct UIImageLoadParams_t
{
	CUtlString m_origin;
	int32 m_nMaxWidth;
	int32 m_nMaxHeight;
	int32 m_nResizeWidth;
	int32 m_nResizeHeight;
	float m_fScaleFactor;
	SvgAttributeOverrides_t m_svgAttributeOverrides;
	bool m_bAllowAnimation;
};

COMPILE_TIME_ASSERT( sizeof( SvgAttributeOverrides_t ) == 48 );

} // namespace panorama

#endif
