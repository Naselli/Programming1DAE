#include "pch.h"
#include "Light.h"
#include "utils.h"
using namespace utils;

Light::Light ( const Rectf & rect, const Color4f & color ) :
m_Rect( rect ), m_isOn( false ), m_Color( color )
{
    //nothing to do
}

Light::~Light ( )
{
    
}

void Light::Draw ( )
{
    //fill element
    if ( m_isOn )SetColor(m_Color);
    else SetColor( .25, .25, .25 );
    FillRect( m_Rect );
    

    //draw outline
    SetColor( .75, .75, .75  );
    DrawRect( m_Rect );
}

void Light::OnMouseDownEvent ( const SDL_MouseButtonEvent & e )
{
    const Point2f mousePos { float(e.x), float(e.y) };

    if ( IsPointInRect( mousePos, m_Rect) )
    {
        m_isOn = !m_isOn;
    }
}

bool Light::IsOn ( )
{
    return m_isOn;
}
