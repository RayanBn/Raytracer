/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Ray
*/

#include "Raytracer.hpp"

RayTracer::Ray::Ray() :
    origin(Math::Point3D()),
    direction(Math::Vector3D())
{
}

RayTracer::Ray::Ray(const Math::Point3D &origin, const Math::Vector3D &direction) :
    origin(origin),
    direction(direction.normalize())
{
}

Math::Point3D RayTracer::Ray::at(double distance) const
{
    return Math::Point3D(direction * distance + origin);
}

RayTracer::Ray::~Ray()
{
}
