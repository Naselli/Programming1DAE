//-----------------------------------------------------------------
// Main Game File
// C++ Source - Explosion.cpp - version v7_02_firstyear
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Explosion.h"

//-----------------------------------------------------------------
// Explosion methods																				
//-----------------------------------------------------------------

Explosion::Explosion() 																	
{
	// nothing to create
}

Explosion::~Explosion()																						
{
	// nothing to destroy
}


void Explosion::Initialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::Initialize(hInstance);
	GAME_ENGINE->SetTitle("Game Engine version 7_02 firstyear");					
	GAME_ENGINE->RunGameLoop(true);		
	
	// Set the optional values
	GAME_ENGINE->SetWidth(SCREENWIDTH);
	GAME_ENGINE->SetHeight(SCREENHEIGTH);
    GAME_ENGINE->SetFrameRate(FRAMERATE);

	// Set the keys that the game needs to listen to
	//std::stringstream buffer;
	//buffer << "KLMO";
	//buffer << (char) VK_LEFT;
	//buffer << (char) VK_RIGHT;
	//GAME_ENGINE->SetKeyList(buffer.str());
}

void Explosion::Start()
{
	// Insert the code that needs to be executed at the start of the game
}

void Explosion::End()
{
	// Insert the code that needs to be executed at the closing of the game
}

void Explosion::Paint(RECT rect)
{
	GAME_ENGINE->DrawSolidBackground(RGB(200,200,200));
	GAME_ENGINE->SetColor(RGB(50,50,50));
	GAME_ENGINE->FillRect(CENTER_POINT.x - (SQUARE_SIZE / 2), CENTER_POINT.y - (SQUARE_SIZE / 2), SQUARE_SIZE, SQUARE_SIZE);


}

void Explosion::Tick()
{
	// Insert non-paint code that needs to be executed each tick 
}

void Explosion::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
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
	if (isLeft == true && isDown == true)
	{
		if (x > CENTER_POINT.x - (SQUARE_SIZE / 2) && x < (CENTER_POINT.x - (SQUARE_SIZE / 2) + SQUARE_SIZE) &&
			y > CENTER_POINT.y - (SQUARE_SIZE / 2) && y < (CENTER_POINT.y - (SQUARE_SIZE / 2) + SQUARE_SIZE))
		{
			//GAME_ENGINE->MessageBox("test");
		}
	}
}


void Explosion::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse wheel action
}

void Explosion::MouseMove(int x, int y, WPARAM wParam)
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

void Explosion::CheckKeyboard()
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

void Explosion::KeyPressed(TCHAR cKey)
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

void Explosion::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
}




