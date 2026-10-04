#ifndef PANORAMA_UIPANEL_H
#define PANORAMA_UIPANEL_H

#ifdef _WIN32
#pragma once
#endif

#include <mathlib/vector.h>
#include <tier0/utlstring.h>
#include <tier1/utlvector.h>
#include <panorama/controls/panelhandle.h>
#include <panorama/iuipanel.h>
#include <panorama/panoramasymbol.h>
#include <panorama/panoramatypes.h>

namespace panorama
{

class CLayoutFile;

class CUIPanel : public IUIPanel
{
public:
	typedef CUtlString ID_t;
	typedef CUtlVector< CUIPanel * > Children_t;
	typedef CUtlVector< CPanoramaSymbol > Classes_t;
	typedef uint8 Flags_t;

	IUIPanelClient *m_pClientPanel;
	ID_t m_strID;
	IUIPanel *m_pParent;
	IUIWindow *m_pWindow;
	Children_t m_vecChildren;
	void *m_pHiddenChildren;
private:
	uint8 m_pad048[ 0x20 ];
public:
	uint8 m_PanelStyle[ 0xB0 ];
private:
	uint8 m_pad118[ 0x04 ];
public:
	Flags_t m_nPanelFlags;
private:
	uint8 m_pad11D[ 0x1F ];
public:
	float m_flTabIndex;
	float m_flSelectionPosX;
	float m_flSelectionPosY;
	CUtlString m_strDefaultFocus;
private:
	uint8 m_pad150[ 0x08 ];
public:
	Classes_t m_vecClasses;
private:
	uint8 m_pad170[ 0x28 ];
public:
	CLayoutFile *m_pLayoutFile;
	CLayoutFile *m_pLayoutFileLoadedFromParent;
private:
	uint8 m_pad1A8[ 0x08 ];
public:
	float m_flDesiredLayoutWidth;
	float m_flDesiredLayoutHeight;
	float m_flContentWidth;
	float m_flContentHeight;
	float m_flActualXOffset;
	float m_flActualYOffset;
private:
	uint8 m_pad1C8[ 0x08 ];
public:
	float m_flActualLayoutWidth;
	float m_flActualLayoutHeight;
private:
	uint8 m_pad1D8[ 0x18 ];
public:
	Vector m_vActualUIScale;
private:
	uint8 m_pad1FC[ 0x04 ];
public:
	void *m_pHorizontalScrollData;
	void *m_pVerticalScrollData;
	IUIScrollBar *m_pVerticalScrollBar;
	IUIScrollBar *m_pHorizontalScrollBar;
	uint16 m_unStyleFlags;
	uint16 m_unDisallowedStyleFlags;
private:
	uint8 m_pad224[ 0x04 ];
public:
	uint16 m_unNeedsIntermediateTextureFlags;
	uint8 m_nMiscBehaviorFlags;
private:
	uint8 m_pad22B[ 0x01 ];
public:
	CPanoramaSymbol m_symInputNamespace;
	CPanoramaSymbol m_symCompositionLayerTextureName;
	void *m_pMapPanelEvents;
	int32 m_nEventHandlerCount;
private:
	uint8 m_pad23C[ 0x04 ];
public:
	void *m_pEventHandlerData;
private:
	uint8 m_pad248[ 0x28 ];
public:
	void *m_pAttributeMap;
	IUIPanel *m_pParentInputContext;
private:
	uint8 m_pad280[ 0x28 ];
public:
	int32 m_nDialogVariableCount;
	uint32 m_nDialogVariableAllocFlags;
	void *m_pDialogVariableData;
	ILocVariableSource *m_pLocVariableFallback;
private:
	uint8 m_pad2C0[ 0x18 ];
public:
	IUIPanel *m_pPanelContext;
private:
	uint8 m_pad2E0[ 0x18 ];
public:
	PanelHandle_t m_hPanelHandle;
};

COMPILE_TIME_ASSERT( sizeof( CUIPanel ) == 0x300 );

} // namespace panorama

#endif
