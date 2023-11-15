//-----------------------------------------------------------------
// Main Game  File
// C++ Header - DrawFunctions.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------

#include "Resource.h"	
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// DrawFunctions Class																
//-----------------------------------------------------------------
class DrawFunctions : public AbstractGame, public Callable
{
public:				
	//---------------------------
	// Constructor(s) and Destructor
	//---------------------------
	DrawFunctions();

	virtual ~DrawFunctions() override;

	//---------------------------
	// Disabling copy/move constructors and assignment operators   
	//---------------------------
	DrawFunctions(const DrawFunctions& other) = delete;
	DrawFunctions(DrawFunctions&& other) noexcept = delete;
	DrawFunctions& operator=(const DrawFunctions& other) = delete;
	DrawFunctions& operator=(DrawFunctions&& other) noexcept = delete;

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


	// -------------------------
	// My Function
	// -------------------------
	void DrawRectangles ( POINT position, int width, int spacing, int count );
	void DrawCircles( POINT postition, int rows, int columns, int size);
	void DrawCircles( POINT postition, int rows, int columns, int size, int amount, int spacing);
	void DrawTriangles ( POINT position, int height, COLORREF colour, int amount );
	void DrawGradient(int x, int y, int width, int height, COLORREF firstColor, COLORREF secondColor);
	void FillTriangle ( POINT p1, POINT p2, POINT p3 );
	void FillTriangle ( POINT p1, POINT p2, POINT p3, COLORREF colour );
	void DrawPentagram ( int centerX, int centerY, int radius, int startAngle );

private:
	// -------------------------
	// Datamembers
	// -------------------------


};
