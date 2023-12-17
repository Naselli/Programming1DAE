#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// load texture from string
	TextureFromString(	"Sprite Animations", "Resources/Fonts/DIN-Light.otf", 
						60, Color4f{ 0.0f, 0.0f, 0.0f}, g_TextureString);
	
	g_CrabSprite.Start( "Resources/Images/crab spritesheet.png",
						g_WindowWidth / 4, g_WindowHeight / 2, 4, 6, 0.050f);

	g_GirlSprite.Start("Resources/Images/walkingcycle girl.png",
						g_WindowWidth * 3 / 4, g_WindowHeight / 2, 1, 6, 0.050f);
}

void Sprite::Start(const std::string& texturePath,
				float x, float y, int rows, int columns, float frameDelay)
{
	// initialize crab data
	TextureFromFile(texturePath, m_Texture);
	m_Location.x = x;
	m_Location.y = y;
	m_Rows = rows;
	m_Columns = columns;
	m_FrameWidth = m_Texture.width / m_Columns;
	m_FrameHeight = m_Texture.height / m_Rows;
	m_FrameDelay = frameDelay;
}

void Draw()
{
	ClearBackground();

	// Draw String texture
	DrawTexture(g_TextureString, Point2f{ 20, 20 });

	// Draw my sprites
	g_CrabSprite.Draw();
	g_GirlSprite.Draw();
}

void Sprite::Draw()
{
	const int rowIndex{ m_CurrentFrame / m_Columns };
	const int colIndex{ m_CurrentFrame % m_Columns };

	const Rectf sourceRect{ colIndex * m_FrameWidth,
							rowIndex * m_FrameHeight,
							m_FrameWidth,
							m_FrameHeight };

	DrawTexture(m_Texture, m_Location, sourceRect);
}

void Update(float elapsedSec)
{
	g_CrabSprite.Update(elapsedSec);
	g_GirlSprite.Update(elapsedSec);
}

void Sprite::Update(float elapsedSec)
{
	m_AccumulatedTime += elapsedSec;

	if (m_AccumulatedTime > m_FrameDelay)
	{
		++m_CurrentFrame;
		if (m_CurrentFrame >= m_Rows * m_Columns)
		{
			m_CurrentFrame = 0;
		}
		m_AccumulatedTime -= m_FrameDelay;
	}
}

void End()
{
	DeleteTexture(g_TextureString);

	g_CrabSprite.End();
	g_GirlSprite.End();
}

void Sprite::End()
{
	DeleteTexture(m_Texture);
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	// SAMPLE CODE: print mouse position
	//const float mouseX{ float(e.x) };
	//const float mouseY{ float(e.y) };
	//std::cout << "  [" << mouseX << ", " << mouseY << "]\n";
	
	// SAMPLE CODE: check which mouse button was pressed
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//	//std::cout << "Left mouse button released\n";
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions