//-----------------------------------------------------------------
// Main Game File
// C++ Source - Random.cpp - version v7_02_firstyear
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Random.h"	
using namespace std;

//-----------------------------------------------------------------
// Random methods																				
//-----------------------------------------------------------------

Random::Random() 																	
{
	// nothing to create
}

Random::~Random()																						
{
	// nothing to destroy
}


void Random::Initialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::Initialize(hInstance);
	GAME_ENGINE->SetTitle("Random");					
	GAME_ENGINE->RunGameLoop(true);		
	
	// Set the optional values
	GAME_ENGINE->SetWidth(1024);
	GAME_ENGINE->SetHeight(768);
    GAME_ENGINE->SetFrameRate(10);

	// Set the keys that the game needs to listen to
	//tstringstream buffer;
	//buffer << _T("KLMO");
	//buffer << (TCHAR) VK_LEFT;
	//buffer << (TCHAR) VK_RIGHT;
	//GAME_ENGINE->SetKeyList(buffer.str());
}

void Random::Start()
{
	m_FontPtr = new Font("Verdana", false, false, false, 20);
}

void Random::End()
{
	delete m_FontPtr;
}

void Random::Paint(RECT rect)
{
	//int numberOne{12};
	//numberOne = 500;
	
	GAME_ENGINE->SetColor(RGB(255,255,255));
	GAME_ENGINE->SetFont(m_FontPtr);
	
	//[0, 50]
	int randomNumber050 = {rand() % 51 + 1};
	GAME_ENGINE->DrawString(string("Number between [0,50]: -->  ") + to_string(randomNumber050), 20,20);

	//[10, 80]
	int randomNumber1080 = {rand() % 71 + 10};
	GAME_ENGINE->DrawString(string("Number between [10,80]: -->  ") + to_string(randomNumber1080), 20, 40);

	//[-20, 20]
	int randomNumberMin20Plus20 = {rand() % 41 - 20};
	GAME_ENGINE->DrawString(string("Number between [-20, 20]: -->  ") + to_string(randomNumberMin20Plus20), 20, 60);

	//[-2,2]
	int randomNumberMin2Plus2 = {rand() % 5 - 2};
	GAME_ENGINE->DrawString(string("Number between [-2,2]: -->  ") + to_string(randomNumberMin2Plus2), 20, 80);

	//[5,00, 10,00]
	double randomFloatingNumber510 = {(rand() % 501 + 500 )/ 100.0};
	std::string output{ to_string(randomFloatingNumber510) };
	GAME_ENGINE->DrawString(string("Number between [5,00, 10,00]: -->  ") + output.substr(0,4), 20, 100);

	//[-5.00, 5.00]
	double randomFloatingNumberMin5Plus5 = {(rand() % 1001 - 500 )/ 100.0 };
	GAME_ENGINE->DrawString(string("Number between [-5.00,5.00]: -->  ") + to_string(randomFloatingNumberMin5Plus5), 20, 120);

}

void Random::Tick()
{
	// Insert non-paint code that needs to be executed each tick 
}

void Random::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse button action

	/* Example:
	if (isLeft == true && isDown == true) // is it a left mouse click?
	{	
		if ( x > 261 && x < 261 + 117 ) // check if click lies within x coordinates of choice
		{
			if ( y > 182 && y < 182 + 33 ) // check if click also lies within y coordinates of choice
			{
				GAME_ENGINE->MessageBox(_T("Clicked."));
			}
		}
	}
	*/
}


void Random::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse wheel action
}

void Random::MouseMove(int x, int y, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the mouse pointer moves across the game window

	/* Example:
	if ( x > 261 && x < 261 + 117 ) // check if mouse position is within x coordinates of choice
	{
		if ( y > 182 && y < 182 + 33 ) // check if mouse position also is within y coordinates of choice
		{
			GAME_ENGINE->MessageBox(_T("Da mouse wuz here."));
		}
	}
	*/
}

void Random::CheckKeyboard()
{	
	// Here you can check if a key of choice is held down
	// Is executed once per frame if the Game Loop is running 

	/* Example:
	if (GAME_ENGINE->IsKeyDown(_T('K'))) xIcon -= xSpeed;
	if (GAME_ENGINE->IsKeyDown(_T('L'))) yIcon += xSpeed;
	if (GAME_ENGINE->IsKeyDown(_T('M'))) xIcon += xSpeed;
	if (GAME_ENGINE->IsKeyDown(_T('O'))) yIcon -= ySpeed;
	*/
}

void Random::KeyPressed(TCHAR cKey)
{	
	// DO NOT FORGET to use SetKeyList() !!

	// Insert the code that needs to be executed when a key of choice is pressed
	// Is executed as soon as the key is released
	// You first need to specify the keys that the game engine needs to watch by using the SetKeyList() method

	/* Example:
	switch (cKey)
	{
	case _T('K'): case VK_LEFT:
		GAME_ENGINE->MessageBox(_T("Moving left."));
		break;
	case _T('L'): case VK_DOWN:
		GAME_ENGINE->MessageBox(_T("Moving down."));
		break;
	case _T('M'): case VK_RIGHT:
		GAME_ENGINE->MessageBox(_T("Moving right."));
		break;
	case _T('O'): case VK_UP:
		GAME_ENGINE->MessageBox(_T("Moving up."));
		break;
	case VK_ESCAPE:
		GAME_ENGINE->MessageBox(_T("Escape menu."));
	}
	*/
}

void Random::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
}




