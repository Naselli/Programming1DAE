//-----------------------------------------------------------------
// Main Game File
// C++ Source - MovementDemo.cpp - version v7_02_firstyear
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "MovementDemo.h"

#include <corecrt_math_defines.h>
#define _USE_MATH_DEFINES
//-----------------------------------------------------------------
// MovementDemo methods																				
//-----------------------------------------------------------------

MovementDemo::MovementDemo() 																	
{
	// nothing to create
}

MovementDemo::~MovementDemo()																						
{
	// nothing to destroy
}


void MovementDemo::Initialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::Initialize(hInstance);
	GAME_ENGINE->SetTitle("Game Engine version 7_02 firstyear");					
	GAME_ENGINE->RunGameLoop(true);		
	
	// Set the optional values
	GAME_ENGINE->SetWidth(SCREENWIDTH);
	GAME_ENGINE->SetHeight(SCREENHEIGHT);
    GAME_ENGINE->SetFrameRate(FRAMERATE);

	// Set the keys that the game needs to listen to
	//std::stringstream buffer;
	//buffer << "KLMO";
	//buffer << (char) VK_LEFT;
	//buffer << (char) VK_RIGHT;
	//GAME_ENGINE->SetKeyList(buffer.str());
}

void MovementDemo::Start()
{
	// Insert the code that needs to be executed at the start of the game
	const std::string fileName{"Graphics/platform.bmp"};
	m_BmpPlatformPtr = new  Bitmap(fileName);

	if (m_BmpPlatformPtr->Exists()==false)
	{
		GAME_ENGINE->MessageBox(std::string("File not found") + fileName);
		GAME_ENGINE->Quit();
	}
	else m_BmpPlatformPtr->SetTransparencyColor(RGB(255,0,255));
	
}

void MovementDemo::End()
{
	// Insert the code that needs to be executed at the closing of the game
	delete m_BmpPlatformPtr;
}

void MovementDemo::Paint(RECT rect)
{
	//Linear platform
	int xLinearPos{ LINEAR_PLATFORM_X - m_BmpPlatformPtr->GetWidth(  ) / 2 };
	int yLinearPos{	(int)(LINEAR_PLATFORM_Y_BASE - m_BmpPlatformPtr->GetHeight(  ) /2 - m_LinearMovement_Y_Deviation)  };  // NOLINT(bugprone-integer-division)
	
	GAME_ENGINE ->DrawBitmap( m_BmpPlatformPtr, xLinearPos, yLinearPos );	

	//Wave Platform
	int xWavePos{ WAVE_PLATFORM_X - m_BmpPlatformPtr->GetWidth(  ) / 2 };
	int yWavePos{	(int)(WAVE_PLATFORM_Y_BASE - m_BmpPlatformPtr->GetHeight(  ) /2 - m_WaveMovement_Y_Deviation)  };  // NOLINT(bugprone-integer-division)
	
	GAME_ENGINE ->DrawBitmap( m_BmpPlatformPtr, xWavePos, yWavePos );	
}

void MovementDemo::Tick()
{
	// Insert non-paint code that needs to be executed each tick
	m_LinearMovement_Y_Deviation += LINEAR_MOVEMENT_PER_FRAME_IN_PIXELS * m_LinearMovement_Direction;

	if ( abs( m_LinearMovement_Y_Deviation ) >= AMPLITUDE )
		m_LinearMovement_Direction *= -1;


	//wave movement position calculation
	++m_TickCounter;
	double WaveMovementInPercent{(double)m_TickCounter / (double)(FRAMERATE * PERIOD_IN_SECONDS)};
	m_WaveMovement_Y_Deviation = AMPLITUDE * sin( (2 *M_PI) * WaveMovementInPercent );
}

void MovementDemo::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
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


void MovementDemo::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse wheel action
}

void MovementDemo::MouseMove(int x, int y, WPARAM wParam)
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

void MovementDemo::CheckKeyboard()
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

void MovementDemo::KeyPressed(TCHAR cKey)
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

void MovementDemo::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
}




