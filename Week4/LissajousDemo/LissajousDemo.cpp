//-----------------------------------------------------------------
// Main Game File
// C++ Source - LissajousDemo.cpp - version v7_02_firstyear
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "LissajousDemo.h"
#define _USE_MATH_DEFINES
#include <math.h>

//-----------------------------------------------------------------
// LissajousDemo methods																				
//-----------------------------------------------------------------

LissajousDemo::LissajousDemo() 																	
{
	// nothing to create
}

LissajousDemo::~LissajousDemo()																						
{
	// nothing to destroy
}


void LissajousDemo::Initialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::Initialize(hInstance);
	GAME_ENGINE->SetTitle("Game Engine version 7_02 firstyear");					
	GAME_ENGINE->RunGameLoop(true);		
	
	// Set the optional values
	GAME_ENGINE->SetWidth(WINDOWWIDTH);
	GAME_ENGINE->SetHeight(WINDOWHEIGTH);
    GAME_ENGINE->SetFrameRate(FRAMERATE);

	// Set the keys that the game needs to listen to
	//std::stringstream buffer;
	//buffer << "KLMO";
	//buffer << (char) VK_LEFT;
	//buffer << (char) VK_RIGHT;
	//GAME_ENGINE->SetKeyList(buffer.str());
}

void LissajousDemo::Start()
{
	// Insert the code that needs to be executed at the start of the game
	//GAME_ENGINE->ShowMousePointer(false);
}

void LissajousDemo::End()
{
	// Insert the code that needs to be executed at the closing of the game
}

void LissajousDemo::Paint(RECT rect)
{
	GAME_ENGINE->SetColor(RGB(255,10,10,));

	double verticalDeviation{};
	if (m_AnimationMode == AnimationMode::Both || m_AnimationMode == AnimationMode::Vertical)
	{
		double verticalWaveProgressInPercent{ m_TickCounter / (FRAMERATE * VERTICAL_PERIOD_IN_SECONDS) };
		verticalDeviation = VERTICAL_AMPLITUDE * sin((2 * M_PI) * verticalWaveProgressInPercent);
	}

	double horizontalDeviation{};
	if (m_AnimationMode == AnimationMode::Both || m_AnimationMode == AnimationMode::Horizontal)
	{
		double horizontalWaveProgressInPercent{ m_TickCounter / (FRAMERATE * HORIZONTAL_PERIOD_IN_SECONDS) };
		horizontalDeviation = HORIZONTAL_AMPLITUDE * sin((2 * M_PI) * horizontalWaveProgressInPercent);
	}
	
	GAME_ENGINE->FillOval((int)(m_CenterX  - RADIUS - horizontalDeviation), (int)(m_CenterY - RADIUS + verticalDeviation), 2 * RADIUS, 2 * RADIUS);

}

void LissajousDemo::Tick()
{
	++m_TickCounter;
	// Insert non-paint code that needs to be executed each tick 
}

void LissajousDemo::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
{
	if (isLeft == false && isDown == false)
	{
		switch (m_AnimationMode)
		{
		case AnimationMode::None: m_AnimationMode = AnimationMode::Vertical; break;
		case AnimationMode::Vertical: m_AnimationMode = AnimationMode::Horizontal; break;
		case AnimationMode::Horizontal: m_AnimationMode = AnimationMode::Both; break;
		case AnimationMode::Both: m_AnimationMode = AnimationMode::None; break;
		}
	}
}


void LissajousDemo::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse wheel action
}

void LissajousDemo::MouseMove(int x, int y, WPARAM wParam)
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

	m_CenterX = x;
	m_CenterY = y;


}

void LissajousDemo::CheckKeyboard()
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

void LissajousDemo::KeyPressed(TCHAR cKey)
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

void LissajousDemo::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
}




