#include "pch.h"
#include "Fraction.h"
#include "utils.h"

using namespace utils;

Fraction::Fraction ( int numerator, int denominator ) : m_Numerator( numerator )
{
    if ( denominator == 0 ) m_Denominator = 1;
    else m_Denominator = denominator;
}

Fraction::~Fraction ( )
{
    
}

void Fraction::Draw ( const Point2f & pos, int size )
{
    for(int i = 0; i < (m_Denominator); i++)
    {
        if ( i < m_Numerator )
        {
            SetColor( 1,0,0 );
            FillRect( pos.x + ((float)i * size), pos.y, size, size );
            SetColor( 1,1,1 );
            DrawRect( pos.x+ ((float)i * size), pos.y, size, size  );
        }
        else
        {
            DrawRect( pos.x+ ((float)i * size), pos.y, size, size );  
        }
    }
}

float Fraction::GetValue ( )
{
    return float(m_Numerator) / float(m_Denominator);
}
