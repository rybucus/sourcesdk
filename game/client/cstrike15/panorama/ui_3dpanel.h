#ifndef UI_3DPANEL_H
#define UI_3DPANEL_H

#ifdef _WIN32
#pragma once
#endif

#include <mathlib/camera.h>
#include <mathlib/vector.h>
#include <mathlib/vector2d.h>
#include <tier1/refcount.h>
#include <tier1/utlvector.h>
#include <entityhandle.h>
#include <gameeventlistener.h>
#include <panorama/controls/renderpanel.h>

class CCS_PortraitWorld;

class ICS_PortraitWorldOwner
{
public:
	virtual void *unk000() = 0;
	virtual void *unk001() = 0;
};

class IRenderReadCallback : public CRefCounted< CRefCountServiceBase< CRefMT > >
{
public:
	virtual void *unk001() = 0;
};

class IReadTexturePixelsCallback : public IRenderReadCallback
{
public:
	virtual void *unk002() = 0;
};

class CUI_3dPanel : public panorama::CRenderPanel, public CGameEventListener, public ICS_PortraitWorldOwner, public IReadTexturePixelsCallback
{
public:
	virtual void *unk085( int nUnknown ) = 0;
	virtual void unk086() = 0;
	virtual void *unk087() = 0;
	virtual void unk088( int nUnknown0, int64 nUnknown1, float flUnknown0, float flUnknown1, float flUnknown2, float flUnknown3, int64 nUnknown2 ) = 0;
	virtual void unk089() = 0;
	virtual bool unk090() = 0;
	virtual void unk091() = 0;
	virtual bool unk092( const char *pchName, const char *pchItemId, const char *pchModel, int nFlags ) = 0;
	virtual bool unk093( const char *pchItemId ) = 0;
	virtual void unk094() = 0;
	virtual void *unk095() = 0;
	virtual bool unk096() = 0;
	virtual bool unk097() = 0;
	virtual bool unk098() = 0;
	virtual bool unk099() = 0;
	virtual void unk100() = 0;
	virtual bool SwitchMap( const char *pchMapName ) = 0;
	virtual void unk102( float flX, float flY ) = 0;
	virtual void UpdateCamera( int nWidth, int nHeight ) = 0;
	virtual void unk104() = 0;
	virtual void *unk105( int *pParams ) = 0;
	virtual bool unk106() const = 0;

private:
	uint8 m_pad058[ 0x10 ];
public:
	CCS_PortraitWorld *m_pPortraitWorld;
private:
	uint8 m_pad070[ 0x420 ];
public:
	Camera_t m_Camera;
private:
	uint8 m_pad4C0[ 0x318 ];
public:
	bool m_bDragRotate;
	bool m_bDragRotating;
private:
	uint8 m_pad7DA[ 0x2 ];
public:
	float m_flDragRotateYaw;
	float m_flDragRotateYawLimit;
	float m_flDragRotateRadius;
private:
	uint8 m_pad7E8[ 0x28 ];
public:
	bool m_bStickerApplicationMode;
	bool m_bKeychainApplicationMode;
	bool m_bApplicationMode;
private:
	uint8 m_pad813[ 0x1 ];
public:
	Vector2D m_vecApplicationPressCursor;
	Vector2D m_vecApplicationDragDelta;
	Vector2D m_vecApplicationStickerOffset;
	float m_flApplicationTouchTime;
	bool m_bApplicationDragging;
	bool m_bApplicationPressHit;
private:
	uint8 m_pad832[ 0x2 ];
public:
	float m_flApplicationWheelTime;
	float m_flApplicationStickerRotation;
private:
	uint8 m_pad83C[ 0x8 ];
public:
	bool m_bApplicationInputReady;
	bool m_bApplicationWheelReady;
private:
	uint8 m_pad846[ 0x6 ];
public:
	float m_flFOV;
	float m_flFOVWeight;
	bool m_bOverrideFOV;
private:
	uint8 m_pad855[ 0x6B ];
};

COMPILE_TIME_ASSERT( sizeof( CUI_3dPanel ) == 0x8C0 );

class CUI_Item3dPanel : public CUI_3dPanel
{
private:
	uint8 m_pad8C0[ 0x38 ];
public:
	CEntityHandle m_hItemEntity;
private:
	uint8 m_pad8FC[ 0x64 ];
public:
	int32 m_nCreateItem;
private:
	uint8 m_pad964[ 0x14C ];
public:
	CEntityHandle m_hPreviewPlayer;
	bool m_bGhostHandsApplied;
	bool m_bStartWeaponLookAt;
private:
	uint8 m_padAB6[ 0x1A ];
};

COMPILE_TIME_ASSERT( sizeof( CUI_Item3dPanel ) == 0xAD0 );

struct PreviewCharacter_t
{
	CEntityHandle m_hCharacter;
private:
	uint8 m_pad004[ 0x9C ];
};

COMPILE_TIME_ASSERT( sizeof( PreviewCharacter_t ) == 0xA0 );

class CUI_Player3dPanel : public CUI_3dPanel
{
private:
	uint8 m_pad8C0[ 0x2C ];
public:
	int32 m_nActiveCharacter;
	CUtlVector< PreviewCharacter_t > m_Characters;
private:
	uint8 m_pad908[ 0x8 ];
};

COMPILE_TIME_ASSERT( sizeof( CUI_Player3dPanel ) == 0x910 );

#endif
