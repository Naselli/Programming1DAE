//-----------------------------------------------------------------
// Main Game  File
// C++ Header - LoopedDrawings.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// LoopedDrawings Class																
//-----------------------------------------------------------------
class LoopedDrawings : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	LoopedDrawings();

	virtual ~LoopedDrawings() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	LoopedDrawings(const LoopedDrawings& other) = delete;
	LoopedDrawings(LoopedDrawings&& other) noexcept = delete;
	LoopedDrawings& operator=(const LoopedDrawings& other) = delete;
	LoopedDrawings& operator=(LoopedDrawings&& other) noexcept = delete;

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
