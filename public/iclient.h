//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: Client-side networking interfaces reversed from CS2 engine2.dll.
//          Mirrors iserver.h (INetworkGameServer / CNetworkGameServerBase).
//
//=============================================================================//

#ifndef ICLIENT_H
#define ICLIENT_H
#ifdef _WIN32
#pragma once
#endif

#include <engine/IEngineService.h>
#include <playerslot.h>
#include <ns_address.h>

class INetChannel;
class CNetworkGameClient;
class CClientChangelevelState;
class CGlobalVars;
class IGameSpawnGroupMgr;

//-----------------------------------------------------------------------------
// Purpose: Engine-facing client interface. Implemented by CNetworkGameClientBase.
// Vtable indices are absolute (primary vtable of CNetworkGameClient, engine2.dll).
//-----------------------------------------------------------------------------
abstract_class INetworkGameClient
{
public:
	virtual void *unk000() = 0; // 0
	virtual void SetGameSpawnGroupMgr(IGameSpawnGroupMgr *pMgr) = 0; // 1
	virtual int AddRef() = 0; // 2
	virtual int Release() = 0; // 3

	// 4: returns &m_GlobalVars (embedded CGlobalVars at this+0x90). Client-side globals getter.
	virtual CGlobalVars *GetGlobals() = 0; // 4

	virtual int GetClientTickCount() = 0; // 5
	virtual int GetServerTickCount() = 0; // 6
	virtual void *unk007() = 0; // 7
	virtual void *unk008() = 0; // 8
	virtual void *unk009() = 0; // 9
	virtual void *unk010() = 0; // 10
	virtual void SetFrameTime(float flFrameTime) = 0; // 11
	virtual void Connect(int nSplitScreenSlot, int nUnk, const void *pAddr) = 0; // 12
	virtual void Disconnect(/*ENetworkDisconnectionReason*/ int reason) = 0; // 13
	virtual void *unk014() = 0; // 14
	virtual void *unk015() = 0; // 15
	virtual void *unk016() = 0; // 16
	virtual void *unk017() = 0; // 17
	virtual void *unk018() = 0; // 18
	virtual void *unk019() = 0; // 19
	virtual void *unk020() = 0; // 20
	virtual void *unk021() = 0; // 21
	virtual void ClientPollNetworking(const void *pEvent) = 0; // 22
	virtual void ClientProcessNetworking(const void *pEvent) = 0; // 23
	virtual void *unk024() = 0; // 24
	virtual void OnClientFrameSimulate(const void *pEvent) = 0; // 25
	virtual void OnClientAdvanceTick(const void *pEvent) = 0; // 26
	virtual void *unk027() = 0; // 27
	virtual void *unk028() = 0; // 28
	virtual void *unk029() = 0; // 29
	virtual void *unk030() = 0; // 30
	virtual void *unk031() = 0; // 31
	virtual void ForceFullUpdate(const char *pszReason) = 0; // 32
	virtual void *unk033() = 0; // 33
	virtual void *unk034() = 0; // 34
	virtual void *unk035() = 0; // 35
	virtual void ServerCmd(int nCommandSrc, const char *pszCmd) = 0; // 36
	virtual void *unk037() = 0; // 37
	virtual void SendStringCmd(int nSplitScreenSlot, const char *pszCmd) = 0; // 38
	virtual void SplitScreenConnect(int nSplitScreenSlot) = 0; // 39
	virtual int GetMaxSplitScreenPlayers() = 0; // 40
	virtual void *unk041() = 0; // 41
	virtual void *unk042() = 0; // 42
	virtual void *unk043() = 0; // 43
	virtual void *unk044() = 0; // 44
	virtual void *unk045() = 0; // 45
	virtual void PrepareSteamConnectResponse(uint64 nUnk, bool bUnk, const void *pAddr, void *pMsg) = 0; // 46
};

