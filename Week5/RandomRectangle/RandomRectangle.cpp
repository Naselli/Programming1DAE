//-----------------------------------------------------------------
// Main Game File
// C++ Source - RandomRectangle.cpp - version v7_02_firstyear
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "RandomRectangle.h"

//-----------------------------------------------------------------
// RandomRectangle methods																				
//-----------------------------------------------------------------

RandomRectangle::RandomRectangle() 																	
{
	// nothing to create
}

RandomRectangle::~RandomRectangle()																						
{
	// nothing to destroy
}


void RandomRectangle::Initialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::Initialize(hInstance);
	GAME_ENGINE->SetTitle("Game Engine version 7_02 firstyear");					
	GAME_ENGINE->RunGameLoop(true);		
	
	// Set the optional values
	GAME_ENGINE->SetWidth(1000);
	GAME_ENGINE->SetHeight(1000);
    GAME_ENGINE->SetFrameRate(1);

	// Set the keys that the game needs to listen to
	//std::stringstream buffer;
	//buffer << "KLMO";
	//buffer << (char) VK_LEFT;
	//buffer << (char) VK_RIGHT;
	//GAME_ENGINE->SetKeyList(buffer.str());
}

void RandomRectangle::Start()
{
	// Insert the code that needs to be executed at the start of the game
}

void RandomRectangle::End()
{
	// Insert the code that needs to be executed at the closing of the game
}

void RandomRectangle::Paint(RECT rect)
{
	GAME_ENGINE->DrawSolidBackground(RGB(255,255,255));
	const int MAX_AMOUNT { 50 };

	for ( int counter {0} ; counter < MAX_AMOUNT ; ++counter)
	{
		COLORREF color = RGB(
		rand() % 256,
		rand() % 256,
		rand() % 256
		);

		GAME_ENGINE->SetColor(color);

		GAME_ENGINE->FillRect(
		rand() % 1000,
		rand() % 1000,
		rand() % 300,
		rand() % 300
		);

	}
}

void RandomRectangle::Tick()
{
	// Insert non-paint code that needs to be executed each tick 
}

void RandomRectangle::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse button action

	/* Example:
	if (isLeft == true && isDown == true) // is it a left mouse click?
	{	
		if ( x > 261 && x < 261 + 117 ) // check if click lies within x coordinates of choice
		{
			if ( y > 182 && y < 182 + 33 ) // check if click also lies within y coordinates of choice
			{
				GAME_ENGINE->MessageBox("Clicked.");
			}
		}
	}
	*/
}


void RandomRectangle::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse wheel action
}

void RandomRectangle::MouseMove(int x, int y, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the mouse pointer moves across the game window

	/* Example:
	if ( x > 261 && x < 261 + 117 ) // check if mouse position is within x coordinates of choice
	{
		if ( y > 182 && y < 182 + 33 ) // check if mouse position also is within y coordinates of choice
		{
			GAME_ENGINE->MessageBox("Da mouse wuz here.");
		}
	}
	*/
}

void RandomRectangle::CheckKeyboard()
{	
	// Here you can check if a key of choice is held down
	// Is executed once per frame if the Game Loop is running 

	/* Example:
	if (GAME_ENGINE->IsKeyDown('K')) xIcon -= xSpeed;
	if (GAME_ENGINE->IsKeyDown('L')) yIcon += xSpeed;
	if (GAME_ENGINE->IsKeyDown('M')) xIcon += xSpeed;
	if (GAME_ENGINE->IsKeyDown('O')) yIcon -= ySpeed;
	*/
}

void RandomRectangle::KeyPressed(TCHAR cKey)
{	
	// DO NOT FORGET to use SetKeyList() !!

	// Insert the code that needs to be executed when a key of choice is pressed
	// Is executed as soon as the key is released
	// You first need to specify the keys that the game engine needs to watch by using the SetKeyList() method

	/* Example:
	switch (cKey)
	{
	case 'K': case VK_LEFT:
		GAME_ENGINE->MessageBox("Moving left.");
		break;
	case 'L': case VK_DOWN:
		GAME_ENGINE->MessageBox("Moving down.");
		break;
	case 'M': case VK_RIGHT:
		GAME_ENGINE->MessageBox("Moving right.");
		break;
	case 'O': case VK_UP:
		GAME_ENGINE->MessageBox("Moving up.");
		break;
	case VK_ESCAPE:
		GAME_ENGINE->MessageBox("Escape menu.");
	}
	*/
}

void RandomRectangle::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
}




