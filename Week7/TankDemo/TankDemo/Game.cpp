#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	TextureFromFile("Resources/Graphics/Tank.png", g_TextureTankData);
	g_FrameWidth = g_TextureTankData.height / NR_ROWS;
}	

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	//DrawTexture(g_TextureTankData, Point2f{0,0}, Rectf{0, 0, 300, 300} );
	PaintTank();
}

void PaintTank()
{
	const float yPos{ int(g_TankData.direction) * g_FrameWidth };
	const Rectf SOURCE_RECT{ 0, yPos, g_FrameWidth, g_FrameWidth };

	DrawTexture(g_TextureTankData,
		Point2f{g_TankData.position.x - g_FrameWidth / 2,
		g_TankData.position.y - g_FrameWidth / 2},
		SOURCE_RECT);
}

void PaintBullet()
{

}
void Update(float elapsedSec)
{
	// process input, do physics 
	UpdateTank( elapsedSec );
	UpdateBullet( elapsedSec );
}

void UpdateTank(float elapsedSec)
{
	// e.g. Check keyboard state
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	// check the keys 
	const bool isUp {		bool(pStates[SDL_SCANCODE_UP])};
	const bool isDown {		bool(pStates[SDL_SCANCODE_DOWN])};
	const bool isLeft {		bool(pStates[SDL_SCANCODE_LEFT])};
	const bool isRight {	bool(pStates[SDL_SCANCODE_RIGHT])};

	// update direction
	if ( isUp )
	{
		if ( isLeft )		g_TankData.direction = Direction::UpLeft;
		else if ( isRight ) g_TankData.direction = Direction::UpRight;
		else				g_TankData.direction = Direction::Up;
	}

	else if (isDown)
	{
		if ( isLeft )		g_TankData.direction = Direction::DownLeft;
		else if ( isRight ) g_TankData.direction = Direction::DownRight;
		else				g_TankData.direction = Direction::Down;
	}
	else if (isLeft) g_TankData.direction = Direction::Left;
	else if (isRight) g_TankData.direction = Direction::Right;

	if ( isUp ) g_TankData.position.y -= g_TankData.SPEED * elapsedSec;
	if ( isDown ) g_TankData.position.y += g_TankData.SPEED * elapsedSec;
	if ( isLeft ) g_TankData.position.x -= g_TankData.SPEED * elapsedSec;
	if ( isRight ) g_TankData.position.x += g_TankData.SPEED * elapsedSec;
	
	/*
	//update position
	switch ( m_TankData.direction ) {
		case Direction::Up:
			m_TankData.position.y -= m_TankData.SPEED;
		break;
		case Direction::UpRight:
			m_TankData.position.y -= m_TankData.SPEED / 2;
			m_TankData.position.x += m_TankData.SPEED / 2;
		break;
		case Direction::Right:
			m_TankData.position.x += m_TankData.SPEED;
			break;
		case Direction::DownRight:
			m_TankData.position.y += m_TankData.SPEED / 2;
			m_TankData.position.x += m_TankData.SPEED / 2;
			break;
		case Direction::Down:
			m_TankData.position.y += m_TankData.SPEED;
			break;
		case Direction::DownLeft:
			m_TankData.position.x -= m_TankData.SPEED / 2;
			m_TankData.position.y += m_TankData.SPEED / 2 ;
		break;
		case Direction::Left:
			m_TankData.position.x -= m_TankData.SPEED;
			break;
		case Direction::UpLeft:
			m_TankData.position.x -= m_TankData.SPEED / 2;
			m_TankData.position.y -= m_TankData.SPEED / 2;
			break;
		default: ;
	}*/
}
void UpdateBullet(float elapsedSec)
{
	
}


void End()
{
	// free game resources here
	DeleteTexture(g_TextureTankData);
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