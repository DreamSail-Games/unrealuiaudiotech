#include "stdafx.h"

#define AK_IMPLEMENT_THREAD_EMULATION
#include <AK/Tools/Win32/ThreadEmulation.h>

#include "Main.h"
#include "Common\DirectXHelper.h"
#include "IntegrationDemo.h"
#include "Helpers.h"
#include "InputMgr.h"
#include "Platform.h"

#include <AK/SoundEngine/Common/AkMemoryMgr.h>		// Memory Manager
#include <AK/SoundEngine/Common/AkModule.h>			// Default memory and stream managers
#include <AK/SoundEngine/Common/IAkStreamMgr.h>		// Streaming Manager
#include <AK/SoundEngine/Common/AkSoundEngine.h>    // Sound engine
#include <AK/MusicEngine/Common/AkMusicEngine.h>	// Music Engine
#include <AK/SoundEngine/Common/AkStreamMgrModule.h>	// AkStreamMgrModule

#include "AkFilePackageLowLevelIOBlocking.h"

#ifndef AK_OPTIMIZED
#include <AK/Comm/AkCommunication.h>	// Communication between Wwise and the game (excluded in release build)
#endif

using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Concurrency;

/////////////////////////////////////////////////////////////////////////////////
//                              MEMORY HOOKS SETUP
//
//                             ##### IMPORTANT #####
//
// These custom alloc/free functions are declared as "extern" in AkMemoryMgr.h / AkTypes.h
// and MUST be defined by the game developer.
/////////////////////////////////////////////////////////////////////////////////

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
	void * VirtualAllocHook(
		void * in_pMemAddress,
		size_t in_size,
		DWORD in_dwAllocationType,
		DWORD in_dwProtect
		)
	{
		return malloc( in_size );
	}
	void VirtualFreeHook( 
		void * in_pMemAddress,
		size_t in_size,
		DWORD in_dwFreeType
		)
	{
		free( in_pMemAddress );
	}
}

// Loads and initializes application assets when the application is loaded.
Main::Main(const std::shared_ptr<DX::DeviceResources>& deviceResources) :
	m_deviceResources(deviceResources)
{
	// Register to be notified if the Device is lost or recreated
	m_deviceResources->RegisterDeviceNotify(this);

	// TODO: Change the timer settings if you want something other than the default variable timestep mode.
	// e.g. for 60 FPS fixed timestep update logic, call:
	/*
	m_timer.SetFixedTimeStep(true);
	m_timer.SetTargetElapsedSeconds(1.0 / 60);
	*/

	AkMemSettings memSettings;
	AkStreamMgrSettings stmSettings;
	AkDeviceSettings deviceSettings;
	AkInitSettings initSettings;
	AkPlatformInitSettings platformInitSettings;
	AkMusicSettings musicInit;

	IntegrationDemo::Instance().GetDefaultSettings(memSettings, stmSettings, deviceSettings, initSettings, platformInitSettings, musicInit);

	const Windows::Foundation::Size & renderTargetSize = deviceResources->GetRenderTargetSize();

	AkOSChar szError[500];
	if ( !IntegrationDemo::Instance().Init( memSettings, stmSettings, deviceSettings, initSettings, platformInitSettings, musicInit, NULL, szError, IntegrationDemoHelpers::AK_ARRAYSIZE(szError), (AkUInt32) renderTargetSize.Width, (AkUInt32) renderTargetSize.Height ) )
	{
		AkOSChar szMsg[550];
		__AK_OSCHAR_SNPRINTF( szMsg, IntegrationDemoHelpers::AK_ARRAYSIZE(szMsg), AKTEXT("Failed to initialize the Integration Demo.\r\n%s"), szError );
		AKPLATFORM::OutputDebugMsg( szMsg );
	}

	Renderer::CreateInstance( deviceResources, (float) m_deviceResources->GetRenderTargetSize().Width / m_deviceResources->GetLogicalSize().Width );
}

Main::~Main()
{
	// Deregister device notification
	m_deviceResources->RegisterDeviceNotify(nullptr);

	// Terminate the various components of the application
	IntegrationDemo::Instance().Term();
}

// Updates application state when the window size changes (e.g. device orientation change)
void Main::CreateWindowSizeDependentResources() 
{
	// TODO: Replace this with the size-dependent initialization of your app's content.
	//m_sceneRenderer->CreateWindowSizeDependentResources();
}

// Updates the application state once per frame.
bool Main::Update() 
{
	return IntegrationDemo::Instance().Update();
}

// Renders the current frame according to the current application state.
// Returns true if the frame was rendered and is ready to be displayed.
bool Main::Render() 
{
	auto context = m_deviceResources->GetD3DDeviceContext();

	// Reset the viewport to target the whole screen.
	auto viewport = m_deviceResources->GetScreenViewport();
	context->RSSetViewports(1, &viewport);

	IntegrationDemo::Instance().Render();
	IntegrationDemo::Instance().EndFrame();

	return true;
}

// Notifies renderers that device resources need to be released.
void Main::OnDeviceLost()
{
	//m_sceneRenderer->ReleaseDeviceDependentResources();
	//m_fpsTextRenderer->ReleaseDeviceDependentResources();
}

// Notifies renderers that device resources may now be recreated.
void Main::OnDeviceRestored()
{
	//m_sceneRenderer->CreateDeviceDependentResources();
	//m_fpsTextRenderer->CreateDeviceDependentResources();
	CreateWindowSizeDependentResources();
}
