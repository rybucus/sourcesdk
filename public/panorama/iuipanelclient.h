#ifndef PANORAMA_IUIPANELCLIENT_H
#define PANORAMA_IUIPANELCLIENT_H

#ifdef _WIN32
#pragma once
#endif

#include <mathlib/vector.h>
#include <tier0/basetypes.h>
#include <tier0/platform.h>
#include <tier1/utlvector.h>
#include <panorama/panoramasymbol.h>
#include <panorama/panoramatypes.h>

namespace panorama
{

class CPanel2D;
class IUIPanel;
class IUIScrollBar;
struct CPanel2DClassInfo;
struct GamePadData_t;
struct KeyData_t;
struct MouseData_t;
struct PanoramaRect_t;

struct ParsedPanelProperty_t
{
	CPanoramaSymbol m_symName;
	const char *m_pchValue;
};

struct GestureData_t
{
	float m_flX;
	float m_flY;
	int m_nPhase;
	float m_flRotation;
	float m_flScale;
};

class IUIPanelClient
{
public:
	virtual IUIPanel *UIPanel() const = 0;
	virtual void OnDeletePanel() = 0;
	virtual CPanoramaSymbol GetPanelType() const = 0;
	virtual bool IsPanelType( CPanoramaSymbol symPanelType ) const = 0;
	virtual void Paint() = 0;
	virtual void PaintArea( const PanoramaRect_t &rectPaintArea ) = 0;
	virtual void StoppedPainting() = 0;
	virtual void OnContentSizeTraverse( float *pflContentWidth, float *pflContentHeight, float flMaxWidth, float flMaxHeight, bool bFinalDimensions ) = 0;
	virtual void OnLayoutTraverse( float flFinalWidth, float flFinalHeight ) = 0;
	virtual bool OnKeyDown( const KeyData_t &code ) = 0;
	virtual bool OnKeyUp( const KeyData_t &code ) = 0;
	virtual bool OnKeyTyped( const KeyData_t &unichar ) = 0;
	virtual bool OnGamePadDown( const GamePadData_t &code ) = 0;
	virtual bool OnGamePadUp( const GamePadData_t &code ) = 0;
	virtual bool OnGamePadAnalog( const GamePadData_t &code ) = 0;
	virtual bool OnMouseButtonDown( const MouseData_t &code ) = 0;
	virtual bool OnMouseButtonUp( const MouseData_t &code ) = 0;
	virtual bool OnMouseButtonDoubleClick( const MouseData_t &code ) = 0;
	virtual bool OnMouseButtonTripleClick( const MouseData_t &code ) = 0;
	virtual bool OnMouseWheel( const MouseData_t &code ) = 0;
	virtual void OnMouseMove( float flMouseX, float flMouseY ) = 0;
	virtual bool BDragInProgress() const = 0;
	virtual bool BRequiresFocus() const = 0;
	virtual bool OnClick( IUIPanel *pPanel, const MouseData_t &code ) = 0;
	virtual bool OnGesture( float flMouseX, float flMouseY, const GestureData_t &gesture ) = 0;
	virtual bool BIsClientPanelEvent( CPanoramaSymbol symProperty ) = 0;
	virtual bool BSetProperties( const CUtlVector< ParsedPanelProperty_t > &vecProperties ) = 0;
	virtual bool BSetProperty( ParsedPanelProperty_t property ) = 0;
	virtual void OnBeforeChildrenChanged() = 0;
	virtual void OnRemoveChild( IUIPanel *pChild ) = 0;
	virtual void OnAfterChildrenChanged() = 0;
	virtual void OnInitializedFromLayout() = 0;
	virtual void OnStylesChanged() = 0;
	virtual void OnChildStylesChanged() = 0;
	virtual void OnVisibilityChanged() = 0;
	virtual bool OnSetFocusToNextPanel( int nRepeats, EFocusMoveDirection moveType, bool bAllowWrap, float flTabIndexCurrent, float flXPosCurrent, float flYPosCurrent, float flXStart, float flYStart ) = 0;
	virtual bool BRequiresContentClipLayer() = 0;
	virtual void OnCallBeforeStyleAndLayout() = 0;
	virtual int GetMouseCursor() = 0;
	virtual void OnUIScaleFactorChanged( const Vector &vOldScaleFactor, const Vector &vNewScaleFactor ) = 0;
	virtual void SetupJavascriptObjectTemplate() = 0;
	virtual IUIScrollBar *CreateNewVerticalScrollBar( float flInitialScrollPos ) = 0;
	virtual IUIScrollBar *CreateNewHorizontalScrollBar( float flInitialScrollPos ) = 0;
	virtual void HideTooltip() = 0;
	virtual IUIPanel *OnGetDefaultInputFocus() = 0;
	virtual void GetPositionWithinAncestor( CPanel2D *pAncestor, float *pflX, float *pflY ) = 0;
	virtual bool BCanCustomScrollUp() const = 0;
	virtual bool BCanCustomScrollDown() const = 0;
	virtual bool BCanCustomScrollLeft() const = 0;
	virtual bool BCanCustomScrollRight() const = 0;
	virtual bool BCustomCanDragScroll() const = 0;
	virtual bool BCustomScrollInProgress() = 0;
	virtual void OnLayoutReloading() = 0;
	virtual void OnLayoutReloaded() = 0;
	virtual void OnStyleFileReloaded() = 0;
	virtual void OnReadyForDisplay() = 0;
	virtual void OnUnreadyForDisplay() = 0;
	virtual void OnDeferredUpdate() = 0;
	virtual const char *GetDebugDescription() = 0;
	virtual void OnParentWindowChanged() = 0;
	virtual SoundEventGuid_t PlayPanelSound( const char *pchSound ) = 0;
	virtual const CPanel2DClassInfo *GetPanelClassInfo() const = 0;
	virtual ~IUIPanelClient() {}
};

} // namespace panorama

#endif
