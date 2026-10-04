#ifndef PANORAMA_UIENGINESOURCE2_H
#define PANORAMA_UIENGINESOURCE2_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/threadtools.h>
#include <tier1/utlmap.h>
#include <tier1/utlvector.h>
#include <resourcefile/resourcetype.h>
#include <panorama/uiengine.h>

class IToolsResourceListener
{
public:
	virtual void *unk000() = 0;
	virtual void *unk001() = 0;
};

class IRenderDeviceEventListener
{
public:
	virtual void *unk000() = 0;
	virtual void *unk001() = 0;
	virtual void *unk002() = 0;
	virtual void *unk003() = 0;
};

class ITextureResidencyListener
{
public:
	virtual void *unk000() = 0;
	virtual void *unk001() = 0;
};

namespace panorama
{

class CImageResourceManager;
class CUIRenderDeviceSource2;

class CUIEngineSource2 : public CUIEngine, public IToolsResourceListener, public IRenderDeviceEventListener, public ITextureResidencyListener
{
public:
	virtual bool BInitialize() = 0;

	bool m_bInShutdown;
private:
	uint8 m_padBB9[ 0x07 ];
public:
	void *m_pUnknownBC0[ 6 ];
	CUIRenderDeviceSource2 *m_pRenderDevice;
	CImageResourceManager *m_pImageResourceManager;
	CAtomicMutex m_Mutex;
private:
	uint8 m_padC0C[ 0x04 ];
public:
	CUtlMap< ResourceHandle_t, void *, int > m_MonitoredResources;
	void *m_hRequiredManifest;
	CUtlVector< void * > m_QueuedResourceReloads;
private:
	uint8 m_padC58[ 0x08 ];
};

COMPILE_TIME_ASSERT( sizeof( CUIEngineSource2 ) == 0xC60 );

} // namespace panorama

#endif
