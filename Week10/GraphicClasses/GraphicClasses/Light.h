#pragma once

class Light
{
public:
    //constructor
    Light(const Rectf& rect, const Color4f& color);

    //destructor
    ~Light();
    
    //member functions
    void Draw();
    void OnMouseDownEvent( const SDL_MouseButtonEvent& e);
    bool IsOn();
    
private:
    Rectf m_Rect;
    bool m_isOn;
    Color4f m_Color;
};
