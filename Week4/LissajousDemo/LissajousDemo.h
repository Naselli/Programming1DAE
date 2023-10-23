//-----------------------------------------------------------------
// Main Game  File
// C++ Header - LissajousDemo.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"


//-----------------------------------------------------------------
// Structs and enum classes
//-----------------------------------------------------------------
enum class AnimationMode
{
	None,
	Vertical,
	Horizontal,
	Both
};

//-----------------------------------------------------------------
// LissajousDemo Class																
//-----------------------------------------------------------------
class LissajousDemo : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	LissajousDemo();

	virtual ~LissajousDemo() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	LissajousDemo(const LissajousDemo& other) = delete;
	LissajousDemo(LissajousDemo&& other) noexcept = delete;
	LissajousDemo& operator=(const LissajousDemo& other) = delete;
	LissajousDemo& operator=(LissajousDemo&& other) noexcept = delete;

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
	const int WINDOWWIDTH	{ 800 };
	const int WINDOWHEIGTH	{ 800 };
	const int FRAMERATE		{  50 };

	const int RADIUS		{  10 };

	int m_CenterX{ WINDOWWIDTH  / 2 };
	int m_CenterY{ WINDOWHEIGTH / 2 };

	AnimationMode m_AnimationMode{ AnimationMode::None };

};
