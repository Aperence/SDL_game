#include <iostream>
#include "Vector2D.h"
#include "ECS/Components.h"
#include <math.h>

Vector2D::Vector2D()
{
    x = y = 0.0f;
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

void Vector2D::normalize()
{
    float length = x * x + y * y;
    if (length < 0.0000001) return;
    x = x / length;
    y = y / length;
}


Vector2D& operator*(const Vector2D& v, const float h)
{
    Vector2D *ret = new Vector2D(v.x * h, v.y * h);
    return *ret;
}

Vector2D& operator*(const float h, const Vector2D& v)
{
    return v * h;
}

Vector2D& operator/(const Vector2D& v, const float h)
{
    Vector2D *ret = new Vector2D(v.x / h, v.y / h);
    return *ret;
}

Vector2D& operator/(const float h, const Vector2D& v)
{
    return v / h;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& v)
{
    stream << "Vec2D(" << v.x << "," << v.y << ")";
    return stream;
}

void Vector2D::rotate(double angle, Vector2D center) {
    double angle_rad = angle * M_PI / 180.0;
    float oldX = x;
    float oldY = y;
    x = (oldX-center.x) * cos(angle_rad) - (oldY-center.y) * sin(angle_rad) + center.x;
    y = (oldX - center.x) * sin(angle_rad) + (oldY - center.y) * cos(angle_rad) + center.y;
}

