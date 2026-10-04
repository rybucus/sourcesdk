#ifndef PANORAMA_TEXTENTRY_H
#define PANORAMA_TEXTENTRY_H

#ifdef _WIN32
#pragma once
#endif

#include <panorama/controls/panel2d.h>
#include <panorama/imeui.h>

namespace panorama
{

class ITextInputControl
{
public:
	virtual void *unk000() = 0;
	virtual void *unk001() = 0;
	virtual void *unk002() = 0;
	virtual void *unk003() = 0;
	virtual void *unk004() = 0;
	virtual void *unk005() = 0;
	virtual void *unk006() = 0;
	virtual void *unk007() = 0;
	virtual void *unk008() = 0;
	virtual void *unk009() = 0;
	virtual void *unk010() = 0;
	virtual void *unk011() = 0;
	virtual void *unk012() = 0;
	virtual void *unk013() = 0;
};

class CTextEntry : public CPanel2D, public ITextInputControl, public IIMEUITextField
{
public:
	virtual void SetCursorOffset( int32 nCursorOffset ) = 0;
	virtual bool unk085( void *pUnknown ) = 0;

private:
	uint8 m_pad030[ 0x0E ];
public:
	bool m_bMayDrawOutsideBounds;
private:
	uint8 m_pad03F[ 0x11 ];
public:
	int32 m_nCharCount;
private:
	uint8 m_pad054[ 0x3C ];
public:
	int32 m_nCursorOffset;
private:
	uint8 m_pad094[ 0x14C ];
};

COMPILE_TIME_ASSERT( sizeof( CTextEntry ) == 0x1E0 );

} // namespace panorama

#endif
