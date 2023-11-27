#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
std::string g_WindowTitle{ "Dice Rolls - Naselli, Luca- 1DAE14" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Constants
static const int MAX_ELEMENTS_1D6{  6 };
static const int MAX_ELEMENTS_2D6{ 11 };

const int DRAW_2D6_Y_BASE{ 20  };
const int DRAW_1D6_Y_BASE{ 400 };

const int DRAW_X_BASE		{ 20 };
const int DRAW_LINE_HEIGHT	{ 20 };
const int DRAW_LINE_SPACING {  5 };

// Declare your own global variables here
int g_Results1D6Arr[ MAX_ELEMENTS_1D6 ]{};
int g_Results2D6Arr[ MAX_ELEMENTS_2D6 ]{};


// Declare your own functions here
int RollD6(int nrDice = 1 );

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
