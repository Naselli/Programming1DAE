#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void DrawGrid()
{
	
	SetColor(1,1,1);

	// Drawing with Rectangles
	for (int rowCounter{}; rowCounter < ROWS; ++rowCounter)
		for (int colCounter{}; colCounter < COLUMNS; ++colCounter)
		{
			DrawRect(
				DRAW_X_BASE + (colCounter * DRAW_CELL_WIDTH),
				DRAW_Y_BASE + (rowCounter * DRAW_CELL_WIDTH),
				DRAW_CELL_WIDTH,
				DRAW_CELL_WIDTH
			);
		}


	// Drawing with lines
	/* Vertical lines
	for (int countLine{}; countLine <= COLUMNS; ++countLine)
	{
		const int xPos{ DRAW_X_BASE + countLine * DRAW_CELL_WIDTH};
		DrawLine(xPos,DRAW_Y_BASE,xPos,DRAW_Y_BASE + ROWS * DRAW_CELL_WIDTH);
	}
	// Horizintal lines
	for (int countLine{}; countLine <= ROWS; ++countLine)
	{
		const int yPos{ DRAW_Y_BASE + countLine * DRAW_CELL_WIDTH };
		DrawLine(DRAW_X_BASE, yPos, DRAW_X_BASE + COLUMNS * DRAW_CELL_WIDTH, yPos);
	}
	*/
}

void Draw()
{
	ClearBackground(0, 0, 0);

	for (int rowIndex{}; rowIndex < ROWS; ++rowIndex)
		for (int columnIndex{}; columnIndex < COLUMNS; ++columnIndex)
		{
			switch (g_GridArr[rowIndex][columnIndex])
			{
			case CellState::Empty:
				SetColor(.5f,.5f,.5f);
				break;
			case CellState::Red:
				SetColor(1,0,0);
				break;
			case CellState::Green:
				SetColor(0,1,0);
				break;
			case CellState::Blue:
				SetColor(0,0,1);
				break;
			default: ;
			}

			FillRect(
				DRAW_X_BASE + (columnIndex * DRAW_CELL_WIDTH),
				DRAW_Y_BASE + (rowIndex * DRAW_CELL_WIDTH),
				DRAW_CELL_WIDTH,
				DRAW_CELL_WIDTH
			);
		}

	DrawGrid();

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
	const Point2f clickPos	{ float(e.x), float(e.y)};
	const int rowIndex		{ GetRowIndex(clickPos)};
	const int columnIndex	{ GetColumnIndex(clickPos)};

	//std::cout << rowIndex << ", " << columnIndex << std::endl;

	if (rowIndex != -1 && columnIndex != -1)
	{
		switch (g_GridArr[rowIndex][columnIndex]) {
		case CellState::Empty:
			g_GridArr[rowIndex][columnIndex] = CellState::Red;
			break;
		case CellState::Red:
			g_GridArr[rowIndex][columnIndex] = CellState::Green;
			break;
		case CellState::Green:
			g_GridArr[rowIndex][columnIndex] = CellState::Blue;
			break;
		case CellState::Blue:
			g_GridArr[rowIndex][columnIndex] = CellState::Empty;
			break;
		default: ;
		}
	}
}

int GetRowIndex(const Point2f& clickPos)
{
	if (clickPos.y < DRAW_Y_BASE || clickPos.y > DRAW_Y_BASE + ROWS * DRAW_CELL_WIDTH) return -1;
	return int(clickPos.y - DRAW_Y_BASE) / DRAW_CELL_WIDTH;
}

int GetColumnIndex(const Point2f& clickPos)
{
	if (clickPos.x < DRAW_X_BASE || clickPos.x > DRAW_X_BASE + COLUMNS * DRAW_CELL_WIDTH) return -1;
	return int(clickPos.x - DRAW_X_BASE) / DRAW_CELL_WIDTH;
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