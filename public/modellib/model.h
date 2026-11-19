#ifndef MODELLIB_MODEL_H
#define MODELLIB_MODEL_H

#ifdef _WIN32
	#pragma once
#endif

#include <resourcefile/resourcehandle.h>
#include <resourcesystem/resourcehandletypes.h>

using HModelStrong = CStrongHandle< InfoForResourceTypeCModel >;
using HModelWeak = CWeakHandle< InfoForResourceTypeCModel >;

#endif // MODELLIB_MODEL_H
