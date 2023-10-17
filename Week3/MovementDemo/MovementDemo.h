//-----------------------------------------------------------------
// Main Game  File
// C++ Header - MovementDemo.h - version v7_02_firstyear			
//-----------------------------------------------------------------

#pragma once

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Resource.h"
#include "GameEngine.h"
#include "AbstractGame.h"

//-----------------------------------------------------------------
// MovementDemo Class																
//-----------------------------------------------------------------
class MovementDemo : public AbstractGame, public Callable
{
public:
    //---------------------------
    // Constructor(s) and Destructor
    //---------------------------
    MovementDemo ( );

    virtual ~MovementDemo ( ) override;

    //---------------------------
    // Disabling copy/move constructors and assignment operators   
    //---------------------------
    MovementDemo ( const MovementDemo & other )                 = delete;
    MovementDemo ( MovementDemo && other ) noexcept             = delete;
    MovementDemo & operator= ( const MovementDemo & other )     = delete;
    MovementDemo & operator= ( MovementDemo && other ) noexcept = delete;

    //---------------------------
    // General Methods
    //---------------------------
    void Initialize ( HINSTANCE hInstance ) override;
    void Start ( ) override;
    void End ( ) override;
    void Paint ( RECT rect ) override;
    void Tick ( ) override;
    void MouseButtonAction ( bool isLeft, bool isDown, int x, int y, WPARAM wParam ) override;
    void MouseWheelAction ( int x, int y, int distance, WPARAM wParam ) override;
    void MouseMove ( int x, int y, WPARAM wParam ) override;
    void CheckKeyboard ( ) override;
    void KeyPressed ( TCHAR cKey ) override;

    void CallAction ( Caller * callerPtr ) override;

private:
    // -------------------------
    // Constants
    // -------------------------
    const int SCREENWIDTH                   { 1024 };
    const int SCREENHEIGHT                  { 768 };
    const int FRAMERATE                     { 50 };
    const int LINEAR_PLATFORM_X             { SCREENWIDTH      / 4 };
    const int LINEAR_PLATFORM_Y_BASE        { SCREENHEIGHT * 3 / 4 };
    const int WAVE_PLATFORM_X               { SCREENWIDTH  * 3 / 4 };
    const int WAVE_PLATFORM_Y_BASE          { SCREENHEIGHT * 3 / 4 };
    const int AMPLITUDE                     { 100 };
    const int PERIOD_IN_SECONDS             { 3 };
    const int NR_OF_QUADRANTS               { 4 };

    const double LINEAR_MOVEMENT_PER_FRAME_IN_PIXELS{
        ( double ) ( AMPLITUDE * NR_OF_QUADRANTS ) /
        ( double ) ( PERIOD_IN_SECONDS * FRAMERATE)
    };

    // -------------------------
    // Datamembers
    // -------------------------
    Bitmap* m_BmpPlatformPtr{ };

    //Linear movement
    double m_LinearMovement_Y_Deviation{};
    int m_LinearMovement_Direction{ + 1 };

    //Wave movement
    int m_TickCounter{};
    double m_WaveMovement_Y_Deviation{};
};
