#ifndef PANORAMA_UITOPLEVELWINDOW_H
#define PANORAMA_UITOPLEVELWINDOW_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/platform.h>
#include <tier0/platwindow.h>
#include <tier0/utlstring.h>
#include <panorama/imeui.h>
#include <panorama/iuiwindow.h>

struct InputContextHandle_t__;
typedef InputContextHandle_t__ *InputContextHandle_t;

namespace panorama
{

class IUI3DSurface;

class CTopLevelWindow : public IUIWindow
{
public:
	IUIRenderEngine *m_pRenderEngine;
	IUIRenderDevice *m_pRenderDevice;
private:
	uint8 m_pad018[ 0x04 ];
public:
	bool m_bDeviceLost;
private:
	uint8 m_pad01D[ 0x0B ];
public:
	uint32 m_unSurfaceWidth;
	uint32 m_unSurfaceHeight;
	uint32 m_unWindowWidth;
	uint32 m_unWindowHeight;
private:
	uint8 m_pad038[ 0x08 ];
public:
	IUIWindowInput *m_pWindowInput;
private:
	uint8 m_pad048[ 0x08 ];
public:
	void *m_pContextPtr;
	float m_flScaleFactor;
private:
	uint8 m_pad05C[ 0xD2 ];
public:
	bool m_bInhibitInput;
	bool m_bPreventForceWindowOnTop;
private:
	uint8 m_pad130[ 0x04 ];
public:
	uint8 m_eFocusBehavior;
private:
	uint8 m_pad135[ 0x03 ];
public:
	int32 m_nWindowPriority;
private:
	uint8 m_pad13C[ 0x04 ];
};

COMPILE_TIME_ASSERT( sizeof( CTopLevelWindow ) == 0x140 );

class CTopLevelWindowSource2 : public CTopLevelWindow, public IIMEUIView
{
public:
	virtual bool BInitializeSurface( int xPos, int yPos, int nWidth, int nHeight, bool bFixedSurfaceSize, bool bEnforceWindowAspectRatio, bool bUseCustomMouseCursor, bool bAcceptKBandMouse ) = 0;

	CUtlString m_strName;
	InputContextHandle_t m_hInputContext;
	int32 m_nXPos;
	int32 m_nYPos;
	IUI3DSurface *m_p3DSurface;
private:
	uint8 m_pad168[ 0x01 ];
public:
	bool m_bHidden;
private:
	uint8 m_pad16A[ 0x2E ];
public:
	PlatWindow_t m_hPlatWindow;
private:
	uint8 m_pad1A0[ 0x20 ];
};

COMPILE_TIME_ASSERT( sizeof( CTopLevelWindowSource2 ) == 0x1C0 );

} // namespace panorama

#endif
