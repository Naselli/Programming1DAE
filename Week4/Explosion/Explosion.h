//-----------------------------------------------------------------
// Main Game  File
// C++ Header - Explosion.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// Explosion Class																
//-----------------------------------------------------------------
class Explosion : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	Explosion();

	virtual ~Explosion() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	Explosion(const Explosion& other) = delete;
	Explosion(Explosion&& other) noexcept = delete;
	Explosion& operator=(const Explosion& other) = delete;
	Explosion& operator=(Explosion&& other) noexcept = delete;

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

	const int SQUARE_SIZE { 50 };
	const int SCREENWIDTH { 800 };
	const int SCREENHEIGTH { 500 };
	const int FRAMERATE { 50 };

	POINT CENTER_POINT { (SCREENWIDTH / 2), (SCREENHEIGTH / 2)};

	

};
