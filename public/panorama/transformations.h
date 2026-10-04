#ifndef PANORAMA_TRANSFORMATIONS_H
#define PANORAMA_TRANSFORMATIONS_H

#ifdef _WIN32
#pragma once
#endif

#include <mathlib/vector.h>
#include <panorama/layout/uilength.h>

namespace panorama
{

class CTransform3D
{
public:
	const void *m_pVTable;
};

class CTransformTranslate3D : public CTransform3D
{
public:
	CUILength m_x;
	CUILength m_y;
	CUILength m_z;
};

class CTransformScale3D : public CTransform3D
{
public:
	Vector m_VecScale;
};

COMPILE_TIME_ASSERT( sizeof( CTransformTranslate3D ) == 32 );
COMPILE_TIME_ASSERT( sizeof( CTransformScale3D ) == 24 );

} // namespace panorama

#endif
