//-----------------------------------------------------------------
// Main Game  File
// C++ Header - TankDemo.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include <stdbool.h>
#include <stdbool.h>

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// Structs and enum classes
//-----------------------------------------------------------------
enum class Direction
{
	Up, UpRight, Right, DownRight, Down, DownLeft, Left, UpLeft
};

struct TankData
{
	POINT position;
	bool isMoving;
	Direction direction;
	const int SPEED;
};

struct BulletData 
{
	POINT position;
	bool isFired;
	Direction direction;
	const int SPEED;

	int animationCounter;
	const int MAX_ANIMATION;
	const int RADIUS; 
};


//-----------------------------------------------------------------
// TankDemo Class																
//-----------------------------------------------------------------
class TankDemo : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	TankDemo();

	virtual ~TankDemo() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	TankDemo(const TankDemo& other) = delete;
	TankDemo(TankDemo&& other) noexcept = delete;
	TankDemo& operator=(const TankDemo& other) = delete;
	TankDemo& operator=(TankDemo&& other) noexcept = delete;

	//---------------------------
	// General Methods
	//---------------------------
	void Initialize(HINSTANCE hInstance) override;
	void Start() override;
	void End() override;
	void Paint(RECT rect) override;
	void Tick() override;
	void MouseButtonAction(bool isLeft, bool isDown, int x, int y, WPARAM wParam) override;
	void MouseWheelAction(int x, int y, int distance, WPARAM wParam) override;
	void MouseMove(int x, int y, WPARAM wParam) override;
	void CheckKeyboard() override;
	void KeyPressed(TCHAR cKey) override;
	
	void CallAction(Caller* callerPtr) override;

	// -------------------------
	// My Functions
	// -------------------------
	void PaintTank();
	void PaintBullet();
	
private:
	// -------------------------
	// Constants
	// -------------------------
	const int WINDOW_WIDTH	{ 800 };
	const int WINDOW_HEIGHT	{ 800 };
	const int NR_ROWS		{   8 };
	
	// -------------------------
	// Datamembers
	// -------------------------
	Bitmap* m_BmpTankPtr	{ };
	int m_FrameWidth		{ };

	TankData m_TankData{
		{ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 },
		false,
		Direction::Right,
		2 };

	BulletData m_BulletData{
		{-1,-1},
		false,
		Direction::Right,
		5,
		-1,
		50,
		3
	};

};
