// Platform.cpp
// Copyright (C) 2010 Audiokinetic Inc
/// \file 
/// Contains definitions for functions declared in Platform.h

#include "stdafx.h"
#include "Platform.h"
#include "UniversalInput.h"
#include <AK/Tools/Common/AkPlatformFuncs.h>

class RenderingEngine;
RenderingEngine*	g_renderingEngine = NULL;
UGBtnState			g_btnState = 0;
UGStickState		g_sticksState[2];
char				g_szBasePath[AK_IOS_MAX_BANK_PATH];
char				g_szDocumentsPath[AK_IOS_MAX_DOCUMENTS_PATH];
unsigned int g_windowWidth;
unsigned int g_windowHeight;

UInt32 g_uSamplesPerFrame = 512;