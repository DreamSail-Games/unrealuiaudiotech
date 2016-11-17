#pragma once

#include "Common\DeviceResources.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"

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

class Renderer 
{
public:
	Renderer( const std::shared_ptr<DX::DeviceResources> & in_pDeviceResources, float in_fScale );

	// Direct3DBase methods.
	virtual void CreateDeviceResources();
	virtual void CreateWindowSizeDependentResources();

	void BeginDrawing();
	void DrawText( WCHAR * in_szText, int in_eType, int in_eColor, int in_X, int in_Y );
	void DoneDrawing();
	
	// Method for updating time-dependent objects.
	void Update(float timeTotal, float timeDelta);

	static void CreateInstance( const std::shared_ptr<DX::DeviceResources> & in_deviceResources, float in_fScale ) { s_instance = std::make_unique<Renderer>( in_deviceResources, in_fScale ); }
	static Renderer& GetInstance() { return *s_instance; }

	float GetScale() { return m_fScale; }

private:
	static std::unique_ptr<Renderer> s_instance;

	std::shared_ptr<DX::DeviceResources> m_deviceResources;
	std::unique_ptr<DirectX::SpriteFont> m_spriteFont16;
	std::unique_ptr<DirectX::SpriteFont> m_spriteFont24;
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;

	float m_fScale;
};
