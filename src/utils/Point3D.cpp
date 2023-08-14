/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Point3D
*/

#include "Point3D.hpp"
#include "Vector3D.hpp"

Math::Point3D::Point3D() :
    X(0), Y(0), Z(0)
{
}

Math::Point3D::Point3D(double x, double y, double z) :
    X(x), Y(y), Z(z)
{
}

Math::Point3D::Point3D(const Vector3D &vector) :
    X(vector.X), Y(vector.Y), Z(vector.Z)
{
}

Math::Point3D Math::Point3D::operator+(const Math::Vector3D &vector) const
{
    return Math::Point3D(this->X + vector.X, this->Y + vector.Y, this->Z + vector.Z);
}

Math::Point3D Math::Point3D::operator-(const Math::Point3D &point) const
{
    return Math::Point3D(this->X - point.X, this->Y - point.Y, this->Z - point.Z);
}

Math::Point3D Math::Point3D::operator*(const Math::Point3D &point) const
{
    return Math::Point3D(this->X * point.X, this->Y * point.Y, this->Z * point.Z);
}

Math::Point3D Math::Point3D::operator/(const Math::Point3D &point) const
{
    return Math::Point3D(this->X / point.X, this->Y / point.Y, this->Z / point.Z);
}

Math::Point3D Math::Point3D::operator+(const Math::Point3D &point)
{
    return Math::Point3D(this->X + point.X, this->Y + point.Y, this->Z + point.Z);
}

Math::Point3D Math::Point3D::operator-(double value) const
{
    return Math::Point3D(this->X - value, this->Y - value, this->Z - value);
}

Math::Point3D Math::Point3D::operator*(double value) const
{
    return Math::Point3D(this->X * value, this->Y * value, this->Z * value);
}

Math::Point3D::~Point3D()
{
}
