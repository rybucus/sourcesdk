#ifndef PANORAMA_UIENGINE_H
#define PANORAMA_UIENGINE_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/mempool.h>
#include <tier0/threadtools.h>
#include <tier0/utlstring.h>
#include <tier0/utlsymbol.h>
#include <tier1/UtlSortVector.h>
#include <tier1/utldelegate.h>
#include <tier1/utlhashmaplarge.h>
#include <tier1/utlhashtable.h>
#include <tier1/utllinkedlist.h>
#include <tier1/utlmap.h>
#include <tier1/utlpriorityqueue.h>
#include <tier1/utlrbtree.h>
#include <tier1/utlvector.h>
#include <panorama/iuiengine.h>
#include <panorama/panoramasymbol.h>
#include <panorama/panoramav8.h>

namespace panorama
{

class CTopLevelWindow;

class CChunkAllocator
{
public:
	struct Bucket_t
	{
		uint64 m_nChunkSize;
	private:
		uint8 m_pad008[ 0x10 ];
	};

	const void *m_pVTable;
	CAtomicMutex m_Mutex;
private:
	uint8 m_pad014[ 0x04 ];
public:
	uint64 m_nUnknown018;
	Bucket_t m_Buckets[ 10 ];
};

COMPILE_TIME_ASSERT( sizeof( CChunkAllocator ) == 0x110 );

struct RegisterJSEntryInfoInternal_t
{
	const char *pName;
	const char *pDescription;
	uint32 unFlags;
	RegisterJSType_t eDataType;
	uint8 unNumParams;
	RegisterJSType_t pParamTypes[ RegisterJSEntryInfo_t::k_unMaxParams ];
};

COMPILE_TIME_ASSERT( sizeof( RegisterJSEntryInfoInternal_t ) == 0x20 );

struct RegisterJSScopeInfoInternal_t
{
	const char *pName;
	const char *pDescription;
	CUtlVector< RegisterJSEntryInfoInternal_t > vecEntries;
};

COMPILE_TIME_ASSERT( sizeof( RegisterJSScopeInfoInternal_t ) == 0x28 );

class CUIEngine : public IUIEngine
{
public:
	struct HandlerCount_t
	{
		int m_nPanelHandlers;
		int m_nUnhandledHandlers;
		int m_nPanelTypeHandlers;
	};

	struct QueuedEvent_t
	{
		double flDispatch;
		IUIEvent *pEvent;

		bool operator<( const QueuedEvent_t &rhs ) const { return flDispatch < rhs.flDispatch; }
	};

	struct V8GlobalFunctionRegistration_t
	{
		CUtlString m_strName;
		v8::Global< v8::FunctionTemplate > *m_pFunction;
		bool m_bTrueGlobal;
	};

	struct V8GlobalObjectRegistration_t
	{
		CUtlString m_strName;
		v8::Global< v8::Object > *m_pObj;
		bool m_bTrueGlobal;
	};

	struct UIEventFactory_t
	{
		uint64 m_nData[ 6 ];
	};

	struct ScheduledItem_t
	{
		double m_flFrameTime;
		int m_iListIndex;
	};

	struct PanelPaintCount_t
	{
		uint32 m_unPaintsSinceReset;
		double m_flLastPaintTime;
		bool m_bLastNeededCompositionLayer;
	};

	typedef CUtlMap< IUIPanel *, uint32, int > PanelMap_t;

	static const int k_nPanelStackSize = 63;

	virtual void CopyToClipboardImpl( const char *pchTextUTF8 ) = 0;
	virtual void GetClipboardTextImpl( CUtlString &strUTF8 ) const = 0;
	virtual void OnFileCacheRemoved( CPanoramaSymbol fileSymbol ) = 0;
	virtual void ReloadChangedFile( const char *pchFile ) = 0;
	virtual void RunPlatformFrame() = 0;

