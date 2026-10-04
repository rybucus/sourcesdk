#ifndef PANORAMA_DROPDOWN_H
#define PANORAMA_DROPDOWN_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/utlstring.h>
#include <panorama/controls/panel2d.h>
#include <panorama/controls/panelptr.h>

namespace panorama
{

class CDropDownMenu;

class CDropDown : public CPanel2D
{
public:
	virtual void unk084() = 0;

	CPanelPtr< CDropDownMenu > m_pMenu;
	CPanelPtr< CPanel2D > m_pSelected;
	bool m_bSuppressClick;
private:
	uint8 m_pad031[ 0x07 ];
public:
	CUtlString m_strInitialSelection;
	CUtlString m_strDefaultSelection;
};

class CDropDownMenu : public CPanel2D
{
public:
	virtual void unk084() = 0;

	CDropDown *m_pDropDown;
	CPanelPtr< CPanel2D > m_pSelectedChild;
private:
	uint8 m_pad030[ 0x08 ];
};

COMPILE_TIME_ASSERT( sizeof( CDropDown ) == 0x48 );
COMPILE_TIME_ASSERT( sizeof( CDropDownMenu ) == 0x38 );

} // namespace panorama

#endif
