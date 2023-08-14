/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include "AMaterial.hpp"

RayTracer::Sphere::Sphere() :
    Hittable(RayTracer::AMaterial(color(0, 0, 0))),
    center(Math::Point3D()),
    radius(0)
{
}

RayTracer::Sphere::Sphere(const Math::Point3D &center, const double &radius, const RayTracer::AMaterial &material) :
    Hittable(material),
    center(center),
    radius(radius)
{
}

double RayTracer::Sphere::hits(const RayTracer::Ray &ray) const
{
    Math::Vector3D dist = Math::Vector3D(ray.origin.X - this->center.X, ray.origin.Y - this->center.Y, ray.origin.Z - this->center.Z);
    double a = ray.direction.dot(ray.direction);
    double b = 2.0 * ray.direction.dot(dist);
    double c = dist.dot(dist) - std::pow(this->radius, 2);
    double delta = b * b - 4 * a * c;

    if (delta < 0)
        return -1.0;
    return (-b - std::sqrt(delta)) / (2.0 * a);
}

Math::Vector3D RayTracer::Sphere::normal(const Math::Point3D &point) const
{
    Math::Vector3D normal(point - center);

    return normal;
}

RayTracer::Sphere::~Sphere()
{
}
