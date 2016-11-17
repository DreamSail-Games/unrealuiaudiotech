#include "stdafx.h"
#include "Renderer.h"

#include "GeometricPrimitive.h"
 

using namespace DirectX;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::UI::Core;

std::unique_ptr<Renderer> Renderer::s_instance;

Renderer::Renderer( const std::shared_ptr<DX::DeviceResources> & in_deviceResources, float in_fScale )
	: m_deviceResources( in_deviceResources )
	, m_fScale( in_fScale )
{
	CreateDeviceResources();
}

void Renderer::CreateDeviceResources()
{
	m_spriteFont16 = std::unique_ptr<SpriteFont>(new SpriteFont(m_deviceResources->GetD3DDevice(), L"Assets\\segoeui_16.spritefont"));
	m_spriteFont24 = std::unique_ptr<SpriteFont>(new SpriteFont(m_deviceResources->GetD3DDevice(), L"Assets\\segoeui_24.spritefont"));
	m_spriteBatch = std::unique_ptr<SpriteBatch>(new SpriteBatch(m_deviceResources->GetD3DDeviceContext()));
}

void Renderer::CreateWindowSizeDependentResources()
{
}

void Renderer::Update(float timeTotal, float timeDelta)
{
}

void Renderer::BeginDrawing()
{
	m_deviceResources->GetD3DDeviceContext()->ClearRenderTargetView(
		m_deviceResources->GetBackBufferRenderTargetView(),
		Colors::DarkBlue
		);

	m_deviceResources->GetD3DDeviceContext()->ClearDepthStencilView(
		m_deviceResources->GetDepthStencilView(),
		D3D11_CLEAR_DEPTH,
		1.0f,
		0
		);

	ID3D11RenderTargetView * pTargets[ 1 ];
	pTargets[ 0 ] = m_deviceResources->GetBackBufferRenderTargetView();

	m_deviceResources->GetD3DDeviceContext()->OMSetRenderTargets(
		1,
		pTargets,
		m_deviceResources->GetDepthStencilView()
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

	pFont->DrawString( m_spriteBatch.get(), in_szText, XMFLOAT2( (float) in_X, (float) in_Y ), vColor, 0.0f, XMFLOAT2( 0.0f, 0.0f ), m_fScale ); 
}

void Renderer::DoneDrawing()
{
	m_spriteBatch->End();
}
