#ifndef PANORAMA_STYLEPROPERTIES_H
#define PANORAMA_STYLEPROPERTIES_H

#ifdef _WIN32
#pragma once
#endif

#include <color.h>
#include <mathlib/vmatrix.h>
#include <tier0/utlstring.h>
#include <tier1/utlvector.h>
#include <panorama/layout/fillbrush.h>
#include <panorama/layout/stylesymbol.h>
#include <panorama/layout/uilength.h>
#include <panorama/panoramatypes.h>
#include <panorama/transformations.h>

namespace panorama
{

class CStyleProperty
{
public:
	const void *m_pVTable;
	CStyleSymbol m_symPropertyName;
	bool m_bDisallowTransition;
};

class CStylePropertyWidth : public CStyleProperty
{
public:
	CUILength m_Length;
};

class CStylePropertyHeight : public CStyleProperty
{
public:
	CUILength m_Height;
};

class CStylePropertyOpacity : public CStyleProperty
{
public:
	float opacity;
};

class CStylePropertyZIndex : public CStyleProperty
{
public:
	float zindex;
};

class CStylePropertyPosition : public CStyleProperty
{
public:
	CUILength x;
	CUILength y;
	CUILength z;
};

class CStylePropertyTransformOrigin : public CStyleProperty
{
public:
	CUILength x;
	CUILength y;
	bool m_bParentRelative;
};

class CStylePropertyAlign : public CStyleProperty
{
public:
	EHorizontalAlignment m_eHorizontalAlignment;
	EVerticalAlignment m_eVerticalAlignment;
};

class CStylePropertyWashColor : public CStyleProperty
{
public:
	Color m_color;
	bool m_bSet;
};

class CStylePropertyFlowChildren : public CStyleProperty
{
public:
	EFlowDirection m_eFlowDirection;
};

class CStylePropertyFont : public CStyleProperty
{
public:
	CUtlString m_strFontFamily;
	float m_flFontSize;
	EFontStyle m_eFontStyle;
	EFontWeight m_eFontWeight;
	EFontStretch m_eFontStretch;
};

class CStylePropertyImageShadow : public CStyleProperty
{
public:
	bool m_bSet;
	CUILength m_HorizontalOffset;
	CUILength m_VerticalOffset;
	CUILength m_BlurRadius;
	float m_flStrength;
	Color m_ShadowColor;
};

class CStylePropertyTextShadow : public CStyleProperty
{
public:
	bool m_bSet;
	CUILength m_HorizontalOffset;
	CUILength m_VerticalOffset;
	CUILength m_BlurRadius;
	float m_flStrength;
	Color m_ShadowColor;
};

class CStylePropertyMargin : public CStyleProperty
{
public:
	CUILength m_left;
	CUILength m_top;
	CUILength m_right;
	CUILength m_bottom;
};

class CStylePropertyMixBlendMode : public CStyleProperty
{
public:
	EMixBlendMode m_eMixBlendMode;
	bool m_bSet;
};

class CStylePropertyTextAlign : public CStyleProperty
{
public:
	ETextAlign m_eAlign;
};

class CStylePropertyFillColor : public CStyleProperty
{
public:
	CFillBrushCollection m_FillBrushCollection;
};

class CStylePropertyForegroundColor : public CStylePropertyFillColor
{
};

class CStylePropertyBackgroundColor : public CStylePropertyFillColor
{
public:
	float m_flOpacity;
};

class CStylePropertyTransform3D : public CStyleProperty
{
public:
	CUtlVector< CTransform3D * > m_vecTransforms;
	float m_flCachedParentWidth;
	float m_flCachedParentHeight;
	bool m_bDirty;
	VMatrix m_Matrix;
	bool m_bInterpolated;
	bool m_bSet;
};

class CStylePropertyBorder : public CStyleProperty
{
public:
	EBorderStyle m_rgBorderStyle[ 4 ];
	CUILength m_rgBorderWidth[ 4 ];
	bool m_rgColorsSet[ 4 ];
	Color m_rgBorderColor[ 4 ];
};

class CStylePropertyBorderRadius : public CStyleProperty
{
public:
	struct CornerRadii_t
	{
		CUILength m_HorizontalRadii;
		CUILength m_VerticalRadii;
	};

	CornerRadii_t m_rgCornerRaddi[ 4 ];
};

COMPILE_TIME_ASSERT( sizeof( CStyleProperty ) == 16 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyWidth ) == 24 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyHeight ) == 24 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyOpacity ) == 24 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyZIndex ) == 24 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyPosition ) == 40 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyTransformOrigin ) == 40 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyWashColor ) == 24 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyFont ) == 32 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyImageShadow ) == 56 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyTextShadow ) == 56 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyMargin ) == 48 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyForegroundColor ) == 48 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyBackgroundColor ) == 56 );
COMPILE_TIME_ASSERT( sizeof( CStylePropertyTransform3D ) == 120 );

} // namespace panorama

#endif
