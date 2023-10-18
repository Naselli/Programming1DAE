//-----------------------------------------------------------------
// Main Game  File
// C++ Header - GrowingBars.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// GrowingBars Class																
//-----------------------------------------------------------------
class GrowingBars : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	GrowingBars();

	virtual ~GrowingBars() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	GrowingBars(const GrowingBars& other) = delete;
	GrowingBars(GrowingBars&& other) noexcept = delete;
	GrowingBars& operator=(const GrowingBars& other) = delete;
	GrowingBars& operator=(GrowingBars&& other) noexcept = delete;

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

	const int BAR_POSX					{ 50 };
	const int BAR_POSY					{ 50 };

	const int BAR_WIDTH					{ 600 };
	const int BAR_HEIGTH				{ 100 };

	//first bar
	int FIRSTBAR_SPEED_IN_PIXELS		{ 15 }; //not const because the value changes
	int m_FirstBarWidth{};

	//second bar
	int SECONDBAR_SPEED_IN_PIXELS		{ 30 }; //not const because the value changes
	int m_SecondBarWidth{};




};
