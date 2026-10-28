#ifndef TRACE_DATA_H
#define TRACE_DATA_H

#ifdef _WIN32
#pragma once
#endif

#include "entityhandle.h"
#include "gametrace.h"
#include "mathlib/vector.h"
#include "tier1/utlvector.h"

struct TraceInterval_t
{
	Vector m_vHitNormal;
	float m_flFraction;
	union
	{
		const CHitBox *m_pHitbox;
		HPhysicsBody m_hBody;
	};
	HPhysicsShape m_hShape;
	int32 m_unk001;
	int32 m_nTriangle;
	int16 m_nHitboxBoneIndex;
	CEntityHandle m_hEntity;
	CPhysSurfacePropertyHandle m_hSurfaceProperties;
	bool m_bIsExit;
	bool m_bIsHitbox;
};

COMPILE_TIME_ASSERT( sizeof( TraceInterval_t ) == 0x38 );

enum PenetrationResultFlags_t
{
	PENETRATION_RESULT_SOLID = 1 << 0,
};

struct PenetrationResult_t
{
	float m_flEnterFraction;
	float m_flExitFraction;
	float m_flDamage;
	int32 m_nPenetrations;
	uint16 m_nEnterIndex;
	uint16 m_nTraceIndex;
	uint8 m_nFlags;
};

COMPILE_TIME_ASSERT( sizeof( PenetrationResult_t ) == 0x18 );

struct PenetrationState_t
{
	float m_flDamage;
	float m_flPenetration;
	float m_flRangeModifier;
	float m_flRayLength;
	int m_nPenetrationsLeft;
	bool m_bStop;
};

COMPILE_TIME_ASSERT( sizeof( PenetrationState_t ) == 0x18 );

struct PenetrationTrace_t
{
	Vector m_vEnter;
	Vector m_vExit;
	float m_flLength;
	float m_flDamage;
	float m_flUnk020;
	float m_flUnk024;
	const CPhysSurfaceProperties *m_pSurfaceProperties;
	uint64 m_nUnk030;
};

COMPILE_TIME_ASSERT( sizeof( PenetrationTrace_t ) == 0x38 );

inline constexpr bool k_bCreateTraceNoReset = true;

struct TraceData_t
{
	CUtlVectorFixedGrowable< TraceInterval_t, 128 > m_Intervals;
	bool m_bEndsInSolid;
	CUtlVectorFixedGrowable< PenetrationResult_t, 8 > m_Results;
	Vector m_vStart;
	Vector m_vDelta;
	float m_flEndFraction = 1.0f;
	bool m_bUnk1D14;
};

COMPILE_TIME_ASSERT( sizeof( TraceData_t ) == 0x1d18 );

#endif
