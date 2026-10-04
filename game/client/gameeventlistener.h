#ifndef GAMEEVENTLISTENER_H
#define GAMEEVENTLISTENER_H

#ifdef _WIN32
#pragma once
#endif

#include <igameevents.h>

class CGameEventListener : public IGameEventListener2
{
public:
	bool m_bRegisteredForEvents;
};

COMPILE_TIME_ASSERT( sizeof( CGameEventListener ) == 0x10 );

#endif
