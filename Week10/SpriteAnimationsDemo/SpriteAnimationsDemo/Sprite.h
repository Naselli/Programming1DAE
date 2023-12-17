#pragma once
#include "utils.h"
using namespace utils;

class Sprite
{
public:
    Sprite(	const std::string& texturePath, 
                float x, float y, 
                int rows, int columns, float frameDelay);
    ~Sprite();

    void Draw();
    void Update(float elapsedSec);
    
private:
    Texture		m_Texture;
    Point2f		m_Location;
    int			m_Rows, m_Columns;
    int			m_FrameWidth{ -1 }, m_FrameHeight{ -1 };
    float		m_FrameDelay;
    float		m_AccumulatedTime{};
    int			m_CurrentFrame{};
};
