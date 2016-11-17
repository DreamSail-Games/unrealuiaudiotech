// stdafx.h
// Copyright (C) 2010 Audiokinetic Inc
/// \file 
/// Precompiled Header File for the Integration Demo application.

#pragma once

////////////////////////////////////////////
// Helper Includes
////////////////////////////////////////////

#include <cmath>
#include <cstdio>
#include <cassert>

#include <CoreAudio/AudioHardware.h>
//#include <CAHostTimeBase.h>

#include <AK/SoundEngine/Common/AkTypes.h>
#include <AK/Tools/Common/AkPlatformFuncs.h>

#ifdef AK_SOUNDINPUT_DEBUG
	#undef AK_OPTIMIZED
#endif //ifdef AK_SOUNDINPUT_DEBUG


#define AK_MALLOC(nBytes) malloc(nBytes)
#define AK_MALLOC_ARRAY(arraySize, dataType) malloc(arraySize*sizeof(dataType))
#define AK_SAFE_FREE(pointer) free(pointer); pointer = NULL

#define AK_NEW(type) new type
#define AK_SAFE_DELETE(obj) delete obj; obj = NULL 

#define AK_MEMSET_ZERO(array, arraySize, dataType) memset(array, 0, arraySize*sizeof(dataType))
#define AK_MEMCPY(destArray, srcArray, nArrayBytes) memcpy(destArray, srcArray, nArrayBytes) 

#define DEFAULT_MESSAGE_SIZE 256
#define ERROR_NO_ERROR "No Error"

typedef Float32 CoreAudioNativeFormat;
typedef AkInt16 AkSrcCommonFormat;
typedef unsigned int MacUInt;
typedef int MacInt;
typedef double MacFloat64;

