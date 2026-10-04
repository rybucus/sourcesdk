#ifndef PANORAMA_IUIPANELCLIENT_H
#define PANORAMA_IUIPANELCLIENT_H

#ifdef _WIN32
#pragma once
#endif

#include <mathlib/vector.h>
#include <tier0/platform.h>
#include <tier1/utlvector.h>
#include <panorama/panoramasymbol.h>

namespace panorama
{

class CPanel2D;
class IUIPanel;
class IUIScrollBar;
struct GamePadData_t;
struct KeyData_t;
struct MouseData_t;
struct PanoramaRect_t;

struct ParsedPanelProperty_t
{
	CPanoramaSymbol m_symName;
	const char *m_pchValue;
};

class IUIPanelClient
{
public:
	virtual IUIPanel *UIPanel() const = 0;
	virtual void OnDeletePanel() = 0;
	virtual CPanoramaSymbol GetPanelType() const = 0;
	virtual bool unk003( CPanoramaSymbol symPanelType ) const = 0;
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
	virtual bool OnClick( IUIPanel *pPanel, const MouseData_t &code ) = 0;
	virtual bool unk022() const = 0;
	virtual void OnRemoveChild( IUIPanel *pChild ) = 0;
	virtual bool unk024() = 0;
	virtual bool BIsDelayedProperty( CPanoramaSymbol symProperty ) = 0;
	virtual bool BSetProperties( const CUtlVector< ParsedPanelProperty_t > &vecProperties ) = 0;
	virtual bool BSetProperty( CPanoramaSymbol symName, const char *pchValue ) = 0;
	virtual void unk028() = 0;
	virtual void unk029() = 0;
	virtual void unk030() = 0;
	virtual void unk031() = 0;
	virtual void unk032() = 0;
	virtual void unk033() = 0;
	virtual void unk034() = 0;
	virtual bool unk035() = 0;
	virtual bool BRequiresContentClipLayer() = 0;
	virtual void unk037() = 0;
	virtual void *unk038() = 0;
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
	virtual void unk054() = 0;
	virtual void unk055() = 0;
	virtual void unk056() = 0;
	virtual void unk057() = 0;
	virtual void *unk058() = 0;
	virtual void unk059() = 0;
	virtual void *unk060() = 0;
	virtual const CPanoramaSymbol *unk061() const = 0;
	virtual ~IUIPanelClient() {}
	virtual bool GetContextUIBounds( float *pflX, float *pflY, float *pflWidth, float *pflHeight ) = 0;
	virtual void *unk064() = 0;
	virtual void *unk065() = 0;
};

} // namespace panorama

#endif
