#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Sprite Animations Demo - Hoefman, Kevin - DAE" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Structs and Enum Classes
struct Sprite
{
	void Start(	const std::string& texturePath, 
				float x, float y, 
				int rows, int columns, float frameDelay);
	void Draw();
	void Update(float elapsedSec);
	void End();

	Texture		m_Texture;
	Point2f		m_Location;
	int			m_Rows, m_Columns;
	int			m_FrameWidth, m_FrameHeight;
	float		m_FrameDelay;
	float		m_AccumulatedTime;
	int			m_CurrentFrame;
};

// Constants

// Declare your own global variables here
Texture g_TextureString{};

Sprite g_GirlSprite{}, g_CrabSprite{};

// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
