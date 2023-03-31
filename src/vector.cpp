#include "vector.h"


Vector::Vector()
    :x(0.0f), y(0.0f)
{ }


Vector::Vector(float x, float y)
    :x(x), y(y)
{ }


float Vector::getX() const
{
    return x;
}


float Vector::getY() const
{
    return y;
}


void Vector::setX(float x)
{
    this->x = x;
}


void Vector::setY(float y)
{
    this->y = y;
}


Vector Vector::operator-() const
{
    return Vector(-x, -y);
}


Vector Vector::operator+(const Vector& other) const
{
    return Vector(x + other.x, y + other.y);
}


Vector Vector::operator-(const Vector& other) const
{
    return Vector(x - other.x, y - other.y);
}


Vector Vector::operator+(float b) const
{
    return Vector(x + b, y + b);
}


Vector Vector::operator-(float b) const
{
    return Vector(x - b, y - b);
}


Vector Vector::operator*(float scalar) const
{
    return Vector(x * scalar, y * scalar);
}


Vector Vector::operator/(float scalar) const
{
    if(scalar == 0) {
        return Vector();
    }
    return Vector(x / scalar, y / scalar);
}


bool Vector::operator==(const Vector &other) const
{
    return (x == other.x && y == other.y);
}


bool Vector::operator!=(const Vector &other) const
{
    return !(*this == other);
}


float Vector::magnitude() const
{
    return std::sqrt(x*x + y*y);
}


float Vector::magnitudeSquerd() const
{
    return (x*x + y*y);
}


Vector Vector::normalize() const
{
    float mag = magnitude();

    if(mag == 0) {
        return Vector();
    }

    return Vector(x / mag, y / mag);
}
