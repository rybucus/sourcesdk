#ifndef IMATERIALSYSTEM2_H
#define IMATERIALSYSTEM2_H

#ifdef _WIN32
	#pragma once
#endif

#include "imaterial2.h"

#include <resourcefile/resourcehandle.h>
#include <resourcefile/resourcetype.h>

#include <tier0/platform.h>

class KeyValues3;

//-----------------------------------------------------------------------------
// Source 2 material system, exposed as MATERIAL_SYSTEM2_INTERFACE_VERSION
// ( see g_pMaterialSystem2 ).
//
// Reconstructed vtable. Every slot is kept in its verified index; slots whose
// purpose is unknown are placeholders named after their index. Do not reorder,
// remove or collapse them. No base class is declared because the inheritance
// chain has not been verified - the placeholders cover whatever occupies the
// leading slots.
//-----------------------------------------------------------------------------
abstract_class IMaterialSystem2
{
public:
	virtual void Unk_Slot0( void *p ) = 0;										// 0
	virtual void Unk_Slot1( void *p ) = 0;										// 1
	virtual void Unk_Slot2( void *p ) = 0;										// 2
	virtual void Unk_Slot3( void *p ) = 0;										// 3
	virtual void Unk_Slot4( void *p ) = 0;										// 4
	virtual void Unk_Slot5( void *p ) = 0;										// 5
	virtual void Unk_Slot6( void *p ) = 0;										// 6
	virtual void Unk_Slot7( void *p ) = 0;										// 7
	virtual void Unk_Slot8( void *p ) = 0;										// 8
	virtual void Unk_Slot9( void *p ) = 0;										// 9
	virtual void Unk_Slot10( void *p ) = 0;										// 10
	virtual void Unk_Slot11( void *p ) = 0;										// 11
	virtual void Unk_Slot12( void *p ) = 0;										// 12
	virtual void Unk_Slot13( void *p ) = 0;										// 13
	virtual void Unk_Slot14( void *p ) = 0;										// 14
	virtual void Unk_Slot15( void *p ) = 0;										// 15
	virtual void Unk_Slot16( void *p ) = 0;										// 16
	virtual void Unk_Slot17( void *p ) = 0;										// 17
	virtual void Unk_Slot18( void *p ) = 0;										// 18
	virtual void Unk_Slot19( void *p ) = 0;										// 19
	virtual void Unk_Slot20( void *p ) = 0;										// 20
	virtual void Unk_Slot21( void *p ) = 0;										// 21
	virtual void Unk_Slot22( void *p ) = 0;										// 22
	virtual void Unk_Slot23( void *p ) = 0;										// 23
	virtual void Unk_Slot24( void *p ) = 0;										// 24
	virtual void Unk_Slot25( void *p ) = 0;										// 25
	virtual void Unk_Slot26( void *p ) = 0;										// 26
	virtual void Unk_Slot27( void *p ) = 0;										// 27

	// Creates a material derived from an already loaded one, applying overrides on top of it.
	virtual ResourceHandle_t *CreateMaterialFromMaterial( HMaterialStrong *pOutMaterial, const char *pMaterialName, ResourceHandle_t hSrcMaterial, KeyValues3 *pOverrides, int nFlags, bool bUnk ) = 0;	// 28

	// Creates a material from scratch out of a KeyValues3 description.
	virtual ResourceHandle_t *CreateMaterial( HMaterialStrong *pOutMaterial, const char *pMaterialName, KeyValues3 *pData, int nFlags, bool bUnk ) = 0;											// 29
};

#endif // IMATERIALSYSTEM2_H