	bool m_bShutdown;
	bool m_bShuttingdown;
private:
	uint8 m_pad00A[ 0x06 ];
public:
	CChunkAllocator m_ChunkAllocator;
	CUtlMemoryPoolBase m_PanelStylePool;
	CUtlVector< CTopLevelWindow * > m_vecWindows;
private:
	uint8 m_pad198[ 0x01 ];
public:
	bool m_bPaintedWindows;
private:
	uint8 m_pad19A[ 0x16 ];
public:
	double m_flCurrentFrameTime;
	double m_flLastScheduledDelRunTime;
	uint64 m_nFrameCycles;
private:
	uint8 m_pad1C8[ 0x08 ];
public:
	double m_flLastInputTime;
	bool m_bUnknown1D8;
	bool m_bDebuggerActive;
private:
	uint8 m_pad1DA[ 0x06 ];
public:
	IUIWindow *m_pDebuggerWindow;
	IUIStyleFactory *m_pStyleFactory;
	CUtlVector< PanoramaFrameFunc_t > m_vecFrameFuncs;
	PanelMap_t m_mapPanels;
	CUtlMap< IUIPanel *, CUtlString, int > m_mapMouseCanActivateIfParent;
	IUIInput *m_pInputEngine;
	IUILayoutManager *m_pUILayoutManager;
	CUtlHashMap< UtlSymId_t, void * > m_mapUnhandledEventHandlers;
	CUtlHashMap< void *, void * > m_mapUnhandledEventHandlerMessages;
	CUtlMap< IUIPanel *, void *, int > m_mapPanelToJSUnhandledEventHandlers;
	uint32 m_unNextEventHandlerId;
private:
	uint8 m_pad334[ 0x04 ];
public:
	CUtlMap< IUIPanel *, void *, int > m_mapPanelToJSGenericCallbacks;
	CUtlMap< JSGenericCallbackHandle_t, void *, int > m_AllJSGenericCallbacks;
	JSGenericCallbackHandle_t m_nNextGenericCallbackHandle;
private:
	uint8 m_pad38C[ 0x04 ];
public:
	CUtlVector< RegisterJSScopeInfoInternal_t > m_vecRegisterJSScopes;
	int m_nCurRegisterJSScope;
private:
	uint8 m_pad3AC[ 0x04 ];
public:
	CUtlHashMap< UtlSymId_t, HandlerCount_t > m_mapEventsToHandlerCounts;
	CUtlSortVector< QueuedEvent_t > m_vecQueuedEvents;
private:
	uint8 m_pad428[ 0x08 ];
public:
	uint8 m_tslNewAsyncEvents[ 0x40 ];
	uint8 m_tslQueuedDecRef[ 0x40 ];
	CUtlLinkedList< CUtlString > m_ConsoleHistory;
	IUILocalization *m_pLocalization;
	IUISoundSystem *m_pSoundSystem;
	CUtlHashtable< uint64 > m_treeCallBeforeStyleAndLayout;
	CUtlHashtable< uint64 > m_setUnknown4F8;
	CUtlHashtable< uint64 > m_treePanelsWaitingAsyncDelete;
	CUtlString m_strUnknown538;
	CUtlMap< const char *, CUtlString, int > m_dictNamedPaths;
	CUtlVector< void * > m_vecDirWatchers;
	IUISettings *m_pSettings;
	CAtomicMutex m_MutexLayersToRepaint;
private:
	uint8 m_pad594[ 0x04 ];
public:
	CUtlHashtable< uint64 > m_treeLayersToRepaint;
	uint64 m_nUnfocusedFrameCounter;
	v8::Global< v8::Context > m_V8UIEngineGlobalContext;
	v8::Global< v8::ObjectTemplate > m_V8GlobalTemplate;
	v8::Global< v8::ObjectTemplate > m_V8PanoramaTemplate;
	v8::Global< v8::ObjectTemplate > m_V8PanelStyleTemplate;
	v8::Local< v8::ObjectTemplate > m_v8ObjectTemplateSetupCur;
	const char *m_pchObjectTypeSetupCur;
	v8::Isolate *m_pV8Isolate;
	CUtlMap< CPanoramaSymbol, v8::Global< v8::FunctionTemplate > *, int > m_mapV8PanelClassTemplates;
	CUtlMap< const char *, v8::Global< v8::ObjectTemplate > *, int > m_mapV8ClassTemplatesByType;
	CUtlMap< IUIPanel *, v8::Global< v8::Context > *, int > m_MapPanelV8Contexts;
	CUtlMap< IUIPanel *, v8::Global< v8::Object > *, int > m_MapV8PanelObjectInstances;
	CUtlMap< IUIPanelStyle *, v8::Global< v8::Object > *, int > m_MapV8PanelStyleObjectInstances;
	CUtlMap< IUIWindow *, v8::Global< v8::Object > *, int > m_MapV8IUIWindowObjectInstances;
	CUtlMap< IUIPanel *, CUtlVector< IUIPanel * > *, int > m_mapOtherPanelsV8InContext;
	CUtlMap< void *, v8::Global< v8::Object > *, int > m_MapV8GlobalObjectInstances;
	CUtlVector< V8GlobalFunctionRegistration_t > m_vecV8GlobalFunctionRegistrations;
	CUtlVector< V8GlobalObjectRegistration_t > m_vecV8GlobalObjectRegistrations;
	CUtlHashMap< UtlSymId_t, void * > m_mapPanelTypeEventHandlers;
	CUtlMap< CPanoramaSymbol, UIEventFactory_t, int > m_mapEventRegistrations;
	CUtlMap< CPanoramaSymbol, CPanel2DFactory *, int > m_mapPanelRegistrations;
	bool m_bFrameFuncHasRun;
private:
	uint8 m_pad809[ 0x07 ];
public:
	CUtlPriorityQueue< ScheduledItem_t > m_QueueScheduledDelegates;
	CUtlLinkedList< CUtlDelegate< void() >, int > m_ListScheduledDelegates;
	CUtlRBTree< int, CDefLess< int >, int > m_treeScheduledJSHandles;
	uint32 m_unNextScheduledJSHandle;
private:
	uint8 m_pad86C[ 0x04 ];
public:
	IUIFileSystem *m_pFileSystem;
	CAtomicMutex m_MutexPanelPaintCounts;
private:
	uint8 m_pad884[ 0x04 ];
public:
	CUtlMap< uint64, PanelPaintCount_t, int > m_MapPanelPaintCounts;
	uint32 m_unMaxPanelPaintsSinceReset;
	bool m_bPaintCountTrackingEnabled;
private:
	uint8 m_pad8B5[ 0x03 ];
public:
	uint32 m_unClipboardHash;
private:
	uint8 m_pad8BC[ 0x04 ];
public:
	CUtlString m_sClipboardPasteStringLocToken;
	bool m_bIsReloadingScript;
private:
	uint8 m_pad8C9[ 0x0F ];
public:
	IUIPanel *m_rgContextPanels[ k_nPanelStackSize ];
	int m_nContextPanels;
private:
	uint8 m_padAD4[ 0x04 ];
public:
	CUtlSymbolTable m_SymbolTable;
	CUtlMap< const char *, v8::Global< v8::String > *, int > m_mapScriptOriginNames;
	CUtlMap< const char *, v8::Global< v8::String > *, int > m_mapCachedScriptSources;
	CUtlVector< void * > m_vecUnknownB88;
};

COMPILE_TIME_ASSERT( sizeof( CUIEngine ) == 0xBA0 );

} // namespace panorama

#endif
