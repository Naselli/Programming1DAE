//-----------------------------------------------------------------
// Main Game  File
// C++ Header - GameEngineDemo.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// GameEngineDemo Class																
//-----------------------------------------------------------------
class GameEngineDemo : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	GameEngineDemo();

	virtual ~GameEngineDemo() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	GameEngineDemo(const GameEngineDemo& other) = delete;
	GameEngineDemo(GameEngineDemo&& other) noexcept = delete;
	GameEngineDemo& operator=(const GameEngineDemo& other) = delete;
	GameEngineDemo& operator=(GameEngineDemo&& other) noexcept = delete;

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
