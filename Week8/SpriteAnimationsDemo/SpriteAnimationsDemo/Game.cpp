#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// load texture from string
	TextureFromString(
		"Animations",
		"Resources/Fonts/DIN-Light.otf",
		50,
		Color4f{0,0,0},
		g_TextureString);

	// inintialize crab data
	TextureFromFile(
		"Resources/Images/crab spritesheet.png",
		g_CrabSpriteData.texture );
	g_CrabSpriteData.location.x = g_WindowWidth / 4;
	g_CrabSpriteData.location.y = g_WindowHeight / 2;
	g_CrabSpriteData.rows = 4;
	g_CrabSpriteData.columns = 6;
	g_CrabSpriteData.frameWidth = g_CrabSpriteData.texture.width / g_CrabSpriteData.columns;
	g_CrabSpriteData.frameHeight = g_CrabSpriteData.texture.height / g_CrabSpriteData.rows;
	g_CrabSpriteData.frameDelay = 0.050f; // in milliseconds
	
	// initialize girl data
	TextureFromFile(
		"Resources/Images/walkingcycle girl.png",
		g_GirlSpriteData.texture );
	g_GirlSpriteData.location.x = g_WindowWidth  * 3 / 4;
	g_GirlSpriteData.location.y = g_WindowHeight / 2;
	g_GirlSpriteData.rows = 1;
	g_GirlSpriteData.columns = 6;
	g_GirlSpriteData.frameWidth = g_GirlSpriteData.texture.width / g_GirlSpriteData.columns;
	g_GirlSpriteData.frameHeight = g_GirlSpriteData.texture.height / g_GirlSpriteData.rows;
	g_GirlSpriteData.frameDelay = 0.020f; // in milliseconds
	

	
}

void Draw()
{
	ClearBackground();

	// Draw String texture
	DrawTexture( g_TextureString, Point2f{20, 20} );


	// Crab draw
	const int rowIndexCrab		{ (g_CrabSpriteData.currentFrame / g_CrabSpriteData.rows) * g_CrabSpriteData.frameHeight };
	const int columnIndexCrab	{ (g_CrabSpriteData.currentFrame % g_CrabSpriteData.columns) * g_CrabSpriteData.frameWidth};
	
	const Rectf crabSourceRect{
	rowIndexCrab,
	columnIndexCrab,
		g_CrabSpriteData.frameWidth,
		g_CrabSpriteData.frameHeight
	};
		
	DrawTexture(
		g_CrabSpriteData.texture,
		g_CrabSpriteData.location,
		crabSourceRect
		);

	// Girl draw
	const int rowIndexGirl		{ (g_GirlSpriteData.currentFrame / g_GirlSpriteData.rows) * g_GirlSpriteData.frameHeight };
	const int columnIndexGirl	{ (g_GirlSpriteData.currentFrame % g_GirlSpriteData.columns) * g_GirlSpriteData.frameWidth};
	
	const Rectf girlSourceRect{
		rowIndexCrab,
		columnIndexCrab,
			g_GirlSpriteData.frameWidth,
			g_GirlSpriteData.frameHeight
		};

	
	DrawTexture(
		g_GirlSpriteData.texture,
		g_GirlSpriteData.location,
		girlSourceRect
		);
	
}

void Update(float elapsedSec)
{
	// crab update
	g_CrabSpriteData.accumulatedTime += elapsedSec;
	if ( g_CrabSpriteData.accumulatedTime > g_CrabSpriteData.frameDelay )
	{
		++g_CrabSpriteData.currentFrame;
		if ( g_CrabSpriteData.currentFrame >= g_CrabSpriteData.rows * g_CrabSpriteData.columns )
		{
			g_CrabSpriteData.currentFrame = 0;
		}
		g_CrabSpriteData.accumulatedTime -= g_CrabSpriteData.frameDelay;
	}
	
	// girl update
	g_GirlSpriteData.accumulatedTime += elapsedSec;
	if ( g_GirlSpriteData.accumulatedTime > g_GirlSpriteData.frameDelay )
	{
		++g_GirlSpriteData.currentFrame;
		if ( g_GirlSpriteData.currentFrame >= g_GirlSpriteData.rows * g_GirlSpriteData.columns )
		{
			g_GirlSpriteData.currentFrame = 0;
		}
		g_GirlSpriteData.accumulatedTime -= g_GirlSpriteData.frameDelay;
	}
}

void End()
{
	DeleteTexture( g_TextureString );
	DeleteTexture( g_CrabSpriteData.texture );
	DeleteTexture( g_GirlSpriteData.texture );
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