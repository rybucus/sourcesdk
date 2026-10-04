#ifndef PANORAMA_IMEUI_H
#define PANORAMA_IMEUI_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/platwindow.h>

class IIMEUIObject
{
public:
	virtual void *unk000() = 0;
};

class IIMEUITextField : public IIMEUIObject
{
public:
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
	virtual void *unk014() = 0;
	virtual void *unk015() = 0;
	virtual void *unk016() = 0;
	virtual void *unk017() = 0;
	virtual void *unk018() = 0;
	virtual void *unk019() = 0;
	virtual void *unk020() = 0;
	virtual void *unk021() = 0;
	virtual void *unk022() = 0;
	virtual void *unk023() = 0;
	virtual void *unk024() = 0;
	virtual void *unk025() = 0;
	virtual void *unk026() = 0;
	virtual void *unk027() = 0;
	virtual void *unk028() = 0;
};

class IIMEUIView
{
public:
	virtual IIMEUIObject *GetFocusedObject() = 0;
	virtual PlatWindow_t GetAssociatedPlatWindow() = 0;
};

#endif
