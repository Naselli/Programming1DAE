//-----------------------------------------------------------------
// Main Game File
// C++ Source - TankDemo.cpp - version v7_02_firstyear
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "TankDemo.h"



//-----------------------------------------------------------------
// TankDemo methods																				
//-----------------------------------------------------------------

TankDemo::TankDemo() 																	
{
	// nothing to create
}

TankDemo::~TankDemo()																						
{
	// nothing to destroy
}


void TankDemo::Initialize(HINSTANCE hInstance)			
{
	// Set the required values
	AbstractGame::Initialize(hInstance);
	GAME_ENGINE->SetTitle("Tank Demo");					
	GAME_ENGINE->RunGameLoop(true);		
	
	// Set the optional values
	GAME_ENGINE->SetWidth(WINDOW_WIDTH);
	GAME_ENGINE->SetHeight(WINDOW_HEIGHT);
    GAME_ENGINE->SetFrameRate(50);

	// Set the keys that the game needs to listen to
	//std::stringstream buffer;
	//buffer << "KLMO";
	//buffer << (char) VK_LEFT;
	//buffer << (char) VK_RIGHT;
	//GAME_ENGINE->SetKeyList(buffer.str());
}

void TankDemo::Start()
{
	m_BmpTankPtr = new Bitmap("Bitmaps/tank.bmp");
	if ( !m_BmpTankPtr->Exists(  ) )
		GAME_ENGINE->MessageBox( "Bitmap not found!" );

	m_BmpTankPtr->SetTransparencyColor( RGB(255, 0, 255) );
	m_FrameWidth = m_BmpTankPtr->GetHeight(  ) / NR_ROWS;
}

void TankDemo::End()
{
	delete m_BmpTankPtr;
}

void TankDemo::Paint(RECT rect)
{
	GAME_ENGINE->DrawSolidBackground( RGB(219,219,219) );
	PaintTank(  );
	if ( m_BulletData.isFired )
		PaintBullet();
}

void TankDemo::PaintTank ( )
{
	const int yPos{ int(m_TankData.direction) * m_FrameWidth};
	const RECT SOURCE_RECT{ 0, yPos, m_FrameWidth, yPos + m_FrameWidth}; 

	GAME_ENGINE->DrawBitmap( m_BmpTankPtr,
		m_TankData.position.x - m_FrameWidth / 2,
		m_TankData.position.y - m_FrameWidth /2,
		SOURCE_RECT );
}

void TankDemo::PaintBullet ( )
{
	
}

void TankDemo::Tick()
{
	// Insert non-paint code that needs to be executed each tick 
}

void TankDemo::MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam)
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
void TankDemo::MouseWheelAction(int x, int y, int distance, WPARAM wParam)
{	
	// Insert the code that needs to be executed when the game registers a mouse wheel action
}
void TankDemo::MouseMove(int x, int y, WPARAM wParam)
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
void TankDemo::CheckKeyboard()
{
	// check the keys 
	const bool isUp { GAME_ENGINE-> IsKeyDown( VK_UP )};
	const bool isDown { GAME_ENGINE-> IsKeyDown( VK_DOWN )};
	const bool isLeft { GAME_ENGINE-> IsKeyDown( VK_LEFT )};
	const bool isRight { GAME_ENGINE-> IsKeyDown( VK_RIGHT )};

	// update direction
	if ( isUp )
	{
		if ( isLeft )		m_TankData.direction = Direction::UpLeft;
		else if ( isRight ) m_TankData.direction = Direction::UpRight;
		else				m_TankData.direction = Direction::Up;
	}

	else if (isDown)
	{
		if ( isLeft )		m_TankData.direction = Direction::DownLeft;
		else if ( isRight ) m_TankData.direction = Direction::DownRight;
		else				m_TankData.direction = Direction::Down;
	}
	else if (isLeft) m_TankData.direction = Direction::Left;
	else if (isRight) m_TankData.direction = Direction::Right;

	if ( isUp ) m_TankData.position.y -= m_TankData.SPEED;
	if ( isDown ) m_TankData.position.y += m_TankData.SPEED;
	if ( isLeft ) m_TankData.position.x -= m_TankData.SPEED;
	if ( isRight ) m_TankData.position.x += m_TankData.SPEED;
	
	/*
	//update position
	switch ( m_TankData.direction ) {
		case Direction::Up:
			m_TankData.position.y -= m_TankData.SPEED;
		break;
		case Direction::UpRight:
			m_TankData.position.y -= m_TankData.SPEED / 2;
			m_TankData.position.x += m_TankData.SPEED / 2;
		break;
		case Direction::Right:
			m_TankData.position.x += m_TankData.SPEED;
			break;
		case Direction::DownRight:
			m_TankData.position.y += m_TankData.SPEED / 2;
			m_TankData.position.x += m_TankData.SPEED / 2;
			break;
		case Direction::Down:
			m_TankData.position.y += m_TankData.SPEED;
			break;
		case Direction::DownLeft:
			m_TankData.position.x -= m_TankData.SPEED / 2;
			m_TankData.position.y += m_TankData.SPEED / 2 ;
		break;
		case Direction::Left:
			m_TankData.position.x -= m_TankData.SPEED;
			break;
		case Direction::UpLeft:
			m_TankData.position.x -= m_TankData.SPEED / 2;
			m_TankData.position.y -= m_TankData.SPEED / 2;
			break;
		default: ;
	}*/
	
}
void TankDemo::KeyPressed(TCHAR cKey)
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
void TankDemo::CallAction(Caller* callerPtr)
{
	// Insert the code that needs to be executed when a Caller has to perform an action
}




