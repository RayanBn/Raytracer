/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Cone
*/

#include "Cone.hpp"
#include "AMaterial.hpp"

RayTracer::Cone::Cone() :
    Hittable(RayTracer::AMaterial(color(0, 0, 0))),
    center(Math::Point3D()),
    radius(0),
    height(0),
    direction(Math::Vector3D())
{
}

RayTracer::Cone::Cone(const Math::Point3D &center, const double &radius, const double &height, const Math::Vector3D &direction, const RayTracer::AMaterial &material) :
    Hittable(material),
    center(center),
    radius(radius),
    height(height),
    direction(direction)
{
}

double RayTracer::Cone::hits(const RayTracer::Ray &ray) const
{
    Math::Vector3D dist = ray.origin - this->center;
    double a = ray.direction.dot(this->direction) * ray.direction.dot(this->direction) - this->radius * this->radius;
    double b = 2.0 * (ray.direction.dot(this->direction) * dist.dot(this->direction) - this->radius * this->radius * dist.dot(ray.direction));
    double c = dist.dot(this->direction) * dist.dot(this->direction) - this->radius * this->radius * dist.dot(dist);
    double delta = b * b - 4 * a * c;

    if (delta < 0)
        return -1.0;
    Math::Vector3D cp = ray.origin + ray.direction * (-b - std::sqrt(delta)) / (2.0 * a) - this->center;
    double h = cp.dot(this->direction);
    if (h < 0 || h > this->height)
        return -1.0;
    return (-b - std::sqrt(delta)) / (2.0 * a);
}

Math::Vector3D RayTracer::Cone::normal(const Math::Point3D &point) const
{
    Math::Vector3D normal = point * this->direction.dot(point) / (point * point) - this->direction;
    return normal.normalize();
}

RayTracer::Cone::~Cone()
{
}
