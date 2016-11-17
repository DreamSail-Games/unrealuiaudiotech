#pragma once

#include "Direct3DBase.h"
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

ref class Renderer sealed : public Direct3DBase
{
public:
	Renderer();

	// Direct3DBase methods.
	virtual void CreateDeviceResources() override;
	virtual void CreateWindowSizeDependentResources() override;

	void BeginDrawing();
	void DrawText( WCHAR * in_szText, int in_eType, int in_eColor, int in_X, int in_Y );
	void DoneDrawing();
	
	// Method for updating time-dependent objects.
	void Update(float timeTotal, float timeDelta);

	static Renderer^ GetInstance() { return s_instance; }

private:
	static Renderer^ s_instance;

	std::unique_ptr<DirectX::SpriteFont> m_spriteFont16;
	std::unique_ptr<DirectX::SpriteFont> m_spriteFont24;
	std::unique_ptr<DirectX::SpriteBatch> m_spriteBatch;
};
