#ifndef PANORAMA_IUIPANELSTYLE_H
#define PANORAMA_IUIPANELSTYLE_H

#ifdef _WIN32
#pragma once
#endif

#include <color.h>
#include <mathlib/vector.h>
#include <mathlib/vector2d.h>
#include <tier0/platform.h>
#include <tier1/utlvector.h>
#include <panorama/layout/stylesymbol.h>
#include <panorama/layout/uilength.h>
#include <panorama/panoramasymbol.h>
#include <panorama/panoramatypes.h>

namespace panorama
{

class CActiveAnimation;
class CBackgroundImageLayer;
class CRenderCommandList;
class CStyleProperty;
class CTransform3D;
class IImageSource;
struct FillBrushCollectionWithTransition_t;
struct PropertyInTransition_t;
struct TransitionProperty_t;

struct StyleEntry_t
{
	CStyleSymbol m_StyleSymbol;
	CStyleProperty *m_pStyleProperty;
};

class IUIPanelStyle
{
public:
	virtual void Clear( bool bIncludeClearingElementStyles = true ) = 0;
	virtual void UpdateUIScaleFactor( const Vector &vOldScaleFactor, const Vector &vNewScaleFactor, const Vector &vOldParentScaleFactor, const Vector &vNewParentScaleFactor ) = 0;
	virtual bool BHasAnyStyleDataForProperty( CStyleSymbol hSymbolProperty ) = 0;
	virtual void GetPosition( CUILength &x, CUILength &y, CUILength &z, bool bIncludeUIScaleFactor = true ) = 0;
	virtual void GetInterpolatedPosition( CUILength &x, CUILength &y, CUILength &z, bool bFinal, bool bIncludeUIScaleFactor = true ) = 0;
	virtual void SetPosition( CUILength x, CUILength y, CUILength z, bool bPreScaledByUIScaleFactor = false ) = 0;
	virtual void SetPositionWithoutTransition( CUILength x, CUILength y, CUILength z, bool bPreScaledByUIScaleFactor = false ) = 0;
	virtual void GetPerspectiveOrigin( CUILength &x, CUILength &y, bool &bInvert ) = 0;
	virtual void SetPerspectiveOrigin( CUILength &x, CUILength &y, bool &bInvert ) = 0;
	virtual void GetTransformOrigin( CUILength &x, CUILength &y, bool &bParentLayerRelative ) = 0;
	virtual void SetTransformOrigin( CUILength &x, CUILength &y, bool bParentLayerRelative ) = 0;
	virtual void GetPerspective( float &perspective ) = 0;
	virtual void SetPerspective( float perspective ) = 0;
	virtual void GetZIndex( float &zindex ) = 0;
	virtual void SetZIndex( float zIndex ) = 0;
	virtual void GetOverflow( EOverflowValue &eHorizontal, EOverflowValue &eVertical ) = 0;
	virtual void SetOverflow( const EOverflowValue eHorizontal, const EOverflowValue eVertical ) = 0;
	virtual void SetTransform3D( const CUtlVector< CTransform3D * > &vecTransforms ) = 0;
	virtual void SetTransform3DWithoutTransition( const CUtlVector< CTransform3D * > &vecTransforms ) = 0;
	virtual bool SetTransform3DSimple( const CUtlVector< CTransform3D * > &vecTransforms ) = 0;
	virtual void GetOpacity( float &opacity ) = 0;
	virtual void SetOpacity( float opacity ) = 0;
	virtual void GetBackgroundImgOpacity( float &opacity ) = 0;
	virtual void SetBackgroundImgOpacity( float opacity ) = 0;
	virtual void SetScale2DCentered( float flX, float flY ) = 0;
	virtual void GetInterpolatedScale2DCentered( float &flX, float &flY ) = 0;
	virtual void GetScale2DCentered( float &flX, float &flY ) = 0;
	virtual void SetRotate2DCentered( float flDegrees ) = 0;
	virtual void GetRotate2DCentered( float &flDegrees ) = 0;
	virtual void GetHueShift( float &flHueShift ) = 0;
	virtual void SetHueShift( float flHueShift ) = 0;
	virtual void GetSaturation( float &flSaturation ) = 0;
	virtual void SetSaturation( float flSaturation ) = 0;
	virtual void GetBrightness( float &flBrightness ) = 0;
	virtual void SetBrightness( float flBrightness ) = 0;
	virtual void GetContrast( float &flContrast ) = 0;
	virtual void SetContrast( float flContrast ) = 0;
	virtual void GetCursor( int &eCursor ) = 0;
	virtual void SetCursor( int eCursor ) = 0;
	virtual void GetGaussianBlur( BlurType_t &blurType, float &passes, float &stddevhor, float &stddevver ) = 0;
	virtual void SetGaussianBlur( BlurType_t blurType, float passes, float stddevhor, float stddevver ) = 0;
	virtual void GetBackgroundBlur( BlurType_t &blurType, float &passes, float &stddevhor, float &stddevver ) = 0;
	virtual void SetBackgroundBlur( BlurType_t blurType, float passes, float stddevhor ) = 0;
	virtual void GetWorldBlur( BlurType_t &blurType, float &passes, float &stddevhor, float &stddevver ) = 0;
	virtual void SetWorldBlur( BlurType_t blurType, float passes, float stddevhor, float stddevver ) = 0;
	virtual void GetOpacityMaskImage( IImageSource *&pImage, float *pflOpacityMaskOpacity ) = 0;
	virtual void SetOpacityMask( IImageSource *pImage, float flOpacity ) = 0;
	virtual void SetOpacityMask( const char *pchImage, float flOpacity ) = 0;
	virtual void GetWashColor( Color &c ) = 0;
	virtual void SetSimpleWashColor( const Color &c ) = 0;
	virtual EMixBlendMode GetMixBlendMode() = 0;
	virtual void SetMixBlendMode( EMixBlendMode eMode ) = 0;
	virtual ETextureSampleMode GetTexturesSampleMode() = 0;
	virtual void SetBackgroundColor( const char *pchColor ) = 0;
	virtual void SetSimpleBackgroundColor( const Color &c ) = 0;
	virtual bool GetSimpleBackgroundColor( Color &c ) = 0;
	virtual void SetForegroundColor( const char *pchColor ) = 0;
	virtual void SetSimpleForegroundColor( const Color &c ) = 0;
	virtual bool GetSimpleForegroundColor( Color &c ) = 0;
	virtual void SetFontStyle( const char *pchFontFamily, float flSize, EFontStyle style, EFontWeight weight ) = 0;
	virtual void GetFontStyle( const char **pchFontFamily, float &flSize, EFontStyle &style, EFontWeight &weight ) = 0;
	virtual void GetFontStyleNoDefaults( const char **pchFontFamily, float &flSize, EFontStyle &style, EFontWeight &weight ) = 0;
	virtual void GetForegroundFillBrushCollectionData( FillBrushCollectionWithTransition_t &data, CRenderCommandList &commandList, float flRenderWidth, float flRenderHeight ) = 0;
	virtual void *unk063() = 0;
	virtual void GetLineHeight( float &flLineHeight ) = 0;
	virtual void GetTextAlign( ETextAlign &align ) = 0;
	virtual void GetTextDecoration( ETextDecoration &decoration ) = 0;
	virtual void GetTextTransform( ETextTransform &transform ) = 0;
	virtual void GetTextLetterSpacing( int &spacing ) = 0;
	virtual void *unk069() = 0;
	virtual void *unk070() = 0;
	virtual void *unk071() = 0;
	virtual bool BHasPossibleBackgroundColor() = 0;
	virtual void GetWidth( CUILength &width ) = 0;
	virtual void SetWidth( CUILength width ) = 0;
	virtual void SetWidthWithoutTransition( CUILength width ) = 0;
	virtual void GetHeight( CUILength &height ) = 0;
	virtual void SetHeight( CUILength height ) = 0;
	virtual void SetHeightWithoutTransition( CUILength height ) = 0;
	virtual void GetMinWidth( CUILength &minWidth ) = 0;
	virtual void SetMinWidth( CUILength minWidth ) = 0;
	virtual void GetMinHeight( CUILength &minHeight ) = 0;
	virtual void SetMinHeight( CUILength minHeight ) = 0;
	virtual void GetMaxWidth( CUILength &maxWidth ) = 0;
	virtual void SetMaxWidth( CUILength maxWidth ) = 0;
	virtual void GetMaxHeight( CUILength &maxHeight ) = 0;
	virtual void SetMaxHeight( CUILength maxHeight ) = 0;
	virtual void GetInterpolatedWidth( CUILength &width, bool bFinal ) = 0;
	virtual void GetInterpolatedHeight( CUILength &height, bool bFinal ) = 0;
	virtual void GetInterpolatedMaxWidth( CUILength &width, bool bFinal ) = 0;
	virtual void GetInterpolatedMaxHeight( CUILength &height, bool bFinal ) = 0;
	virtual void SetUIScale( const Vector &vUIScale ) = 0;
	virtual Vector GetUIScale() = 0;
	virtual Vector GetInterpolatedUIScale( bool bFinal ) = 0;
	virtual void GetVisibility( bool &bVisible ) = 0;
	virtual void SetVisibility( bool bVisible ) = 0;
	virtual void GetFlowChildren( EFlowDirection &eFlowDirection ) = 0;
	virtual void SetFlowChildren( EFlowDirection eFlowDirection ) = 0;
	virtual void GetIgnoreParentFlow( bool &bIgnore ) = 0;
	virtual void SetIgnoreParentFlow( bool bIgnore ) = 0;
	virtual void GetInterpolatedBorderWidth( CUILength &left, CUILength &top, CUILength &right, CUILength &bottom, bool bFinal ) = 0;
	virtual void GetWhitespaceWrap( bool &bWrap ) = 0;
	virtual void GetTextOverflow( ETextOverflow &eTextOverflow ) = 0;
	virtual void *unk103() = 0;
	virtual void GetContentInset( float flBoxWidth, float flBoxHeight, bool bFinalDimensions, float &left, float &top, float &right, float &bottom ) = 0;
	virtual bool BHasContentInsetTransition() = 0;
	virtual void GetPadding( CUILength &left, CUILength &top, CUILength &right, CUILength &bottom ) = 0;
	virtual void GetMargin( CUILength &left, CUILength &top, CUILength &right, CUILength &bottom ) = 0;
	virtual void GetMargin( float flBoxWidth, float flBoxHeight, float &left, float &top, float &right, float &bottom ) = 0;
	virtual void SetMargin( CUILength &left, CUILength &top, CUILength &right, CUILength &bottom ) = 0;
	virtual void GetBorderWidth( CUILength &left, CUILength &top, CUILength &right, CUILength &bottom ) = 0;
	virtual void SetBorderWidth( CUILength left, CUILength top, CUILength right, CUILength bottom ) = 0;
	virtual CUtlVector< CBackgroundImageLayer * > *GetBackgroundImages() = 0;
	virtual void SetBackgroundImages( const CUtlVector< CBackgroundImageLayer * > &vecLayers ) = 0;
	virtual void *unk114() = 0;
	virtual void *unk115() = 0;
	virtual void GetAlignment( EHorizontalAlignment &eHorizontalAlignment, EVerticalAlignment &eVerticalAlignment ) = 0;
	virtual void SetAlignment( EHorizontalAlignment eHorizontalAlignment, EVerticalAlignment eVerticalAlignment ) = 0;
	virtual void SetTooltipPositions( const EContextUIPosition ( &eTooltipPositions )[ 4 ] ) = 0;
	virtual void GetTooltipPositions( EContextUIPosition ( &eTooltipPositions )[ 4 ] ) = 0;
	virtual void SetTooltipBodyPosition( const CUILength &horizontalPosition, const CUILength &verticalPosition ) = 0;
	virtual void GetTooltipBodyPosition( CUILength &horizontalPosition, CUILength &verticalPosition ) = 0;
	virtual void SetTooltipArrowPosition( const CUILength &horizontalPosition, const CUILength &verticalPosition ) = 0;
	virtual void GetTooltipArrowPosition( CUILength &horizontalPosition, CUILength &verticalPosition ) = 0;
	virtual void SetContextMenuPositions( const EContextUIPosition ( &eContextMenuPositions )[ 4 ] ) = 0;
	virtual void GetContextMenuPositions( EContextUIPosition ( &eContextMenuPositions )[ 4 ] ) = 0;
	virtual void SetContextMenuBodyPosition( const CUILength &horizontalPosition, const CUILength &verticalPosition ) = 0;
	virtual void GetContextMenuBodyPosition( CUILength &horizontalPosition, CUILength &verticalPosition ) = 0;
	virtual void SetContextMenuArrowPosition( const CUILength &horizontalPosition, const CUILength &verticalPosition ) = 0;
	virtual void GetContextMenuArrowPosition( CUILength &horizontalPosition, CUILength &verticalPosition ) = 0;
	virtual void SetRadialClip( bool bRadialClip, const CUILength &x, const CUILength &y, float flStartAngle, float flSectorAngle ) = 0;
	virtual void GetRadialClip( bool &bRadialClip, CUILength &x, CUILength &y, float &flStartAngle, float &flSectorAngle ) = 0;
	virtual void *unk132() = 0;
	virtual void *unk133() = 0;
	virtual void SetLayoutPosition( int ePosition ) = 0;
	virtual void GetLayoutPosition( int &ePosition ) = 0;
	virtual void GetAnimationNames( CUtlVector< CPanoramaSymbol > *pvecAnimations ) = 0;
	virtual void ResetAnimations() = 0;
	virtual float GetParentActualRenderWidth() = 0;
	virtual float GetParentActualRenderHeight() = 0;
	virtual bool BHasAnyTransition() = 0;
	virtual bool BHasAnyTransitionOrAnimation( bool bExcludeStylesImpactingOnlyCompositing ) = 0;
	virtual bool BHasAnimatingBackground() = 0;
	virtual bool BIsTransparentWithNoOpacityTransition() = 0;
	virtual void SetTransitionProperties( const CUtlVector< TransitionProperty_t > &vecTransitionProperties ) = 0;
	virtual void GetAnimationCurveControlPoints( EAnimationTimingFunction eTransitionEffect, Vector2D vecPoints[ 4 ] ) = 0;
	virtual void FindPropertyInfo( CStyleSymbol hSymbol, CStyleProperty **ppProperty, PropertyInTransition_t **ppTransitionData, CUtlVector< CActiveAnimation * > *pvecAnimations ) = 0;
	virtual TransitionProperty_t *FindTransitionData( CStyleSymbol hSymbol ) = 0;
	virtual const CUtlVector< StyleEntry_t > &PropertiesSetFromElement() const = 0;
	virtual const CStyleProperty *GetPropertyNoInherit( CStyleSymbol symProperty ) = 0;
	virtual bool BPropertySetFromElement( CStyleSymbol symProperty ) const = 0;
	virtual void ClearPropertySetFromElement( CStyleSymbol symProperty ) = 0;
	virtual void *unk152() = 0;
	virtual CStyleProperty *CompletePropertyTransitionNow( CStyleSymbol hSymbol, bool bDeleteTargetProperty ) = 0;
	virtual void GetActiveAnimations( CUtlVector< CActiveAnimation * > *pvecAnimations ) = 0;
	virtual CActiveAnimation *FindActiveAnimation( CPanoramaSymbol animName ) = 0;
	virtual void *unk156() = 0;
};

} // namespace panorama

#endif
