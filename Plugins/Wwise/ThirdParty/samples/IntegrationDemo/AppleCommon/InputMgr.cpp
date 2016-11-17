// InputMgr.cpp
// Copyright (C) 2010 Audiokinetic Inc 
/// \file 
/// Defines the methods declared in InputMgr.h

#include "stdafx.h"
#include "InputMgr.h"

extern UGBtnState g_btnState;
extern UGStickState	g_sticksState[2];

InputMgr::~InputMgr()
{
}

bool InputMgr::Init(
	void* in_pParam,
	AkOSChar* in_szErrorBuffer,
	unsigned int in_unErrorBufferCharCount
)
{
	g_btnState = 0;
	m_pUInput = new UniversalInput;
	m_pUInput->AddDevice( 1 , UGDeviceType_GAMEPAD );
	memset(g_sticksState, 0, sizeof(g_sticksState));
	
	return true;
}

UniversalInput* InputMgr::UniversalInputAdapter() const
{
	return m_pUInput;
}


void InputMgr::Update()
{
	m_pUInput->SetState( 1, true, g_btnState, g_sticksState );
	g_btnState = 0;
}

void InputMgr::Release()
{
	if ( m_pUInput )
	{
		delete m_pUInput;
		m_pUInput = NULL;
	}
}

void InputMgr::TranslateInput( int in_iPlayerIndex )
{
}
