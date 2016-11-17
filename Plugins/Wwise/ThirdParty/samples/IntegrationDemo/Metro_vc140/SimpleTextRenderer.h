#pragma once

#include <string>
#include "..\Common\DeviceResources.h"
#include "..\Common\StepTimer.h"

enum TextType
{
	TextType_Reg,
	TextType_Title,
	TextType_Text
};

enum TextColor
{
	TextColor_Normal,
	TextColor_Selected
};

// This class renders simple text with a colored background.
class SimpleTextRenderer 
{
public:
	SimpleTextRenderer(const std::shared_ptr<DX::DeviceResources>& deviceResources);
	void CreateDeviceDependentResources();
	void ReleaseDeviceDependentResources();

	void BeginDrawing();
	void DrawText( WCHAR * in_szText, int in_eType, int in_eColor, int in_X, int in_Y );
	void DoneDrawing();

	// Methods to save and load state in response to suspend.
	void SaveInternalState(Windows::Foundation::Collections::IPropertySet^ state);
	void LoadInternalState(Windows::Foundation::Collections::IPropertySet^ state);

	static SimpleTextRenderer* GetInstance() { return s_instance; }

private:
	// Cached pointer to device resources.
	std::shared_ptr<DX::DeviceResources> m_deviceResources;

	static SimpleTextRenderer* s_instance;

	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> m_textBrush[ 2 ];
	Microsoft::WRL::ComPtr<IDWriteTextFormat> m_textFormat[ 3 ];
	bool m_renderNeeded;
};
