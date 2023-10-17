#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	InitPacman(  );
}

void Draw()
{
	ClearBackground(0.f,0.f,0.f);
    DrawPacman(  );
	// Put your own draw statements here

}

void Update(float elapsedSec)
{

	UpdatePacman(  );
	// process input, do physics 


	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	
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

void InitPacman()
{
	g_PacmanPos.x = g_WindowWidth / 2;
	g_PacmanPos.y = g_WindowHeight / 2;
}

void DrawPacman()
{
	const float pi{ 3.1415f };
	const float mouthSize{ pi / 2.5f }; // angle size of mouth opening
	const float pacmanSize{ 2 * pi - mouthSize };

	const float directionAngle{ 0.f }; // looks towards the right
	const float startAngle{ mouthSize / 2 + directionAngle };

	SetColor(1.f, 0.87f, 0.f);
	FillArc(g_PacmanPos, g_PacmanRadius, g_PacmanRadius, startAngle, startAngle + pacmanSize);
}

void UpdatePacman()
{
	const float speed{ 2 };

}


#pragma endregion ownDefinitions