#ifndef UILENGTH_H
#define UILENGTH_H

#ifdef _WIN32
#pragma once
#endif

#include <float.h>

namespace panorama
{

const float k_flFloatAuto = FLT_MAX;
const float k_flFloatNotSet = FLT_MIN;

class CUILength
{
public:
	enum EUILengthTypes
	{
		k_EUILengthUnset,
		k_EUILengthLength,
		k_EUILengthPercent,
		k_EUILengthFitChildren,
		k_EUILengthFillParentFlow,
		k_EUILengthHeightPercentage,
		k_EUILengthWidthPercentage,
	};

	CUILength() : m_flValue( k_flFloatNotSet ), m_eType( k_EUILengthUnset ) {}
	CUILength( float flValue, EUILengthTypes eType ) : m_flValue( flValue ), m_eType( eType ) {}

	bool IsSet() const { return m_eType != k_EUILengthUnset; }
	bool IsLength() const { return m_eType == k_EUILengthLength; }
	bool IsPercent() const { return m_eType == k_EUILengthPercent; }
	bool IsFitChildren() const { return m_eType == k_EUILengthFitChildren; }
	bool IsFillParentFlow() const { return m_eType == k_EUILengthFillParentFlow; }
	bool IsHeightPercentage() const { return m_eType == k_EUILengthHeightPercentage; }
	bool IsWidthPercentage() const { return m_eType == k_EUILengthWidthPercentage; }

	float GetValue() const { return m_flValue; }
	EUILengthTypes GetType() const { return m_eType; }

	void SetFitChildren() { Set( k_flFloatAuto, k_EUILengthFitChildren ); }
	void SetLength( float flValue ) { Set( flValue, k_EUILengthLength ); }
	void SetPercent( float flValue ) { Set( flValue, k_EUILengthPercent ); }
	void SetFillParentFlow( float flWeight ) { Set( flWeight, k_EUILengthFillParentFlow ); }
	void SetHeightPercentage( float flValue ) { Set( flValue, k_EUILengthHeightPercentage ); }
	void SetWidthPercentage( float flValue ) { Set( flValue, k_EUILengthWidthPercentage ); }

	void Set( float flValue, EUILengthTypes eType )
	{
		m_flValue = flValue;
		m_eType = eType;
	}

	bool operator==( const CUILength &rhs ) const { return m_flValue == rhs.m_flValue && m_eType == rhs.m_eType; }
	bool operator!=( const CUILength &rhs ) const { return !operator==( rhs ); }

	static CUILength Length( float flValue ) { return CUILength( flValue, k_EUILengthLength ); }
	static CUILength Percent( float flValue ) { return CUILength( flValue, k_EUILengthPercent ); }

private:
	float m_flValue;
	EUILengthTypes m_eType;
};

COMPILE_TIME_ASSERT( sizeof( CUILength ) == 8 );

} // namespace panorama

#endif
