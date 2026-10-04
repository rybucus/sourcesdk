#ifndef PANORAMA_LABEL_H
#define PANORAMA_LABEL_H

#ifdef _WIN32
#pragma once
#endif

#include <localize/ilocalize.h>
#include <panorama/controls/panel2d.h>

namespace panorama
{

class CLabel : public CPanel2D, public ILocalizeTextQuery
{
public:
	enum ETextType
	{
		k_ETextTypeNone,
		k_ETextTypePlain,
		k_ETextTypeUnlocalized,
		k_ETextTypeHTML,
	};

	virtual void SetText( const char *pchValue, ETextType eTextType = k_ETextTypeNone ) = 0;
	virtual void AppendText( const char *pchValue, ETextType eTextType = k_ETextTypeNone ) = 0;
	virtual const char *PchGetText() const = 0;
	virtual bool BAcceptsFocus() = 0;
	virtual void SetTextFromJS( const char *pchValue ) = 0;

private:
	uint8 m_pad028[ 0x48 ];
public:
	bool m_bMayDrawOutsideBounds;
	bool m_bAllowTextSelection;
private:
	uint8 m_pad072[ 0x0E ];
public:
	void *m_pLocText;
private:
	uint8 m_pad088[ 0x80 ];
};

COMPILE_TIME_ASSERT( sizeof( CLabel ) == 0x108 );

} // namespace panorama

#endif
