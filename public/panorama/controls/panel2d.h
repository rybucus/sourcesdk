#ifndef PANORAMA_PANEL2D_H
#define PANORAMA_PANEL2D_H

#ifdef _WIN32
#pragma once
#endif

#include <tier1/utlvector.h>
#include <panorama/controls/panelptr.h>
#include <panorama/iuipanelclient.h>
#include <panorama/layout/panel2dfactory.h>

namespace panorama
{

class CUIPanel;
struct DebugPropertyOutput_t;
class IUIRenderDevice;
class IUIRenderEngine;

class CPanel2D : public IUIPanelClient
{
public:
	virtual bool GetContextUIBounds( float *pflX, float *pflY, float *pflWidth, float *pflHeight ) = 0;
	virtual void ScrollToXPercent( float flXPercent ) = 0;
	virtual void ScrollToYPercent( float flYPercent ) = 0;
	virtual bool OnMoveUp( int nRepeats ) = 0;
	virtual bool OnMoveDown( int nRepeats ) = 0;
	virtual bool OnMoveLeft( int nRepeats ) = 0;
	virtual bool OnMoveRight( int nRepeats ) = 0;
	virtual bool OnTabForward( int nRepeats ) = 0;
	virtual bool OnTabBackward( int nRepeats ) = 0;
	virtual void SetSelected( bool bSelected ) = 0;
	virtual void GetDebugPropertyInfo( CUtlVector< DebugPropertyOutput_t * > *pvecProperties ) = 0;
	virtual bool IsClonable() = 0;
	virtual CPanel2D *Clone() = 0;
	virtual bool BHasBeenLayedOut() const = 0;
	virtual void unk077() = 0;
	virtual void unk078() = 0;
	virtual IUIRenderEngine *AccessRenderEngine() = 0;
	virtual IUIRenderDevice *AccessRenderDevice() = 0;
	virtual void InitClonedPanel( CPanel2D *pPanel ) = 0;
	virtual void AddDisabledFlagToChildren() = 0;
	virtual void RemoveDisabledFlagFromChildren() = 0;

	CUIPanel *m_pUIPanel;
	CPanelPtr< CPanel2D > m_pTooltip;
	void *m_pJSData;
};

COMPILE_TIME_ASSERT( sizeof( CPanel2D ) == 0x20 );

} // namespace panorama

#endif
