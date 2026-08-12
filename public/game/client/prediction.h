#ifndef PREDICTION_H
#define PREDICTION_H

#ifdef _WIN32
	#pragma once
#endif

#include <globalvars_base.h>

#include <tier0/platform.h>
#include <tier1/utlvector.h>

class CBaseEntity;
class CBasePlayerController;
// CPrediction lives in the client module, so this is the client command layout.
// Named directly rather than through the CUserCmd alias, which cannot be
// forward declared.
class C_CSGOUserCmd;
struct PostDataUpdateCall_t;

// Reason passed to the engine-side client prediction entry point.
enum PredictionReason_t : int
{
	PREDICTION_REASON_CLIENT_COMMAND_TICK = 0,
};

//-----------------------------------------------------------------------------
// Per-split-screen-slot prediction state.
//
// Reconstructed layout: only the offsets below are verified. The total size of
// this structure is NOT verified, so the stride used by CUtlVector< PredictionSplit_t >
// is an assumption; do not rely on it for anything other than the first element.
//-----------------------------------------------------------------------------
struct PredictionSplit_t
{
	uint8 m_nUnknown0000[0x10];							// 0x0000 - 0x000F

	CBasePlayerController *m_pController;				// 0x0010
	uint8 m_nUnknown0018[0x28];							// 0x0018 - 0x003F

	int m_nPredictedEntityCount;						// 0x0040
	uint8 m_nUnknown0044[0x4];							// 0x0044 - 0x0047
	CBaseEntity **m_ppPredictedEntities;				// 0x0048
	uint8 m_nUnknown0050[0x28];							// 0x0050 - 0x0077

	int m_nLastExecutedCommand;							// 0x0078
	int m_nBasePredictedCommand;						// 0x007C
	int m_nLastPredictedCommand;						// 0x0080
};

COMPILE_TIME_ASSERT( offsetof( PredictionSplit_t, m_pController ) == 0x10 );
COMPILE_TIME_ASSERT( offsetof( PredictionSplit_t, m_nPredictedEntityCount ) == 0x40 );
COMPILE_TIME_ASSERT( offsetof( PredictionSplit_t, m_ppPredictedEntities ) == 0x48 );
COMPILE_TIME_ASSERT( offsetof( PredictionSplit_t, m_nLastExecutedCommand ) == 0x78 );
COMPILE_TIME_ASSERT( offsetof( PredictionSplit_t, m_nBasePredictedCommand ) == 0x7C );
COMPILE_TIME_ASSERT( offsetof( PredictionSplit_t, m_nLastPredictedCommand ) == 0x80 );

//-----------------------------------------------------------------------------
// Client side prediction manager, exposed by the client module as
// SOURCE2CLIENTPREDICTION_INTERFACE_VERSION ( see g_pClientSidePrediction ).
//
// Reconstructed from client.dll. The class has two vtables - the engine only
// ever reaches it through the primary one, which is the 32-slot table declared
// below; the secondary vtable pointer sits at 0x0028 and is left as an opaque
// member because its slots have not been reconstructed.
//
// Every slot is kept in its verified index. Slots whose purpose is unknown are
// placeholders named after their index - do not reorder, remove or collapse
// them. Where a placeholder's signature was recovered from the decompiler it is
// declared with that signature; the Unk_ prefix only means the NAME is
// unverified.
//
// Only the field offsets marked below are verified, and the total size of the
// class is NOT verified.
//-----------------------------------------------------------------------------
class CPrediction
{
public:
	virtual bool Unk_Slot0( void *p ) = 0;										// 0
	virtual void Unk_Slot1( void *p ) = 0;										// 1
	virtual void Unk_Slot2() = 0;												// 2  empty body
	virtual void Unk_Slot3( void *p ) = 0;										// 3
	virtual void Unk_Slot4( void *p ) = 0;										// 4
	virtual void Unk_Slot5() = 0;												// 5  empty body
	virtual void Unk_Slot6() = 0;												// 6  empty body
	virtual int Unk_Slot7() = 0;												// 7  returns the constant 4
	virtual void Unk_Slot8( void *p ) = 0;										// 8
	virtual bool Unk_Slot9() = 0;												// 9  returns the constant 1
	virtual int Unk_Slot10() = 0;												// 10 returns the constant 2

