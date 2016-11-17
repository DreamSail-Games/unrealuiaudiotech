// Platform.cpp
// Copyright (C) 2011 Audiokinetic Inc
/// \file 
/// Contains definitions for functions declared in Platform.h

#include "stdafx.h"
#include "Platform.h"
#include "UniversalInput.h"
#include <AK/Tools/Common/AkPlatformFuncs.h>

class RenderingEngine;
RenderingEngine*	g_renderingEngine = NULL;

// Globals variable for the input manager
UGBtnState			g_btnState = 0;
UGStickState		g_sticksState[2];

UInt32 g_uSamplesPerFrame = 512;

// Alloc hook that need to be define by the game
namespace AK
{
	void * AllocHook( size_t in_size )
	{
		return malloc( in_size );
	}
	void FreeHook( void * in_ptr )
	{
		free( in_ptr );
	}
}
