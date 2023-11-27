#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Gravity - Naselli, Luca - 1DAE14" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Constants
const float RADIUS{ 10.0f };
const float ACCELERATION_FULL_SECOND{ 1000.0f };
const float FLOOR { g_WindowHeight * 3 / 4 };
const float HORIZONTAL_SPEED_FULL_SECOND { 50.0f };
const float FRICTION { 0.8f };


// Declare your own global variables here
Point2f g_Center{g_WindowWidth / 4, g_WindowHeight / 4};
float g_VerticalSpeed{};

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
