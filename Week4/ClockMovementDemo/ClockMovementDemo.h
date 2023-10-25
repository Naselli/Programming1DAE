//-----------------------------------------------------------------
// Main Game  File
// C++ Header - ClockMovementDemo.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"


//-----------------------------------------------------------------
//
//-----------------------------------------------------------------



//-----------------------------------------------------------------
// ClockMovementDemo Class																
//-----------------------------------------------------------------
class ClockMovementDemo : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	ClockMovementDemo();

	virtual ~ClockMovementDemo() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	ClockMovementDemo(const ClockMovementDemo& other) = delete;
	ClockMovementDemo(ClockMovementDemo&& other) noexcept = delete;
	ClockMovementDemo& operator=(const ClockMovementDemo& other) = delete;
	ClockMovementDemo& operator=(ClockMovementDemo&& other) noexcept = delete;

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

private:
	// -------------------------
	// Constants
	// -------------------------
	const int WINDOWWIDTH{ 800 };
	const int WINDOWHEIGTH{ 800 };
	const int FRAMERATE{ 50 };

	const int RADIUS{ 300 };

	// -------------------------
	// Datamembers
	// -------------------------
	POINT m_CenterPoint	{};

	int m_Angle			{ 90 };
	int m_DeltaAngle	{};//90 degrees 

	Button* m_BtnLeftPtr{};
	Button* m_BtnRightPtr{};

};
