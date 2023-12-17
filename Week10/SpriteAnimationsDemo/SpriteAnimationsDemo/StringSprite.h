#pragma once
#include "utils.h"
using namespace utils;

class StringSprite
{
public:
    StringSprite(   const std::string& text,
                    const std::string& fontPath,
                    int size,
                    const Color4f& color,
                    const Point2f& position);
    ~StringSprite();

    void Draw();
    void Move( const Point2f position );
    void ReCreate( const std::string& text,
                    const std::string& fontPath,
                    int size,
                    const Color4f& color);

    const Point2f& GetPosition();
private:
    void LoadTexture(const std::string& text,
                    const std::string& fontPath,
                    int size,
                    const Color4f& color);
    
    Texture m_StringTexture;
    Point2f m_Position;
    
    
};
