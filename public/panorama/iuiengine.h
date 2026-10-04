#ifndef PANORAMA_IUIENGINE_H
#define PANORAMA_IUIENGINE_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/platform.h>
#include <tier0/platwindow.h>
#include <tier0/utlstring.h>
#include <tier1/UtlSortVector.h>
#include <tier1/utldelegate.h>
#include <tier1/utllinkedlist.h>
#include <tier1/utlvector.h>
#include <panorama/controls/panelhandle.h>
#include <panorama/panoramasymbol.h>
#include <panorama/panoramatypes.h>
#include <panorama/panoramav8.h>

class CRefCount;
class IConCommandBaseAccessor;
class ISteamHTMLSurface;

struct InputContextHandle_t__;
typedef InputContextHandle_t__ *InputContextHandle_t;

namespace panorama
{

class CPanel2DFactory;
class IUIEvent;
class IUIFileSystem;
class IUIImageManager;
class IUIInput;
class IUIJSObject;
class IUILayoutManager;
class IUILocalization;
class IUIPanel;
class IUIPanelClient;
class IUIPanelStyle;
class IUISettings;
class IUISoundSystem;
class IUIStyleFactory;
class IUITextLayout;
class IUIWindow;

typedef void ( *PanoramaFrameFunc_t )();

typedef int JSGenericCallbackHandle_t;
const JSGenericCallbackHandle_t JS_GENERIC_CALLBACK_HANDLE_INVALID = -1;

struct ScriptSourceLocation_t
{
	int32 m_nLine;
	int32 m_nColumn;
};

COMPILE_TIME_ASSERT( sizeof( ScriptSourceLocation_t ) == 8 );

struct RegisterJSScopeInfo_t
{
	const char *pName;
	const char *pDescription;
	int nEntries;
};

enum RegisterJSType_t : uint8
{
	k_ERegisterJSTypeUnknown,
	k_ERegisterJSTypeInvalid,
	k_ERegisterJSTypeVoid,
	k_ERegisterJSTypeBool,
	k_ERegisterJSTypeInt8,
	k_ERegisterJSTypeUint8,
	k_ERegisterJSTypeInt16,
	k_ERegisterJSTypeUint16,
	k_ERegisterJSTypeInt32,
	k_ERegisterJSTypeUint32,
	k_ERegisterJSTypeInt64,
	k_ERegisterJSTypeUint64,
	k_ERegisterJSTypeFloat,
	k_ERegisterJSTypeDouble,
	k_ERegisterJSTypeConstString,
	k_ERegisterJSTypePanoramaSymbol,
	k_ERegisterJSTypeRawV8Args,
	k_ERegisterJSTypeScaleformCompatAccessor,
	k_ERegisterJSTypeScaleformCompatArgs,
	k_ERegisterJSTypeUtlString,

	k_ERegisterJSTypeMax,
};

struct RegisterJSEntryInfo_t
{
	enum
	{
		k_EGlobalFunction = 0x00000000,
		k_EMethod = 0x00000001,
		k_EAccessor = 0x00000002,
		k_EAccessorReadOnly = 0x00000003,
		k_EConstantValue = 0x00000004,
		k_EEntryTypeMask = 0x0000000f,
	};

	static const uint8 k_unNumParamsUnknown = 0xff;
	static const uint8 k_unMaxParams = 10;

	const char *pName;
	const char *pDescription;
	uint32 unFlags;
	RegisterJSType_t eDataType;
	uint8 unNumParams;
	RegisterJSType_t pParamTypes[ k_unMaxParams ];
	const char *pParamNames[ k_unMaxParams ];
};

class IUIEngine
{
public:
	enum ENativeMessageBoxType_t
	{
		k_ENativeMessageOk = 1,
		k_ENativeMessageYesNo = 2,
	};