	// Runs a full prediction pass. engine2!CNetworkGameClient::ClientSidePredict
	// calls this through vtable+0x58 while m_bInSimulation is forced true.
	virtual void Update( PredictionReason_t nReason ) = 0;						// 11

	virtual void NetUpdatePreStart() = 0;										// 12
	virtual void NetUpdateStart() = 0;											// 13
	virtual void PostEntityPacketReceived() = 0;								// 14
	virtual void PostNetworkDataReceived( const PostDataUpdateCall_t *pCalls, uint64 nCount ) = 0;	// 15

	virtual void Unk_Slot16( void *p ) = 0;										// 16
	virtual void Unk_Slot17( void *p ) = 0;										// 17
	virtual void Unk_Slot18( void *p ) = 0;										// 18
	virtual void Unk_Slot19( void *p ) = 0;										// 19
	virtual int Unk_Slot20() = 0;												// 20 returns the int at 0x00EC
	virtual void Unk_Slot21( void *p ) = 0;										// 21
	virtual void Unk_Slot22( void *p ) = 0;										// 22
	virtual void Unk_Slot23( void *p ) = 0;										// 23
	virtual void Unk_Slot24( void *p ) = 0;										// 24
	virtual void Unk_Slot25( void *p ) = 0;										// 25

	// Convar-backed gate. engine2 calls this through vtable+0xD0 to decide
	// whether to Msg() the "pred reason %s -- start/finish" lines around Update().
	virtual bool Unk_Slot26() = 0;												// 26

	virtual void Unk_Slot27( void *p ) = 0;										// 27
	virtual void Unk_Slot28( void *p ) = 0;										// 28
	virtual bool Unk_Slot29() = 0;												// 29
	virtual void Unk_Slot30( void *p ) = 0;										// 30
	virtual void Unk_Slot31( void *p ) = 0;										// 31

public:
	uint8 m_nUnknown0008[0x20];							// 0x0008 - 0x0027 ( 0x0000 holds the primary vtable pointer )
	void *m_pSecondaryVTable;							// 0x0028

	PredictionReason_t m_nPredictionReason;				// 0x0030
	bool m_bInPrediction;								// 0x0034
	bool m_bIsEnginePaused;								// 0x0035
	uint8 m_nUnknown0036[0x2];							// 0x0036 - 0x0037

	C_CSGOUserCmd *m_pPredictionCommand;				// 0x0038

	bool m_bPrintDebug;									// 0x0040
	uint8 m_nUnknown0041[0x3];							// 0x0041 - 0x0043
	int m_nSnapshotTick;								// 0x0044
	uint8 m_nUnknown0048[0x8];							// 0x0048 - 0x004F

	CUtlVector< PredictionSplit_t > m_Splits;			// 0x0050
	CGlobalVarsBase m_SavedVars;						// 0x0068
	uint8 m_nUnknown00C8[0x28];							// 0x00C8 - 0x00EF

	bool m_bPredictionStateChanged;						// 0x00F0
	uint8 m_nUnknown00F1[0x1B];							// 0x00F1 - 0x010B
	int m_nPredictedTickBase;							// 0x010C
};

COMPILE_TIME_ASSERT( offsetof( CPrediction, m_pSecondaryVTable ) == 0x28 );
COMPILE_TIME_ASSERT( offsetof( CPrediction, m_nPredictionReason ) == 0x30 );
COMPILE_TIME_ASSERT( offsetof( CPrediction, m_bInPrediction ) == 0x34 );
COMPILE_TIME_ASSERT( offsetof( CPrediction, m_bIsEnginePaused ) == 0x35 );
COMPILE_TIME_ASSERT( offsetof( CPrediction, m_pPredictionCommand ) == 0x38 );
COMPILE_TIME_ASSERT( offsetof( CPrediction, m_bPrintDebug ) == 0x40 );
COMPILE_TIME_ASSERT( offsetof( CPrediction, m_nSnapshotTick ) == 0x44 );
COMPILE_TIME_ASSERT( offsetof( CPrediction, m_Splits ) == 0x50 );
COMPILE_TIME_ASSERT( offsetof( CPrediction, m_SavedVars ) == 0x68 );
COMPILE_TIME_ASSERT( offsetof( CPrediction, m_bPredictionStateChanged ) == 0xF0 );
COMPILE_TIME_ASSERT( offsetof( CPrediction, m_nPredictedTickBase ) == 0x10C );

#endif // PREDICTION_H
