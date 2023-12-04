#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "SpriteAnimationsDemo- Naselli, Luca - 1DAE14" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Structs and Enum Classes
struct SpriteData
{
    Texture texture;
    Point2f location;
    int rows, columns;
    int frameWidth, frameHeight;
    float frameDelay;
    float accumulatedTime;
    int currentFrame;
};

// Constants
static const int NR_FRAMES_GIRL { 6 };
static const int NR_ROWS_CRAB   { 4 };
static const int NR_COLUMNS_CRAB{ 6 };

// Declare your own global variables here
Texture g_TextureString{};

SpriteData g_GirlSpriteData{}, g_CrabSpriteData{};

Point2f g_PositionGirl{ g_WindowWidth / 4,     g_WindowHeight * 3 / 4 };
Point2f g_PositionCrab{ g_WindowWidth * 3 / 4, g_WindowHeight * 3 / 4 };



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
