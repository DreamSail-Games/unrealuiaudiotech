// Drawing.cpp
// Copyright (C) 2010 Audiokinetic Inc
/// \file 
// Implements the Drawing.h functions for the Windows platform


/////////////////////////
//  INCLUDES
/////////////////////////

#include "stdafx.h"
#include "Platform.h"
#include "Drawing.h"
#include <string>
#include "Renderer.h"
#include <AK/Tools/Common/AkPlatformFuncs.h>

using std::string;

/////////////////////////
//  GLOBAL OBJECTS
/////////////////////////

Renderer ^ g_pRenderer;
       
/////////////////////////
//  FUNCTIONS
/////////////////////////

static AkUInt32 g_iWidth;
static AkUInt32 g_iHeight;

AkUInt32 GetWindowWidth()
{
	return g_iWidth;
}

AkUInt32 GetWindowHeight()
{
	return g_iHeight;
}

void BeginDrawing()
{
	Renderer::GetInstance()->BeginDrawing();
}

void DoneDrawing()
{
	Renderer::GetInstance()->DoneDrawing();
}

bool InitDrawing(
	void* in_pParam,
	AkOSChar* in_szErrorBuffer,
	unsigned int in_unErrorBufferCharCount,
	AkUInt32 in_windowWidth,
	AkUInt32 in_windowHeight
)
{
	g_iWidth = in_windowWidth;
	g_iHeight = in_windowHeight;

	return true;
}


void DrawTextOnScreen( const char* in_szText, int in_iXPos, int in_iYPos, DrawStyle in_eDrawStyle )
{
	string buffer = in_szText;

	// Replace tags in the text
	ReplaceTags( buffer );

	WCHAR szMsg[ 512 ];
	AKPLATFORM::AkCharToWideChar( buffer.c_str(), 512, szMsg );

	TextType eTextType;
	TextColor eColor = TextColor_Normal;

	switch ( in_eDrawStyle )
	{
	case DrawStyle_Title:
		eTextType = TextType_Title;
		break;
	case DrawStyle_Selected:
		eTextType = TextType_Reg;
		eColor = TextColor_Selected;
		break;
	case DrawStyle_Error:
		eTextType = TextType_Reg;
		break;
	case DrawStyle_Text:
		eTextType = TextType_Text;
		break;
	case DrawStyle_Control:
		eTextType = TextType_Reg;
		break;
	}
	Renderer::GetInstance()->DrawText( szMsg, eTextType, eColor, in_iXPos, in_iYPos );
}


void TermDrawing()
{
}


int GetLineHeight( DrawStyle in_eDrawStyle )
{
	return 24;
}