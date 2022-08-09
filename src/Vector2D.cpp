#include <iostream>
#include "Vector2D.h"
#include "ECS/Components.h"

Vector2D::Vector2D()
{
    x = y = 0;
}

Vector2D::Vector2D(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vector2D& Vector2D::Add(const Vector2D& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vector2D& Vector2D::Substract(const Vector2D& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

Vector2D& Vector2D::Multiply(const Vector2D& v)
{
    x *= v.x;
    y *= v.y;
    return *this;
}

Vector2D& Vector2D::Divide(const Vector2D& v)
{
    x /= v.x;
    y /= v.y;
    return *this;
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2)
{
    return v1.Add(v2);
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2)
{
    return v1.Add(v2);
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2)
{
    return v1.Add(v2);
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2)
{
    return v1.Add(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& v)
{
    return *this + v;
}

Vector2D& Vector2D::operator-=(const Vector2D& v)
{
    return *this - v;
}

Vector2D& Vector2D::operator*=(const Vector2D& v)
{
    return *this * v;
}

Vector2D& Vector2D::operator/=(const Vector2D& v)
{
    return *this / v;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& v)
{
    stream << "Vec2D(" << v.x << "," << v.y << ")";
    return stream;
}

