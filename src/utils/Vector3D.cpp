/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Vector3D
*/

#include "Vector3D.hpp"
#include "Point3D.hpp"

Math::Vector3D::Vector3D() : X(0), Y(0), Z(0)
{
}

Math::Vector3D::Vector3D(double x, double y, double z) :
    X(x), Y(y), Z(z)
{
}

Math::Vector3D::Vector3D(const Math::Point3D &point) :
    X(point.X), Y(point.Y), Z(point.Z)
{
}

Math::Vector3D &Math::Vector3D::operator=(const Vector3D &other)
{
    this->X = other.X;
    this->Y = other.Y;
    this->Z = other.Z;
    return *this;
}

double Math::Vector3D::length() const
{
    return (sqrt(pow(this->X, 2) + pow(this->Y, 2) + pow(this->Z, 2)));
}

double Math::Vector3D::dot(const Math::Vector3D &other) const
{
    return (this->X * other.X + this->Y * other.Y + this->Z * other.Z);
}

Math::Vector3D Math::Vector3D::normalize() const
{
    double length = this->length();

    return Math::Vector3D(this->X / length, this->Y / length, this->Z / length);
}

Math::Vector3D Math::Vector3D::random() const
{
    return Math::Vector3D((rand() % 100) / 100.0, (rand() % 100) / 100.0, (rand() % 100) / 100.0);
}

Math::Vector3D Math::Vector3D::random(double min, double max) const
{
    return Math::Vector3D((rand() % 100) / 100.0 * (max - min) + min, (rand() % 100) / 100.0 * (max - min) + min, (rand() % 100) / 100.0 * (max - min) + min);
}

Math::Vector3D &Math::Vector3D::operator+=(Math::Vector3D &other)
{
    this->X += other.X;
    this->Y += other.Y;
    this->Z += other.Z;
    return *this;
}

Math::Vector3D &Math::Vector3D::operator-=(Math::Vector3D &other)
{
    this->X -= other.X;
    this->Y -= other.Y;
    this->Z -= other.Z;
    return *this;
}

Math::Vector3D &Math::Vector3D::operator*=(const Math::Vector3D &other)
{
    this->X *= other.X;
    this->Y *= other.Y;
    this->Z *= other.Z;
    return *this;
}

Math::Vector3D &Math::Vector3D::operator/=(const Math::Vector3D &other)
{
    this->X /= other.X;
    this->Y /= other.Y;
    this->Z /= other.Z;
    return *this;
}

Math::Vector3D Math::Vector3D::operator+(const Math::Vector3D &other) const
{
    Math::Vector3D tmp;

    tmp.X = this->X + other.X;
    tmp.Y = this->Y + other.Y;
    tmp.Z = this->Z + other.Z;
    return tmp;
}

Math::Vector3D Math::Vector3D::operator-(const Math::Vector3D &other) const
{
    Math::Vector3D tmp;

    tmp.X = this->X - other.X;
    tmp.Y = this->Y - other.Y;
    tmp.Z = this->Z - other.Z;
    return tmp;
}

Math::Vector3D Math::Vector3D::operator*(const Math::Vector3D &other) const
{
    Math::Vector3D tmp;

    tmp.X = this->X * other.X;
    tmp.Y = this->Y * other.Y;
    tmp.Z = this->Z * other.Z;
    return tmp;
}

Math::Vector3D Math::Vector3D::operator/(const Math::Vector3D &other) const
{
    Math::Vector3D tmp;

    tmp.X = this->X / other.X;
    tmp.Y = this->Y / other.Y;
    tmp.Z = this->Z / other.Z;
    return tmp;
}

Math::Vector3D Math::Vector3D::operator*(double value) const
{
    Math::Vector3D tmp;

    tmp.X = this->X * value;
    tmp.Y = this->Y * value;
    tmp.Z = this->Z * value;
    return tmp;
}

Math::Vector3D &Math::Vector3D::operator*=(double value)
{
    this->X *= value;
    this->Y *= value;
    this->Z *= value;
    return *this;
}

Math::Vector3D Math::Vector3D::operator/(double value) const
{
    Math::Vector3D tmp;

    tmp.X = this->X / value;
    tmp.Y = this->Y / value;
    tmp.Z = this->Z / value;
    return tmp;
}

Math::Vector3D Math::Vector3D::operator-(const Math::Point3D &other) const
{
    Math::Vector3D tmp;

    tmp.X = this->X - other.X;
    tmp.Y = this->Y - other.Y;
    tmp.Z = this->Z - other.Z;
    return tmp;
}

Math::Vector3D Math::Vector3D::operator-(double value) const
{
    Math::Vector3D tmp;

    tmp.X = this->X - value;
    tmp.Y = this->Y - value;
    tmp.Z = this->Z - value;
    return tmp;
}

Math::Vector3D Math::Vector3D::operator+(double value) const
{
    Math::Vector3D tmp;

    tmp.X = this->X + value;
    tmp.Y = this->Y + value;
    tmp.Z = this->Z + value;
    return tmp;
}

Math::Vector3D &Math::Vector3D::operator/=(double value)
{
    this->X /= value;
    this->Y /= value;
    this->Z /= value;
    return *this;
}

Math::Vector3D::~Vector3D()
{
}
