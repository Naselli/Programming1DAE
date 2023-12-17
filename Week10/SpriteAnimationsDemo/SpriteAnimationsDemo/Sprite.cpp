#include "pch.h"
#include "Sprite.h"

Sprite::Sprite ( const std::string & texturePath, float x, float y, int rows, int columns, float frameDelay ) :
                m_Location{ x, y },
                m_Rows{ rows },
                m_Columns{ columns },
                m_FrameDelay{ frameDelay }
{
    TextureFromFile(texturePath, m_Texture);
    m_FrameWidth = m_Texture.width / m_Columns;
    m_FrameHeight = m_Texture.height / m_Rows;
}

Sprite::~Sprite()
{
    DeleteTexture(m_Texture);
}

void Sprite::Draw()
{
    const int rowIndex{ m_CurrentFrame / m_Columns };
    const int colIndex{ m_CurrentFrame % m_Columns };

    const Rectf sourceRect{ colIndex * m_FrameWidth,
                            rowIndex * m_FrameHeight,
                            m_FrameWidth,
                            m_FrameHeight };

    DrawTexture(m_Texture, m_Location, sourceRect);
}

void Sprite::Update(float elapsedSec)
{
    m_AccumulatedTime += elapsedSec;

    if (m_AccumulatedTime > m_FrameDelay)
    {
        ++m_CurrentFrame;
        if (m_CurrentFrame >= m_Rows * m_Columns)
        {
            m_CurrentFrame = 0;
        }
        m_AccumulatedTime -= m_FrameDelay;
    }
}
