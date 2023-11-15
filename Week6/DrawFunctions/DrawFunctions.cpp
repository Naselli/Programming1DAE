//-----------------------------------------------------------------
// Main Game File
// C++ Source - DrawFunctions.cpp - version v7_02_firstyear
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "DrawFunctions.h"

#include <corecrt_math_defines.h>

//-----------------------------------------------------------------
// DrawFunctions methods																				
//-----------------------------------------------------------------

DrawFunctions::DrawFunctions() 																	
{
	// nothing to create
}

DrawFunctions::~DrawFunctions()																						
{
	// nothing to destroy
}


void DrawFunctions::Initialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::Initialize(hInstance);
	GAME_ENGINE->SetTitle("Game Engine version 7_02 firstyear");					
	GAME_ENGINE->RunGameLoop(true);		
	
	// Set the optional values
	GAME_ENGINE->SetWidth(1000);
	GAME_ENGINE->SetHeight(1000);
    GAME_ENGINE->SetFrameRate(50);

	// Set the keys that the game needs to listen to
	//std::stringstream buffer;
	//buffer << "KLMO";
	//buffer << (char) VK_LEFT;
	//buffer << (char) VK_RIGHT;
	//GAME_ENGINE->SetKeyList(buffer.str());
}

void DrawFunctions::Start()
{
	// Insert the code that needs to be executed at the start of the game
}

void DrawFunctions::Paint(RECT rect)
{
	GAME_ENGINE->DrawSolidBackground( RGB(200,200,200) );
	GAME_ENGINE->SetColor( RGB(0,0,0) );
	//Rectangle
	DrawRectangles( {20, 20}, 100, 10, 10);
	DrawRectangles( {140, 40}, 80, 15, 5);
	DrawRectangles( {240, 60}, 60, 20, 3);

	DrawGradient( 300, 300, 300, 30, RGB(30,50,250), RGB(250,40,40) );

	//Triangle
	GAME_ENGINE->SetColor( RGB(255, 0, 0) );
	DrawCircles( {20, 500}, 3, 5, 50);

	GAME_ENGINE->SetColor( RGB(0,255,0) );
	DrawCircles( {400, 500 }, 6, 4, 80, 2 , 10);

	DrawTriangles({300,200}, 200, RGB(255,0,0), 3);
	
	for ( int i{20} ; i < 360 ; i += 30)
	{
		DrawPentagram( 20 + i ,150,10,i );
	}
}

void DrawFunctions::End()
{
	// Insert the code that needs to be executed at the closing of the game
}

void DrawFunctions::DrawRectangles(POINT position, int width, int spacing, int count)
{
	for ( int counter{ 0 }; counter < count; ++counter )
	{
		GAME_ENGINE->DrawRect(
			position.x + (spacing * counter) / 2,
			position.y + (spacing * counter) / 2,
			width - (spacing * counter),
			width - (spacing * counter) );
	}
}


void DrawFunctions::DrawGradient(int x, int y, int width, int height, COLORREF firstColor, COLORREF secondColor)
{
	const int firstRed = { GetRValue( firstColor )};
	const int firstGreen = { GetGValue( firstColor )};
	const int firstBlue = { GetBValue( firstColor )};

	const int secondRed   = { GetRValue( secondColor )};
	const int secondGreen = { GetGValue( secondColor )};
	const int secondBlue  = { GetBValue( secondColor )};

	const double incrementRed { (secondRed - firstRed)		/ (double)width};
	const double incrementGreen { (secondGreen - firstGreen)	/ (double)width};
	const double incrementBlue { (secondBlue - firstBlue)		/ (double)width};

	double currentRed { (double)firstRed};
	double currentGreen { (double)firstGreen};
	double currentBlue { (double)firstBlue};


	for ( int lineCounter{}; lineCounter < width; ++lineCounter )
	{
		GAME_ENGINE->SetColor( RGB(int(currentRed), int(currentGreen), int(currentBlue)) );
		const int xPos{x + lineCounter};
		GAME_ENGINE->DrawLine( xPos, y,xPos, y + height );

		currentRed += incrementRed;
		currentGreen += incrementGreen;
		currentBlue += incrementBlue;
	}
}

