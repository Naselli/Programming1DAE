#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											

void Start()
{
	for (int i{}; i < 50; ++i)
		std::cout << RollD6(2) << std::endl;
	// initialize game resources here
}

void Draw()
{
	ClearBackground();
	SetColor(1, 0, 0) ;
	// Draw the 2D6 array results
	for (int index{}; index	< MAX_ELEMENTS_2D6; ++index)
	{
		FillRect( 
			DRAW_X_BASE, 
			DRAW_2D6_Y_BASE + index * (DRAW_LINE_HEIGHT + DRAW_LINE_SPACING), 
			g_Results2D6Arr[index], 
			DRAW_LINE_HEIGHT);
	}

	SetColor(0,0,1);
	// Draw the 1d6 array results
	for (int index{}; index < MAX_ELEMENTS_1D6; ++index)
	{
		FillRect(
			DRAW_X_BASE, 
			DRAW_1D6_Y_BASE + index * (DRAW_LINE_HEIGHT + DRAW_LINE_SPACING), 
			g_Results1D6Arr[index], 
			DRAW_LINE_HEIGHT);
	}

}


int RollD6(int nrDice)
{
	int result{};

	for (int counter{}; counter < nrDice; ++counter)
		result += rand() % 6 + 1;
	

	return result;
}

void Update(float elapsedSec)
{
	const int result1d6 { RollD6()  };
	const int result2d6 { RollD6(2) };

	g_Results1D6Arr[result1d6 - 1]++;
	g_Results2D6Arr[result2d6 - 2]++;
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