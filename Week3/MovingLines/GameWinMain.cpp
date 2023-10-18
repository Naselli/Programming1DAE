//-----------------------------------------------------------------
// Game Engine WinMain Function
// C++ Source - GameWinMain.cpp - version v7_02_firstyear
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "GameWinMain.h"
#include "GameEngine.h"

#include "MovingLines.h"	

//-----------------------------------------------------------------
// Windows Functions
//-----------------------------------------------------------------
int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	if (GAME_ENGINE == nullptr) return FALSE;		// create the game engine object, exit if it fails

	GAME_ENGINE->SetGame(new MovingLines());					// any class that implements AbstractGame

	return GAME_ENGINE->Run(hInstance, nCmdShow);	// here we go
}
