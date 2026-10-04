#ifndef PANORAMA_PANORAMAV8_H
#define PANORAMA_PANORAMAV8_H

#ifdef _WIN32
#pragma once
#endif

namespace v8
{

class Context;
class Function;
class FunctionTemplate;
class Isolate;
class Object;
class ObjectTemplate;
class String;
class TryCatch;
class Value;

template < class T >
class Local
{
public:
	Local() : m_pValue( nullptr ) {}

	T *m_pValue;
};

template < class T >
class Global
{
public:
	Global() : m_pValue( nullptr ) {}

	T *m_pValue;
};

} // namespace v8

#endif
