#ifndef PANORAMA_IUIWINDOW_H
#define PANORAMA_IUIWINDOW_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/platform.h>
#include <tier0/platwindow.h>
#include <tier1/utllinkedlist.h>

namespace panorama
{

class IUIPanel;
class IUIRenderDevice;
class IUIRenderEngine;
class IUIWindowInput;
struct DrawTextRegionRenderCommand_t;
struct InputMessage_t;

class IUIWindow
{
public:
	virtual void RenderWindow( PlatWindow_t hWindow, bool bDebugger ) = 0;
	virtual bool BUseAutoMouseUpBehavior() = 0;
	virtual bool unk002() = 0;
	virtual void Delete() = 0;
	virtual IUIWindowInput *UIWindowInput() = 0;
	virtual IUIRenderEngine *UIRenderEngine() = 0;
	virtual IUIRenderDevice *UIRenderDevice() = 0;
	virtual void SetWindowScaleFactor( float flScaleFactor ) = 0;
	virtual float GetWindowScaleFactor() = 0;
	virtual bool BCursorVisible() = 0;
	virtual uint32 GetSurfaceWidth() = 0;
	virtual uint32 GetSurfaceHeight() = 0;
	virtual uint32 GetWindowWidth() = 0;
	virtual uint32 GetWindowHeight() = 0;
	virtual void GetClientDimensions( float &width, float &height ) = 0;
	virtual void OnWindowResize( uint32 width, uint32 height ) = 0;
	virtual void SetWindowPosition( float x, float y ) = 0;
	virtual void GetWindowPosition( float &x, float &y ) = 0;
	virtual void Activate( bool bForceful ) = 0;
	virtual bool BHasFocus() = 0;
	virtual uint32 GetNumVisibleTopLevelPanels() const = 0;
	virtual const CUtlLinkedList< IUIPanel * > &GetTopLevelVisiblePanels() const = 0;
	virtual void *unk022() = 0;
	virtual void *unk023() = 0;
	virtual bool unk024() = 0;
	virtual bool unk025() = 0;
	virtual void unk026( bool bUnknown ) = 0;
	virtual void SetContextPtr( void *pv ) = 0;
	virtual void *GetContextPtr() const = 0;
	virtual void AddClass( const char *pchName ) = 0;
	virtual void RemoveClass( const char *pchName ) = 0;
	virtual void SetHasClass( const char *pchName, bool bHasClass ) = 0;
	virtual void ForceFullRepaint() = 0;
	virtual void SetInhibitInput( bool bInhibitInput ) = 0;
	virtual void SetPreventForceWindowOnTop( bool bPreventForceTopLevel ) = 0;
	virtual void *unk035() = 0;
	virtual void *unk036() = 0;
	virtual void *unk037() = 0;
	virtual void *unk038() = 0;
	virtual bool unk039() = 0;
	virtual void unk040() = 0;
	virtual void unk041( float flUnknown ) = 0;
	virtual void *unk042() = 0;
	virtual void *unk043() = 0;
	virtual bool BIsVisible() = 0;
	virtual void SetVisible( bool bVisible ) = 0;
	virtual uint8 GetFocusBehavior() = 0;
	virtual void SetFocusBehavior( uint8 eFocusBehavior ) = 0;
	virtual void OnDeviceLost() = 0;
	virtual void OnDeviceRestored() = 0;
	virtual bool BDeviceLost() = 0;
	virtual void *unk051() = 0;
	virtual void SetWindowPriority( int nPriority ) = 0;
	virtual int GetWindowPriority() = 0;
	virtual void *unk054() = 0;
	virtual void unk055( float flUnknown ) = 0;
	virtual void *unk056() = 0;
	virtual bool unk057() = 0;
	virtual void LayoutAndPaintIfNeeded() = 0;
	virtual bool unk059() = 0;
	virtual void unk060( bool bUnknown ) = 0;
	virtual void AsyncAddTextRegionToCache( const DrawTextRegionRenderCommand_t &renderCommand ) = 0;
	virtual void *unk062() = 0;
	virtual void *unk063() = 0;
	virtual ~IUIWindow() {}
	virtual bool unk065() = 0;
	virtual void ClearGPUResourcesBeforeNextFrame() = 0;
	virtual void GetWindowBounds( float &left, float &top, float &right, float &bottom ) = 0;
	virtual bool BAllowInput( InputMessage_t &msg ) = 0;
	virtual void PaintEmptyFrameAndForceLaterRepaint() = 0;
	virtual void *unk070() = 0;
	virtual const char *unk071() = 0;
	virtual void *unk072() = 0;
};

} // namespace panorama

#endif
