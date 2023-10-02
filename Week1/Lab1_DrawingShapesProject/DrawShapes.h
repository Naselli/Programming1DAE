//-----------------------------------------------------------------
// Main Game  File
// C++ Header - DrawShapes.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// DrawShapes Class																
//-----------------------------------------------------------------
class DrawShapes : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	DrawShapes();

	virtual ~DrawShapes() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	DrawShapes(const DrawShapes& other) = delete;
	DrawShapes(DrawShapes&& other) noexcept = delete;
	DrawShapes& operator=(const DrawShapes& other) = delete;
	DrawShapes& operator=(DrawShapes&& other) noexcept = delete;

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
