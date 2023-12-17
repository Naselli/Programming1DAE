#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											

void Start()
{
	g_FractionPtrArr[0] = new Fraction{3,5};
	g_FractionPtrArr[1] = new Fraction{2,5};
	g_FractionPtrArr[2] = new Fraction{2,3};
	g_FractionPtrArr[3] = new Fraction{2,4};
	g_FractionPtrArr[4] = new Fraction{1,4};
	g_FractionPtrArr[5] = new Fraction{1,3};

	PrintFractionSum();

	g_LightPtr = new Light{ Rectf{300, 200, 100, 100},  Color4f{1,0,0, 1}};
}
void PrintFractionSum ( )
{
	float sum{};
	for ( int fractionIndex{}; fractionIndex < NR_OF_FRACTIONS; ++fractionIndex )
	{
		sum += g_FractionPtrArr[fractionIndex]->GetValue(  );
	}

	std::cout << sum << std::endl;
};

void Draw()
{
	ClearBackground();
	SetColor(1, 0 ,0 );
	for ( int i = 0; i < NR_OF_FRACTIONS; ++i  )
	{
		g_FractionPtrArr[i]->Draw( Point2f{50,50 + ((float)i * 50)}, 50 );
		
	}
	// Put your own draw statements here

	g_LightPtr->Draw(  );

}

void Update(float elapsedSec)
{
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
	for ( int fractionsIndex{}; fractionsIndex < NR_OF_FRACTIONS; ++fractionsIndex)
	{
		delete g_FractionPtrArr[fractionsIndex];
	}

	delete g_LightPtr;
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
	g_LightPtr->OnMouseDownEvent( e );
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