	virtual ~IUIEngine() {}
	virtual bool StartupSubsystems( IUISettings *pSettings, PlatWindow_t hWindow ) = 0;
	virtual void ConCommandInit( IConCommandBaseAccessor *pAccessor ) = 0;
	virtual void Shutdown() = 0;
	virtual void RequestShutdown() = 0;
	virtual void RunFrame() = 0;
	virtual bool BIsRunning() = 0;
	virtual bool BHasFocus() = 0;
	virtual double GetCurrentFrameTime() = 0;
	virtual IUIWindow *CreateNewUILayerWindow( uint32 xPos, uint32 yPos, uint32 width, uint32 height, bool bFixedSurfaceSize, bool bEnforceWindowAspectRatio, bool bUseCustomMouseCursor, const char *pName, InputContextHandle_t hInputContext ) = 0;
	virtual IUIWindow *CreateNewOffscreenUIWindow( uint32 width, uint32 height, const char *pName, InputContextHandle_t hInputContext, bool bDrawToBackBuffer ) = 0;
	virtual IUIWindow *unk011( const char *pName ) = 0;
	virtual bool DestroyWindow( IUIWindow *pWindow ) = 0;
	virtual IUITextLayout *CreateTextLayout( const char *pchText, const char *pchFontName, float flSize, const void *pUnknown, bool bUnknown0, bool bUnknown1, bool bUnknown2, bool bUnknown3, bool bUnknown4, bool bUnknown5, int nUnknown0, int nUnknown1, int nUnknown2, int nUnknown3 ) = 0;
	virtual IUITextLayout *CreateTextLayout( const wchar_t *pch16Text, const char *pchFontName, float flSize, const void *pUnknown, bool bUnknown0, bool bUnknown1, bool bUnknown2, bool bUnknown3, bool bUnknown4, bool bUnknown5, int nUnknown0, int nUnknown1, int nUnknown2, int nUnknown3 ) = 0;
	virtual IUITextLayout *CreateTextLayout( const uint32 *pch32Text, const char *pchFontName, float flSize, const void *pUnknown, bool bUnknown0, bool bUnknown1, bool bUnknown2, bool bUnknown3, bool bUnknown4, bool bUnknown5, int nUnknown0, int nUnknown1, int nUnknown2, int nUnknown3 ) = 0;
	virtual void FreeTextLayout( IUITextLayout *pLayout ) = 0;
	virtual const CUtlSortVector< CUtlString > &GetSortedValidFontNames() = 0;
	virtual IUIInput *UIInputEngine() = 0;
	virtual IUILocalization *UILocalize() = 0;
	virtual IUISoundSystem *UISoundSystem() = 0;
	virtual IUISettings *UISettings() = 0;
	virtual IUILayoutManager *UILayoutManager() = 0;
	virtual IUIFileSystem *UIFileSystem() = 0;
	virtual IUIImageManager *UIImageManager() = 0;
	virtual void RegisterFrameFunc( PanoramaFrameFunc_t frameFunc ) = 0;
	virtual void ReloadLayoutFile( CPanoramaSymbol symPath ) = 0;
	virtual void ToggleDebugMode() = 0;
	virtual CUtlLinkedList< CUtlString > &GetConsoleHistory() = 0;
	virtual void *unk029( CPanoramaSymbol symPanelType, void *pUnknown ) = 0;
	virtual IUIPanel *CreatePanel( IUIWindow *pWindow ) = 0;
	virtual void PanelDestroyed( IUIPanel *pPanel, IUIPanel *pOldParent ) = 0;
	virtual bool IsValidPanelPointer( const IUIPanel *pPanel ) = 0;
	virtual PanelHandle_t GetPanelHandle( const IUIPanel *pPanel ) = 0;
	virtual IUIPanel *GetPanelPtr( const PanelHandle_t &handle ) = 0;
	virtual void CallBeforeStyleAndLayout( IUIPanel *pPanel ) = 0;
	virtual void unk036( IUIPanel *pPanel ) = 0;
	virtual void RegisterEventHandler( CPanoramaSymbol symMsg, IUIPanel *pPanel, CUtlAbstractDelegate pFunc ) = 0;
	virtual void UnregisterEventHandler( CPanoramaSymbol symMsg, IUIPanel *pPanel, CUtlAbstractDelegate pFunc ) = 0;
	virtual void RegisterEventHandler( CPanoramaSymbol symMsg, IUIPanelClient *pPanel, CUtlAbstractDelegate pFunc ) = 0;
	virtual void UnregisterEventHandler( CPanoramaSymbol symMsg, IUIPanelClient *pPanel, CUtlAbstractDelegate pFunc ) = 0;
	virtual void UnregisterEventHandlersForPanel( IUIPanel *pPanel ) = 0;
	virtual void RegisterForUnhandledEvent( CPanoramaSymbol symMsg, CUtlAbstractDelegate pFunc, bool bUnknown ) = 0;
	virtual void UnregisterForUnhandledEvent( CPanoramaSymbol symMsg, CUtlAbstractDelegate pFunc ) = 0;
	virtual void UnregisterForUnhandledEvents( void *pEventHandler ) = 0;
	virtual bool BHaveEventHandlersRegisteredForType( CPanoramaSymbol symPanelType ) = 0;
	virtual void RegisterPanelTypeEventHandler( CPanoramaSymbol symMsg, CPanoramaSymbol symPanelType, CUtlAbstractDelegate pFunc, bool bThisPtrIsUIPanel = false ) = 0;
	virtual bool DispatchEvent( IUIEvent **ppEvent ) = 0;
	virtual void DispatchEventAsync( float flDelay, IUIEvent **ppEvent ) = 0;
	virtual void LayoutAndPaintWindows() = 0;
	virtual void RegisterNamedLocalPath( const char *pathName, const char *pchLocalPath ) = 0;
	virtual void RegisterCustomFontPath( const char *pchFontPath ) = 0;
	virtual void GetLocalPathForRelativePath( const char *pchLocalPathName, const char *pchRelativePathname, CUtlString &strLocalPath ) = 0;
	virtual ISteamHTMLSurface *AccessHTMLController() = 0;
	virtual bool ShowNativeTopMostMessageBox( const char *pchMsg, const char *pchTitle, ENativeMessageBoxType_t eType ) = 0;
	virtual void RegisterMouseCanActivateParent( IUIPanel *pPanel, const char *pchParent ) = 0;
	virtual void UnregisterMouseCanActivateParent( IUIPanel *pPanel ) = 0;
	virtual const char *GetMouseCanActivateParent( IUIPanel *pPanel ) = 0;
	virtual bool BAnyWindowHasFocus() = 0;
	virtual bool BAnyVisibleWindowHasFocus() = 0;
	virtual IUIWindow *GetFocusedWindow() = 0;
	virtual double GetLastInputTime() = 0;
	virtual void UpdateLastInputTime() = 0;
	virtual void ClearClipboard() = 0;
	virtual void CopyToClipboard( const char *pchTextUTF8, const char *pchClipboardPasteStringLocToken ) = 0;
	virtual void GetClipboardText( CUtlString &strUTF8, CUtlString *out_psPasteStringLocToken ) const = 0;
	virtual int GetDisplayLanguage() = 0;
	virtual int GetCurrentInputLocale() = 0;
	virtual bool BHaveInputLocale( int language ) = 0;
	virtual void SetInputLocale( int language ) = 0;
	virtual IUIPanelStyle *AllocPanelStyle( IUIPanel *pPanel ) = 0;
	virtual void FreePanelStyle( IUIPanelStyle *pStyle ) = 0;
	virtual void SetPanelWaitingAsyncDelete( IUIPanel *pPanel ) = 0;
	virtual bool BIsPanelWaitingAsyncDelete( IUIPanel *pPanel ) = 0;
	virtual void MarkLayerToRepaintThreadSafe( uint64 ulCompositionLayerID ) = 0;
	virtual bool AddDirectoryChangeWatch( const char *pchPath ) = 0;
	virtual uint32 GetWheelScrollLines() = 0;
	virtual void RunScript( IUIPanel *pPanelContext, const char *pchScriptString, const char *pchSourceFilename, ScriptSourceLocation_t sourceLocation ) = 0;
	virtual void RunFunction( IUIPanel *pPanelContext, v8::Global< v8::Function > *pFunction, int nNumArgs, v8::Local< v8::Value > *pArgs, bool bPrintReturnValue ) = 0;
	virtual void ExposeObjectTypeToJavaScript( const char *pchObjectTypeName, CUtlAbstractDelegate &del ) = 0;
	virtual bool IsObjectTypeExposedToJavaScript( const char *pchObjectTypeName ) = 0;
	virtual void ExposeGlobalObjectToJavaScript( const char *pchJSVarName, void *pInstance, const char *pchJsTypeName, bool bTrueGlobal = false ) = 0;
	virtual void ClearGlobalObjectForJavaScript( const char *pchJSVarName, void *pInstance ) = 0;
	virtual void DeleteJSObjectInstance( IUIJSObject *pInstance ) = 0;
	virtual IUIPanel *GetPanelForJavaScriptContext( v8::Context *pContext ) = 0;
	virtual v8::Global< v8::Context > *GetJavaScriptContextForPanel( IUIPanel *pPanel ) = 0;
	virtual void OutputJSExceptionToConsole( v8::TryCatch &tryCatch, IUIPanel *pPanelContext ) = 0;
	virtual void AddGlobalV8FunctionTemplate( const char *pchJSFuncName, v8::Local< v8::FunctionTemplate > *pFunc, bool bTrueGlobal = false ) = 0;
	virtual v8::Global< v8::Context > &GetV8GlobalContext() = 0;
	virtual v8::Local< v8::ObjectTemplate > GetCurrentV8ObjectTemplateToSetup() = 0;
	virtual const char *unk090() = 0;
	virtual IUIStyleFactory *UIStyleFactory() = 0;
	virtual v8::Isolate *GetV8Isolate() = 0;
	virtual void *unk093() = 0;
	virtual v8::Global< v8::Object > *CreateV8PanelInstance( IUIPanel *pPanel ) = 0;
	virtual v8::Global< v8::Object > *CreateV8PanelStyleInstance( IUIPanelStyle *pPanelStyle ) = 0;
	virtual v8::Global< v8::Object > *CreateV8IUIWindowInstance( IUIWindow *pWindow ) = 0;
	virtual v8::Global< v8::Object > *CreateV8ObjectInstance( const char *pchObjectType, void *pActualObject, IUIJSObject *pJSObject ) = 0;
	virtual void RegisterEventWithEngine( CPanoramaSymbol symEvent, const void *pFactory ) = 0;
	virtual bool IsValidEventName( CPanoramaSymbol symEvent ) = 0;
	virtual bool IsValidPanelEvent( CPanoramaSymbol symEvent, int *pParams ) = 0;
	virtual IUIEvent **CreateInputEventFromSymbol( IUIEvent **ppEvent, CPanoramaSymbol symEvent, IUIPanel *pPanel, EPanelEventSource_t eSource, int nRepeats ) = 0;
	virtual IUIEvent **CreateEventFromString( IUIEvent **ppEvent, IUIPanel *pCreatingPanel, const char *pchEvent, const char **pchEventEnd ) = 0;
	virtual bool CreateEventsFromString( void *pOutVecUIEvents, IUIPanel *pCreatingPanel, const char *pchEvent, const char **pchEventEnd ) = 0;
	virtual void RegisterPanelFactoryWithEngine( CPanoramaSymbol symPanelType, CPanel2DFactory *pFactory ) = 0;
	virtual bool BRegisteredPanelType( CPanoramaSymbol symPanelType ) = 0;
	virtual void CreateDebuggerWindow() = 0;
	virtual void CloseDebuggerWindow() = 0;
	virtual bool unk108() = 0;
	virtual void unk109( bool bUnknown ) = 0;
	virtual int RegisterScheduledDelegate( double flTargetFrameTime, CUtlDelegate< void() > del ) = 0;
	virtual void CancelScheduledDelegate( int iScheduleIndex ) = 0;
	virtual double GetLastScheduledDelegateRunTime() = 0;
	virtual CPanoramaSymbol MakeSymbol( const char *pchText ) = 0;
	virtual UtlSymId_t MakeTableSymbol( EPanoramaSymbolTable eTable, const char *pchText ) = 0;
	virtual UtlSymId_t FindTableSymbol( EPanoramaSymbolTable eTable, const char *pchText ) = 0;
	virtual const char *ResolveTableSymbol( EPanoramaSymbolTable eTable, UtlSymId_t sym ) = 0;
	virtual void QueueDecrementRefNextFrame( CRefCount *pRefCountObj ) = 0;
	virtual JSGenericCallbackHandle_t RegisterJSGenericCallback( IUIPanel *pContextPanel, v8::Local< v8::Function > callbackFunc ) = 0;
	virtual bool InvokeJSGenericCallback( JSGenericCallbackHandle_t nHandle, int nArgs = 0, v8::Local< v8::Value > *pArgs = nullptr, v8::Local< v8::Value > *pOutRetVal = nullptr ) = 0;
	virtual void UnregisterJSGenericCallback( JSGenericCallbackHandle_t nHandle ) = 0;
	virtual int GetNumRegisterJSScopes() = 0;
	virtual void GetRegisterJSScopeInfo( int nScope, RegisterJSScopeInfo_t *pInfo ) = 0;
	virtual void GetRegisterJSEntryInfo( int nScope, int nEntry, RegisterJSEntryInfo_t *pInfo ) = 0;
	virtual int StartRegisterJSScope( const char *pName, const char *pDesc = nullptr ) = 0;
	virtual void EndRegisterJSScope() = 0;
	virtual int NewRegisterJSEntry( const char *pName, uint32 unFlags, const char *pDesc = nullptr, RegisterJSType_t eDataType = k_ERegisterJSTypeUnknown ) = 0;
	virtual void SetRegisterJSEntryParams( int nEntry, uint8 unNumParams, RegisterJSType_t *pParamTypes ) = 0;
	virtual bool BMatchDomainForJSRequest( IUIPanel *pContextPanel, const char *pchURL ) = 0;
	virtual void ClearFileCache() = 0;
	virtual void PrintCacheStatus() = 0;
	virtual void GetWindowsForDebugger( CUtlVector< IUIWindow * > &vecWindows ) = 0;
	virtual void SetPaintCountTrackingEnabled( bool bEnablePaintCountTracking ) = 0;
	virtual bool GetPaintCountTrackingEnabled() = 0;
	virtual void IncrementPaintCountForPanel( uint64 ulPanelPtrValue, bool bRequiredCompositionLayer, double flFrameTime ) = 0;
	virtual void GetPanelPaintInfo( uint64 ulPanelPtrValue, uint32 &unMaxPanelPaintCount, uint32 &unPaintCount, bool &bRequiredCompositionLayer, double &flFrameTimeLastPaint ) = 0;
	virtual bool BHasAnyWindows() = 0;
	virtual void unk137() = 0;
	virtual void unk138() = 0;
	virtual void unk139( IUIPanel *pPanel ) = 0;
	virtual void unk140( IUIPanel *pPanel ) = 0;
	virtual void CaptureJSStackTrace( bool bPrint = false ) = 0;
	virtual void unk142() = 0;
	virtual void unk143( void *pUnknown ) = 0;
};

} // namespace panorama

#endif
