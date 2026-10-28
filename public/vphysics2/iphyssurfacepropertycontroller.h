#ifndef IPHYSSURFACEPROPERTYCONTROLLER_H
#define IPHYSSURFACEPROPERTYCONTROLLER_H

#ifdef _WIN32
#pragma once
#endif

#include "tier0/platform.h"
#include "tier0/utlstringtoken.h"

class CPhysSurfaceProperties;

abstract_class IPhysSurfacePropertyController
{
public:
	virtual void unk000( void *p ) = 0;
	virtual CPhysSurfaceProperties *FindSurfaceProperties( CUtlStringToken token, bool *pFound ) = 0;
	virtual int GetSurfacePropertiesCount() = 0;
	virtual CPhysSurfaceProperties *GetSurfaceProperties( int nIndex ) = 0;
	virtual void unk004( void *p ) = 0;
	virtual void unk005( void *p ) = 0;
	virtual int GetSurfacePropertiesVersion() = 0;
};

#endif
