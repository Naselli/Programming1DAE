#pragma once
class Fraction
{
public:
     Fraction(int numerator, int denominator);
     ~Fraction();
     void Draw(const Point2f& pos, int size);
     float GetValue();
    
private:
     int m_Numerator{};
     int m_Denominator{};
};

