//-----------------------------------------------------------------
// Main Game  File
// C++ Header - Bitmaps.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// Bitmaps Class																
//-----------------------------------------------------------------
class Bitmaps : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	Bitmaps();

	virtual ~Bitmaps() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	Bitmaps(const Bitmaps& other) = delete;
	Bitmaps(Bitmaps&& other) noexcept = delete;
	Bitmaps& operator=(const Bitmaps& other) = delete;
	Bitmaps& operator=(Bitmaps&& other) noexcept = delete;

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
	Bitmap* m_BmpBackgroundPrt{};

	int m_Opacity{};


};
