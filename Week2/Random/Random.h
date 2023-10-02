//-----------------------------------------------------------------
// Main Game  File
// C++ Header - Random.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// Random Class																
//-----------------------------------------------------------------
class Random : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	Random();

	virtual ~Random() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	Random(const Random& other) = delete;
	Random(Random&& other) noexcept = delete;
	Random& operator=(const Random& other) = delete;
	Random& operator=(Random&& other) noexcept = delete;

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
	Font* m_FontPtr{};


};
