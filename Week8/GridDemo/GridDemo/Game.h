#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
std::string g_WindowTitle{ "GridDemo - Naselli, Luca- 1DAE14" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Structs and Enum Classes
enum class CellState
{
	Empty,
	Red,
	Green,
	Blue
};


// Constants
static const int ROWS	{3};
static const int COLUMNS{4};

const int DRAW_X_BASE		{  20 };
const int DRAW_Y_BASE		{  20 };
const int DRAW_CELL_WIDTH	{ 100 };

CellState g_GridArr[ROWS][COLUMNS]{};


// Declare your own global variables here

// Declare your own functions here
void DrawGrid();
int GetRowIndex(const Point2f& clickPos);
int GetColumnIndex(const Point2f& clickPos);


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
