//-----------------------------------------------------------------
// Main Game  File
// C++ Header - RandomRectangle.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// RandomRectangle Class																
//-----------------------------------------------------------------
class RandomRectangle : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	RandomRectangle();

	virtual ~RandomRectangle() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	RandomRectangle(const RandomRectangle& other) = delete;
	RandomRectangle(RandomRectangle&& other) noexcept = delete;
	RandomRectangle& operator=(const RandomRectangle& other) = delete;
	RandomRectangle& operator=(RandomRectangle&& other) noexcept = delete;

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
	// Datamembers
	// -------------------------


};
