#ifndef PANORAMA_PANEL2D_H
#define PANORAMA_PANEL2D_H

#ifdef _WIN32
#pragma once
#endif

#include <tier1/utlvector.h>
#include <panorama/controls/panelptr.h>
#include <panorama/iuipanelclient.h>

namespace panorama
{

class CUIPanel;
struct DebugPropertyOutput_t;
class IUIRenderDevice;
class IUIRenderEngine;

class CPanel2D : public IUIPanelClient
{
public:
	virtual bool OnMoveUp( int nRepeats ) = 0;
	virtual bool OnMoveDown( int nRepeats ) = 0;
	virtual bool OnMoveLeft( int nRepeats ) = 0;
	virtual bool OnMoveRight( int nRepeats ) = 0;
	virtual bool OnTabForward( int nRepeats ) = 0;
	virtual bool OnTabBackward( int nRepeats ) = 0;
	virtual IUIRenderEngine *AccessRenderEngine() = 0;
	virtual void GetDebugPropertyInfo( CUtlVector< DebugPropertyOutput_t * > *pvecProperties ) = 0;
	virtual bool IsClonable() = 0;
	virtual CPanel2D *Clone() = 0;
	virtual IUIRenderDevice *AccessRenderDevice() = 0;
	virtual void unk077() = 0;
	virtual void unk078() = 0;
	virtual void unk079() = 0;
	virtual void unk080() = 0;
	virtual void *unk081( const CPanoramaSymbol *pTargetType ) = 0;
	virtual void unk082() = 0;
	virtual void unk083() = 0;

	CUIPanel *m_pUIPanel;
	CPanelPtr< CPanel2D > m_pTooltip;
	void *m_pJSData;
};

COMPILE_TIME_ASSERT( sizeof( CPanel2D ) == 0x20 );

} // namespace panorama

#endif
