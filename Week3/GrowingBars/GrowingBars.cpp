//-----------------------------------------------------------------
// Main Game File
// C++ Source - GrowingBars.cpp - version v7_02_firstyear
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "GrowingBars.h"

//-----------------------------------------------------------------
// GrowingBars methods																				
//-----------------------------------------------------------------

GrowingBars::GrowingBars() 																	
{
	// nothing to create
	
}

GrowingBars::~GrowingBars()																						
{
	// nothing to destroy
}


void GrowingBars::Initialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::Initialize(hInstance);
	GAME_ENGINE->SetTitle("Game Engine version 7_02 firstyear");					
	GAME_ENGINE->RunGameLoop(true);		
	
	// Set the optional values
	GAME_ENGINE->SetWidth(800);
	GAME_ENGINE->SetHeight(600);
    GAME_ENGINE->SetFrameRate(50);


	// Set the keys that the game needs to listen to
	//std::stringstream buffer;
	//buffer << "KLMO";
	//buffer << (char) VK_LEFT;
	//buffer << (char) VK_RIGHT;
	//GAME_ENGINE->SetKeyList(buffer.str());
}

void GrowingBars::Start()
{

}

void GrowingBars::End()
{
	// Insert the code that needs to be executed at the closing of the game
}

void GrowingBars::Paint(RECT rect)
{
	//first bar
	GAME_ENGINE->SetColor(RGB(255,255, 0));
	GAME_ENGINE->FillRect(BAR_POSX, BAR_POSY, m_FirstBarWidth, BAR_HEIGTH);


	//second bar
	GAME_ENGINE->SetColor(RGB(255,0,0));
	GAME_ENGINE->FillRect(BAR_POSX, BAR_POSY + 200, m_SecondBarWidth, BAR_HEIGTH);

	//third bar
	GAME_ENGINE->SetColor(g_color);
	GAME_ENGINE->FillRect(BAR_POSX, BAR_POSY + 400, m_ThirdBarWidth, BAR_HEIGTH);

	GAME_ENGINE->SetColor(RGB(255,255,255));
	GAME_ENGINE->DrawRect(BAR_POSX, BAR_POSY,BAR_WIDTH, BAR_HEIGTH);
	GAME_ENGINE->DrawRect(BAR_POSX, BAR_POSY + 200, BAR_WIDTH, BAR_HEIGTH);
	GAME_ENGINE->DrawRect(BAR_POSX, BAR_POSY + 400, BAR_WIDTH, BAR_HEIGTH);

	
}

void GrowingBars::Tick()
{
	m_FirstBarWidth += FIRSTBAR_SPEED_IN_PIXELS;
	m_SecondBarWidth += SECONDBAR_SPEED_IN_PIXELS;

	//Bar goes back and resets
	if (m_FirstBarWidth >= BAR_WIDTH || m_FirstBarWidth <= 0) FIRSTBAR_SPEED_IN_PIXELS = -FIRSTBAR_SPEED_IN_PIXELS;
	if (m_SecondBarWidth >= BAR_WIDTH || m_SecondBarWidth <= 0) SECONDBAR_SPEED_IN_PIXELS = -SECONDBAR_SPEED_IN_PIXELS;

	//reset bars
	/*
	if (m_FirstBarWidth >= BAR_WIDTH) m_FirstBarWidth = 0;
	if (m_SecondBarWidth >= BAR_WIDTH) m_SecondBarWidth = 0;
	*/
	++m_ticks;
	if (m_ticks >= INTERVAL)
	{
		m_ThirdBarWidth += BAR_WIDTH / 8;

		if (m_ThirdBarWidth > BAR_WIDTH)
		{
			m_ThirdBarWidth = 0;
		}
		m_ticks = 0;
	}

	
}

void GrowingBars::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
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
		if ((x > BAR_POSX		&& x < BAR_POSX + m_ThirdBarWidth) &&
			(y > BAR_POSY + 400 && y < BAR_POSY + 400 + BAR_HEIGTH))
		{
			g_color = RGB(
			rand() % 256,
			rand() % 256, 
			rand() % 256 
			);
		}
	}
}


void GrowingBars::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse wheel action
}

void GrowingBars::MouseMove(int x, int y, WPARAM wParam)
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

void GrowingBars::CheckKeyboard()
{	
	// Here you can check if a key of choice is held down
	// Is executed once per frame if the Game Loop is running 

	/* Example:
	if (GAME_ENGINE->IsKeyDown('K')) xIcon -= xSpeed;
	if (GAME_ENGINE->IsKeyDown('L')) yIcon += xSpeed;
	if (GAME_ENGINE->IsKeyDown('M')) xIcon += xSpeed;
	if (GAME_ENGINE->IsKeyDown('O')) yIcon -= ySpeed;
	*/
	if (GAME_ENGINE->IsKeyDown('R')) m_ThirdBarWidth = 0;
}

void GrowingBars::KeyPressed(TCHAR cKey)
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

void GrowingBars::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
}