//-----------------------------------------------------------------------------
// Purpose: Concrete client base. Adds the network message Process* handlers,
// clock-drift / prediction internals and the sign-on state machine.
// (Split point between the interface and the base impl is approximate.)
//-----------------------------------------------------------------------------
class CNetworkGameClientBase : public INetworkGameClient
{
public:
	virtual void *unk047() = 0; // 47
	virtual void *unk048() = 0; // 48
	virtual void *unk049() = 0; // 49
	virtual void *unk050() = 0; // 50
	virtual void *unk051() = 0; // 51
	virtual void *unk052() = 0; // 52
	virtual void SpewSerializer(const char *pszName) = 0; // 53
	virtual void *unk054() = 0; // 54
	virtual void *unk055() = 0; // 55
	virtual void *unk056() = 0; // 56
	virtual void *StartChangeLevel() = 0; // 57
	virtual void FinishChangeLevel(void *pState) = 0; // 58
	virtual void *unk059() = 0; // 59
	virtual void *unk060() = 0; // 60
	virtual void *unk061() = 0; // 61
	virtual void *unk062() = 0; // 62
	virtual void TransmitNetChannel() = 0; // 63
	virtual void *unk064() = 0; // 64
	virtual void *unk065() = 0; // 65
	virtual void *unk066() = 0; // 66
	virtual void *unk067() = 0; // 67
	virtual void *unk068() = 0; // 68
	virtual void *unk069() = 0; // 69
	virtual void *unk070() = 0; // 70
	virtual void *unk071() = 0; // 71
	virtual void *unk072() = 0; // 72
	virtual void ApplyClockDrift(int nServerTick, int nClientTick) = 0; // 73
	virtual void *unk074() = 0; // 74
	virtual void *unk075() = 0; // 75
	virtual void *unk076() = 0; // 76
	virtual void *unk077() = 0; // 77
	virtual void *unk078() = 0; // 78
	virtual void *unk079() = 0; // 79
	virtual void *unk080() = 0; // 80
	virtual void *unk081() = 0; // 81
	virtual void *unk082() = 0; // 82
	virtual void *unk083() = 0; // 83
	virtual void *unk084() = 0; // 84
	virtual void *unk085() = 0; // 85
	virtual void *unk086() = 0; // 86
	virtual void *unk087() = 0; // 87
	virtual void ProcessTick(const void *msg) = 0; // 88
	virtual void ProcessStringCmd(const void *msg) = 0; // 89
	virtual void ProcessSetConVar(const void *msg) = 0; // 90
	virtual void ProcessSignonState(const void *msg) = 0; // 91
	virtual void *unk092() = 0; // 92
	virtual void ProcessSpawnGroup_Load(const void *msg) = 0; // 93
	virtual void ProcessSpawnGroup_ManifestUpdate(const void *msg) = 0; // 94
	virtual void ProcessSpawnGroup_Unload(const void *msg) = 0; // 95
	virtual void ProcessSpawnGroup_SetCreationTick(const void *msg) = 0; // 96
	virtual void *unk097() = 0; // 97
	virtual void *unk098() = 0; // 98
	virtual void *unk099() = 0; // 99
	virtual void *unk100() = 0; // 100
	virtual void ProcessServerInfo(const void *msg) = 0; // 101
	virtual void ProcessClassInfo(const void *msg) = 0; // 102
	virtual void *unk103() = 0; // 103
	virtual void *unk104() = 0; // 104
	virtual void *unk105() = 0; // 105
	virtual void *unk106() = 0; // 106
	virtual void *unk107() = 0; // 107
	virtual void ProcessCreateStringTable(const void *msg) = 0; // 108
	virtual void ProcessUpdateStringTable(const void *msg) = 0; // 109
	virtual void *unk110() = 0; // 110
	virtual void *unk111() = 0; // 111
	virtual void ProcessSplitScreen(const void *msg) = 0; // 112
	virtual void ProcessCmdKeyValues(const void *msg) = 0; // 113
	virtual void *unk114() = 0; // 114
	virtual void *unk115() = 0; // 115
	virtual void *unk116() = 0; // 116
	virtual void *unk117() = 0; // 117
	virtual void *unk118() = 0; // 118
	virtual void *unk119() = 0; // 119
	virtual void *unk120() = 0; // 120
	virtual void *unk121() = 0; // 121
	virtual void *unk122() = 0; // 122
	virtual void *unk123() = 0; // 123
	virtual void *unk124() = 0; // 124
	virtual void *unk125() = 0; // 125
	virtual void *unk126() = 0; // 126
	virtual void ProcessHltvReplay(const void *msg) = 0; // 127
	virtual void *unk128() = 0; // 128
	virtual void *unk129() = 0; // 129
	virtual void Clear(bool bUnk) = 0; // 130
	virtual void FullConnect(const void *pAddr) = 0; // 131
	virtual void SetSignonState(/*SignonState_t*/ int state, int nUnk, const void *pMsg) = 0; // 132
	virtual void *unk133() = 0; // 133
	virtual void *unk134() = 0; // 134
	virtual void InstallStringTableCallbacks(const char *pszTableName) = 0; // 135
	virtual void *unk136() = 0; // 136
	virtual void ProcessPacketEntities(const void *msg) = 0; // 137
	virtual void OnPreserveEntity(void *pReadInfo) = 0; // 138
	virtual void CopyNewEntity(void *pReport, void *pReadInfo, void *pClientClass, int nUnk, unsigned int nUnk2) = 0; // 139
	virtual void CopyExistingEntity(void *pReport, void *pReadInfo) = 0; // 140
	virtual void OnReceivedUncompressedPacket() = 0; // 141
	virtual void *unk142() = 0; // 142
};

// The most-derived client class. Overrides a handful of base virtuals but
// adds no new vtable slots, so it is layout-compatible with the base.
class CNetworkGameClient : public CNetworkGameClientBase
{
};

//-----------------------------------------------------------------------------
// Purpose: "NetworkClientService_001" - engine service that owns the client.
// Backed by CNetworkClientService : CBaseEngineService<INetworkClientService>.
//-----------------------------------------------------------------------------
abstract_class INetworkClientService : public IEngineService
{
public:
	virtual ~INetworkClientService() = 0; // 22

	// 23: returns m_pNetworkGameClient (this+0xA0). Verified against engine2.dll.
	virtual CNetworkGameClient *GetNetworkGameClient() = 0; // 23
};

#endif // ICLIENT_H
