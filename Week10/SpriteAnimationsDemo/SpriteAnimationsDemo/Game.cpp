#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// create title sprite
	g_TxtTitlePtr = new StringSprite(	"Sprite Animations", "Resources/Fonts/DIN-Light.otf", 
						60, Color4f{ 0.0f, 0.0f, 0.0f}, Point2f{ 20, 20});

	// g_TxtTitlePtr-> ReCreate("Sprite Animations Recreated", "Resources/Fonts/DIN-Light.otf", 
	// 					60, Color4f{ 0.0f, 0.0f, 0.0f});
	
	g_CrabSpritePtr = new Sprite( "Resources/Images/crab spritesheet.png",
						g_WindowWidth / 4, g_WindowHeight / 2, 4, 6, 0.050f);

	g_GirlSpritePtr = new Sprite("Resources/Images/walkingcycle girl.png",
						g_WindowWidth * 3 / 4, g_WindowHeight / 2, 1, 6, 0.050f);
}


void Draw()
{
	ClearBackground();

	// Draw String texture
	g_TxtTitlePtr->Draw(  );

	// Draw my sprites
	g_CrabSpritePtr->Draw();
	g_GirlSpritePtr->Draw();
}


void Update(float elapsedSec)
{
	g_CrabSpritePtr->Update(elapsedSec);
	g_GirlSpritePtr->Update(elapsedSec);
}



void End()
{
	delete g_TxtTitlePtr;

	delete g_CrabSpritePtr;
	delete g_GirlSpritePtr;
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