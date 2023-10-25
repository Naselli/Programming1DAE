//-----------------------------------------------------------------
// Main Game File
// C++ Source - ClockMovementDemo.cpp - version v7_02_firstyear
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "ClockMovementDemo.h"
#define _USE_MATH_DEFINES
#include <math.h>
//-----------------------------------------------------------------
// ClockMovementDemo methods																				
//-----------------------------------------------------------------

ClockMovementDemo::ClockMovementDemo() 																	
{
	// nothing to create
}

ClockMovementDemo::~ClockMovementDemo()																						
{
	// nothing to destroy
}


void ClockMovementDemo::Initialize(HINSTANCE hInstance)			
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

void ClockMovementDemo::Start()
{
	// Insert the code that needs to be executed at the start of the game
	m_CenterPoint.x = WINDOWWIDTH / 2;
	m_CenterPoint.y = WINDOWHEIGTH/ 2;

	m_BtnLeftPtr = new Button{"Left"};
	m_BtnLeftPtr->SetBounds(20,20,100,60);
	m_BtnLeftPtr->SetFont("Verdana", false, false, false, 45);
	m_BtnLeftPtr->AddActionListener(this);
	m_BtnLeftPtr->Show();

	m_BtnRightPtr = new Button{ "Right" };
	m_BtnRightPtr->SetBounds(WINDOWWIDTH - 120, 20, 100, 60);
	m_BtnRightPtr->SetFont("Verdana", false, false, false, 45);
	m_BtnRightPtr->AddActionListener(this);
	m_BtnRightPtr->Show();
}

void ClockMovementDemo::End()
{
	// Insert the code that needs to be executed at the closing of the game
	delete m_BtnLeftPtr;
	delete m_BtnRightPtr;
}

void ClockMovementDemo::Paint(RECT rect)
{
	// Insert paint code
	POINT outerPoint{};

	double verticalDeviation   { RADIUS * sin((2 * M_PI) * m_Angle / 360.0) };
	double horizontalDeviation { RADIUS * cos((2 * M_PI) * m_Angle / 360.0) };

	outerPoint.x = ( int )( m_CenterPoint.x + horizontalDeviation );
	outerPoint.y = ( int )( m_CenterPoint.y - verticalDeviation );

	GAME_ENGINE->SetColor(RGB(255,255,255));
	GAME_ENGINE->DrawLine(m_CenterPoint.x, m_CenterPoint.y, outerPoint.x, outerPoint.y);
}

void ClockMovementDemo::Tick()
{
	// Insert non-paint code that needs to be executed each tick
	m_Angle += m_DeltaAngle;
}

void ClockMovementDemo::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
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


void ClockMovementDemo::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse wheel action
}

void ClockMovementDemo::MouseMove(int x, int y, WPARAM wParam)
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

void ClockMovementDemo::CheckKeyboard()
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

void ClockMovementDemo::KeyPressed(TCHAR cKey)
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

void ClockMovementDemo::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
	if (callerPtr == m_BtnLeftPtr)
	{
		++m_DeltaAngle;
	}
	else if (callerPtr == m_BtnRightPtr)
	{
		--m_DeltaAngle;
	}
}




