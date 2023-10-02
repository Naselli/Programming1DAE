//-----------------------------------------------------------------
// Main Game File
// C++ Source - DrawShapes.cpp - version v7_02_firstyear
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "DrawShapes.h"																				

//-----------------------------------------------------------------
// DrawShapes methods																				
//-----------------------------------------------------------------

DrawShapes::DrawShapes() 																	
{
	// nothing to create
}

DrawShapes::~DrawShapes()																						
{
	// nothing to destroy
}


void DrawShapes::Initialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::Initialize(hInstance);
	GAME_ENGINE->SetTitle("Draw Shapes");					
	GAME_ENGINE->RunGameLoop(true);		
	
	// Set the optional values
	GAME_ENGINE->SetWidth(1024);
	GAME_ENGINE->SetHeight(768);
    GAME_ENGINE->SetFrameRate(50);

	// Set the keys that the game needs to listen to
	//tstringstream buffer;
	//buffer << _T("KLMO");
	//buffer << (TCHAR) VK_LEFT;
	//buffer << (TCHAR) VK_RIGHT;
	//GAME_ENGINE->SetKeyList(buffer.str());
}

void DrawShapes::Start()
{
	// Insert the code that needs to be executed at the start of the game
}

void DrawShapes::End()
{
	// Insert the code that needs to be executed at the closing of the game
}

