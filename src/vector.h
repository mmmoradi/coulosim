#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>


class Vector
{
private:
    float x, y;

public:
    Vector();
    Vector(float x, float y);

    float getX() const;
    float getY() const;

    void setY(float y);
    void setX(float x);

    Vector operator-() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;

    Vector operator+(float b) const;
    Vector operator-(float b) const;
    Vector operator*(float scalar) const;
    Vector operator/(float scalar) const;
// TODO: add these vector operator
//    Vector dot(const Vector& other) const;
//    Vector cross(const Vector& other) const;

    bool operator==(const Vector &other) const;
    bool operator!=(const Vector &other) const;

    float magnitude() const;
    float magnitudeSquerd() const;
    Vector normalize() const;
};


#endif // VECTOR_H
