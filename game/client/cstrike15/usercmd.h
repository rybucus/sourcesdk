#ifndef CSTRIKE15_CLIENT_USERCMD_H
#define CSTRIKE15_CLIENT_USERCMD_H

#pragma once

#include "../../shared/cstrike15/usercmd.h"

enum CmdPredictionReason_t : int
{
	CMD_PREDICTION_REASON_OUT_OF_RANGE = 0,
	CMD_PREDICTION_REASON_REPREDICT = 1,
	CMD_PREDICTION_REASON_NEW_COMMAND = 2,
	CMD_PREDICTION_REASON_STALE_RERUN = 3,
};

//-----------------------------------------------------------------------------
// Client side user command, as laid out by the client module.
//
// The client stores per-command prediction bookkeeping where the server keeps
// its list links.
//-----------------------------------------------------------------------------
class C_CSGOUserCmd : public CUserCmdBaseHost< CSGOUserCmdPB >
{
public:
	CInButtonState m_ButtonStates;

private:
	// Not part of the player message.
	char unknown[8];

public:
	double m_flExecutionTime;
	float m_flCurrentTime;
	bool m_bHasBeenPredicted;
	CmdPredictionReason_t m_nPreviousPredictionReason;
	CmdPredictionReason_t m_nPredictionReason;
};

// Cross-checked against the client command ring buffer, which holds 150 entries.
COMPILE_TIME_ASSERT( sizeof( C_CSGOUserCmd ) == 0x98 );

#endif // CSTRIKE15_CLIENT_USERCMD_H