void DrawShapes::Paint(RECT rect)
{
	//set the background
	GAME_ENGINE->DrawSolidBackground(RGB(255,255,255));

	
	//part 1
	GAME_ENGINE->SetColor(RGB(0, 0, 0));
	GAME_ENGINE->DrawString("1. Luca", 20,20 );

	//part 2
	GAME_ENGINE->DrawString("2. One \n    Two\n    Three\n", 20,50, 100, 50);

	//part 3
	GAME_ENGINE->DrawString("3.", 20, 120);
	GAME_ENGINE->DrawLine(50,180,80,130);
	GAME_ENGINE->DrawLine(80,130,110,180);
	GAME_ENGINE->DrawRect(50,180, 60,60);

	//part 4
	GAME_ENGINE->DrawString("4.", 20, 300);
	GAME_ENGINE->SetColor(RGB(0,0,0));
	GAME_ENGINE->FillRect(50, 300,20,30);
	GAME_ENGINE->SetColor(RGB(255,255,0));
	GAME_ENGINE->FillRect(70,300,20,30);
	GAME_ENGINE->SetColor(RGB(255,0,0));
	GAME_ENGINE->FillRect(90, 300, 20, 30);

	//part 5
	GAME_ENGINE->SetColor(RGB(0, 0, 0));
	GAME_ENGINE->DrawString("5.", 20, 350);
	GAME_ENGINE->SetColor(RGB(0,0,0));
	GAME_ENGINE->FillRect(50, 350, 60,60);
	GAME_ENGINE->SetColor(RGB(255,255,255));
	GAME_ENGINE->FillRect(70, 350, 20, 20);
	GAME_ENGINE->FillRect(50, 370, 20, 20);
	GAME_ENGINE->FillRect(90, 370, 20, 20);
	GAME_ENGINE->FillRect(70, 390, 20, 20);

	GAME_ENGINE->SetColor(RGB(0, 0, 0));
	GAME_ENGINE->DrawRect(50, 350, 60, 60);

	//part 6
	GAME_ENGINE->DrawString("6.", 400, 20);
	GAME_ENGINE->SetColor(RGB(255,0,0));
	GAME_ENGINE->FillRect(420, 30, 60,100);

	GAME_ENGINE->SetColor(RGB(0,255,0));
	GAME_ENGINE->FillRect(480,20,60,110);

	GAME_ENGINE->SetColor(RGB(0,0,255));
	GAME_ENGINE->FillRect(540,40, 60, 90);
	GAME_ENGINE->SetColor(RGB(0,0,0));
	GAME_ENGINE->DrawString("Charlotte  Welmer  Noa", 420, 130);

	//part 7
	GAME_ENGINE->DrawString("7.", 400, 200);
	GAME_ENGINE->FillRect(420,200, 20,20);
	GAME_ENGINE->SetColor(RGB(255,0,0));
	GAME_ENGINE->FillRect(440, 200, 20, 20);
	GAME_ENGINE->SetColor(RGB(0, 255, 0));
	GAME_ENGINE->FillRect(460, 200, 20, 20);
	GAME_ENGINE->SetColor(RGB(0, 0, 255));
	GAME_ENGINE->FillRect(480, 200, 20, 20);
	GAME_ENGINE->SetColor(RGB(255, 255, 0));
	GAME_ENGINE->FillRect(500, 200, 20, 20);
	GAME_ENGINE->SetColor(RGB(255, 0, 255));
	GAME_ENGINE->FillRect(520, 200, 20, 20);
	GAME_ENGINE->SetColor(RGB(0, 255, 255));
	GAME_ENGINE->FillRect(540, 200, 20, 20);
	GAME_ENGINE->SetColor(RGB(0,0,0));
	GAME_ENGINE->DrawRect(420,200, 160, 20);

	//part 8
	GAME_ENGINE->DrawString("8.", 400, 240);
	GAME_ENGINE->SetColor(RGB(100,100,100));
	GAME_ENGINE->FillRect(420,240, 40, 125);
	GAME_ENGINE->FillRect(435,360, 10, 80);
	GAME_ENGINE->SetColor(RGB(255, 0,0));
	GAME_ENGINE->FillOval(425,245, 30, 30);
	GAME_ENGINE->SetColor(RGB(255,120, 0));
	GAME_ENGINE->FillOval(425,285, 30, 30);
	GAME_ENGINE->SetColor(RGB(0, 255, 0));
	GAME_ENGINE->FillOval(425,325, 30, 30);

	//part 9
	GAME_ENGINE->SetColor(RGB(0,0,0));
	GAME_ENGINE->DrawString("9.", 500, 240);
	GAME_ENGINE->DrawRoundRect( 520, 260, 120,120, 30);
	GAME_ENGINE->FillOval(540, 280, 20, 20);
	GAME_ENGINE->FillOval(570, 310, 20, 20);
	GAME_ENGINE->FillOval(600, 340, 20, 20);

	//part 10
	GAME_ENGINE->SetColor(RGB(0, 0, 0));
	GAME_ENGINE->DrawString("10.", 400, 500);
	GAME_ENGINE->SetColor(RGB(0, 0, 255));
	GAME_ENGINE->DrawArc(420, 500, 100,50, 90, 270);
	GAME_ENGINE->FillArc(570, 500, 100,50, 90, 270);
	GAME_ENGINE->DrawString("DrawArc", 420, 550);
	GAME_ENGINE->DrawString("FillArc", 570, 550);
	

	/*
	//Extra
	GAME_ENGINE->SetColor(RGB(0,0,0));
	GAME_ENGINE->DrawOval(50,50, 200,200);
	GAME_ENGINE->DrawLine(150,50,220,220);
	GAME_ENGINE->DrawLine(80,220, 150,50);
	GAME_ENGINE->DrawLine(60,110, 240 ,110);
	//GAME_ENGINE->DrawLine(60,110, 80,220);
	GAME_ENGINE->DrawLine(240, 110, 80,220);
	GAME_ENGINE->DrawLine(220, 220, 60,110);
	*/












}

void DrawShapes::Tick()
{
	// Insert non-paint code that needs to be executed each tick 
}

void DrawShapes::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
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


void DrawShapes::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse wheel action
}

void DrawShapes::MouseMove(int x, int y, WPARAM wParam)
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

void DrawShapes::CheckKeyboard()
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

void DrawShapes::KeyPressed(TCHAR cKey)
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

void DrawShapes::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
}




