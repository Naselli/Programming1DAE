#include "pch.h"
#include "StringSprite.h"

StringSprite::StringSprite ( const std::string & text, const std::string & fontPath, int size, const Color4f & color, const Point2f & position ) :
m_Position( position )
{
    LoadTexture( text, fontPath, size, color );
}
StringSprite::~StringSprite ( )
{
    DeleteTexture( m_StringTexture );
}

void StringSprite::Draw ( )
{
    DrawTexture(m_StringTexture, m_Position);
}

void StringSprite::Move ( const Point2f position )
{
    m_Position = position;
}

void StringSprite::ReCreate ( const std::string & text, const std::string & fontPath, int size, const Color4f & color )
{
    DeleteTexture( m_StringTexture );
    LoadTexture( text, fontPath, size, color );
}

const Point2f& StringSprite::GetPosition ( )
{
    return m_Position;
}

void StringSprite::LoadTexture ( const std::string & text, const std::string & fontPath, int size,
        const Color4f & color )
{
    TextureFromString( text, fontPath, size, color, m_StringTexture );
}








