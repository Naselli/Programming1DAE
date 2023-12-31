#pragma once
#include <utils.h>
using namespace utils;

#include "Sprite.h"
#include "StringSprite.h"

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Sprite Animations Demo - Naselli, Luca - 1DAE14" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Structs and Enum Classes

// Constants

// Declare your own global variables here
StringSprite*  g_TxtTitlePtr{};

Sprite *g_GirlSpritePtr, *g_CrabSpritePtr;

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