void DrawFunctions::DrawCircles( POINT postition, int rows, int columns, int size)
{
	for ( int counterColumn{0}; counterColumn < columns; ++counterColumn)
	{
		for ( int counterRow{0}; counterRow < rows; ++counterRow )
		{
				GAME_ENGINE->FillOval(
					postition.x + ( counterColumn * size),
					postition.y + (counterRow * size),
					size,
					size
					);	
		}
	}
}

void DrawFunctions::DrawCircles( POINT postition, int rows, int columns, int size, int amount, int spacing)
{
	for ( int counterColumn{0}; counterColumn < columns; ++counterColumn)
	{
		for ( int counterRow{0}; counterRow < rows; ++counterRow )
		{
			for ( int counterCircles{1}; counterCircles <= amount; ++counterCircles )
			{
				GAME_ENGINE->SetColor( RGB(0,255,0) );
				if ( counterCircles == 1 )
				{
					GAME_ENGINE->SetColor( RGB(255,0,0) );
				}
				GAME_ENGINE->FillOval(
					postition.x + ( counterColumn * size) + (spacing * counterCircles),
					postition.y + (counterRow * size) + (spacing * counterCircles),
					 size - (spacing * counterCircles),
					 size - (spacing * counterCircles)
					);	
			}
		}
	}
}

void DrawFunctions::DrawTriangles ( POINT position, int height, COLORREF colour, int amount ) 
{
	 for ( int counter {0}; counter < amount; ++counter)
	 {
	 	POINT TopPoint{},LeftPoint{},RightPoint{};
	
	 	TopPoint = position;
	 	LeftPoint = {
	 		position.x - height/2,
			 position.y + height
		 };
	 	RightPoint = {
	 		position.x + height/2,
			 position.y + height 
		 };
	
	 	FillTriangle( TopPoint, LeftPoint, RightPoint, colour );
	 }
	
}

void DrawFunctions::FillTriangle(POINT p1, POINT p2, POINT p3)
{
	POINT tempArr[]{ p1, p2, p3};
	GAME_ENGINE->FillPolygon( tempArr, 3 , true);
}

void DrawFunctions::FillTriangle(POINT p1, POINT p2, POINT p3, COLORREF colour)
{
	GAME_ENGINE->SetColor( colour );
	FillTriangle( p1, p2, p3 );
}

void DrawFunctions::DrawPentagram(int centerX, int centerY, int radius, int startAngle)
{
	const int NR_POINTS { 5 };
	const int ANGLE_DIFFERENCE { 360 / NR_POINTS};
	const int QUARTER_CIRCLE { 90 };

	for (int countLines{}, angle{startAngle + QUARTER_CIRCLE} ; countLines < NR_POINTS ; ++countLines, angle += ANGLE_DIFFERENCE * 2 )
	{
		int secondAngle { angle + ANGLE_DIFFERENCE * 2};

		int x1{ int(centerX + radius * cos((2 * M_PI) / 360 * angle ))};
		int y1{ int(centerY + radius * sin((2 * M_PI) / 360 * angle ))};
		int x2{ int(centerX + radius * cos((2 * M_PI) / 360 * secondAngle ))};
		int y2{ int(centerY + radius * sin((2 * M_PI) / 360 * secondAngle ))};

		GAME_ENGINE->DrawLine( x1, y1, x2, y2 );
	}
}







void DrawFunctions::Tick()
{
	// Insert non-paint code that needs to be executed each tick 
}

void DrawFunctions::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
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


void DrawFunctions::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse wheel action
}

void DrawFunctions::MouseMove(int x, int y, WPARAM wParam)
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

void DrawFunctions::CheckKeyboard()
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

void DrawFunctions::KeyPressed(TCHAR cKey)
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

void DrawFunctions::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
}




