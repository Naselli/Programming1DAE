#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations

// Structs and enum classes
enum class Direction
{
	Up, UpRight, Right, DownRight, Down, DownLeft, Left, UpLeft
};
struct TankData
{
	Point2f position;
	bool isMoving;
	Direction direction;
	const float SPEED;
};
struct BulletData
{
	Point2f position;
	bool isFired;
	Direction direction;
	const float SPEED;

	float animationCounter;
	const float MAX_ANIMATION;
	const float RADIUS;
};


// Constants
const int NR_ROWS{ 8 };

// Declare your own global variables here
Texture g_TextureTankData{};
float g_FrameWidth{ };

TankData g_TankData{
	Point2f{ g_WindowWidth / 2, g_WindowHeight/ 2 },
	false,
	Direction::Right,
	2 };

BulletData m_BulletData{
	Point2f{-1.f,-1.f},
	false,
	Direction::Right,
	5,
	-1,
	50,
	3
};




// Declare your own functions here
void PaintTank();
void PaintBullet();
void UpdateTank(float elapsedSec);
void UpdateBullet(float elapsedSec);

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
