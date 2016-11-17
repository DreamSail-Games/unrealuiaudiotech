#include "stdafx.h"
#include "Renderer.h"

#include "GeometricPrimitive.h"
 

using namespace DirectX;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::UI::Core;

Renderer^ Renderer::s_instance;

Renderer::Renderer()
{
	s_instance = this;
}

void Renderer::CreateDeviceResources()
{
	Direct3DBase::CreateDeviceResources();
	m_spriteFont16 = std::unique_ptr<SpriteFont>(new SpriteFont(m_d3dDevice.Get(), L"Assets\\segoeui_16.spritefont"));
	m_spriteFont24 = std::unique_ptr<SpriteFont>(new SpriteFont(m_d3dDevice.Get(), L"Assets\\segoeui_24.spritefont"));
	m_spriteBatch = std::unique_ptr<SpriteBatch>(new SpriteBatch(m_d3dContext.Get()));
}

void Renderer::CreateWindowSizeDependentResources()
{
	Direct3DBase::CreateWindowSizeDependentResources();
}

void Renderer::Update(float timeTotal, float timeDelta)
{
}

void Renderer::BeginDrawing()
{
	m_d3dContext->ClearRenderTargetView(
		m_renderTargetView.Get(),
		Colors::DarkBlue
		);

	m_d3dContext->ClearDepthStencilView(
		m_depthStencilView.Get(),
		D3D11_CLEAR_DEPTH,
		1.0f,
		0
		);

	m_d3dContext->OMSetRenderTargets(
		1,
		m_renderTargetView.GetAddressOf(),
		m_depthStencilView.Get()
		);

	m_spriteBatch->Begin();
}

void Renderer::DrawText( WCHAR * in_szText, int in_eType, int in_eColor, int in_X, int in_Y )
{
	DirectX::SpriteFont * pFont;
	switch ( in_eType )
	{
	case TextType_Title:
		pFont = m_spriteFont24.get();
		break;

	default:
		pFont = m_spriteFont16.get();
		break;
	}

	XMVECTOR vColor;
	switch ( in_eColor )
	{
	case TextColor_Selected:
		vColor = Colors::White;
		break;
	default:
		vColor = Colors::LightGray;
		break;
	}

	pFont->DrawString( m_spriteBatch.get(), in_szText, XMFLOAT2( (float) in_X, (float) in_Y ), vColor ); 
}

void Renderer::DoneDrawing()
{
	m_spriteBatch->End();
}
