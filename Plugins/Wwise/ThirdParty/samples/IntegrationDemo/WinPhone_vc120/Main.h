#pragma once

#include "Common\StepTimer.h"
#include "Common\DeviceResources.h"
#include "Renderer.h"

// Renders Direct2D and 3D content on the screen.
class Main : public DX::IDeviceNotify
{
public:
	Main(const std::shared_ptr<DX::DeviceResources>& deviceResources);
	~Main();
	void CreateWindowSizeDependentResources();
	bool Update();
	bool Render();

	// IDeviceNotify
	virtual void OnDeviceLost();
	virtual void OnDeviceRestored();

private:
	// Cached pointer to device resources.
	std::shared_ptr<DX::DeviceResources> m_deviceResources;

	// Rendering loop timer.
	DX::StepTimer m_timer;
	Renderer * m_pRenderer;
};
