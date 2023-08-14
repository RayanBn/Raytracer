/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Plane
*/

#include "Plane.hpp"

RayTracer::Plane::Plane(const std::string &axe, const double &value, const AMaterial &material) :
    Hittable(material)
{
    if (axe == "X") {
        _normal = Math::Vector3D(1, 0, 0);
        _point = Math::Point3D(value, 0, 0);
    }
    if (axe == "Y") {
        _normal = Math::Vector3D(0, 1, 0);
        _point = Math::Point3D(0, value, 0);
    }
    if (axe == "Z") {
        _normal = Math::Vector3D(0, 0, 1);
        _point = Math::Point3D(0, 0, value);
    }
}

double RayTracer::Plane::hits(const RayTracer::Ray &ray) const
{
    double discr = this->_normal.dot(ray.direction);

    if (std::abs(discr) < 0.000001)
        return -1.0;
    Math::Vector3D ipoint = this->_point - ray.origin;
    double res = this->_normal.dot(ipoint) / discr;
    return res;
}

Math::Vector3D RayTracer::Plane::normal(const Math::Point3D &point) const
{
    static_cast<void>(point);

    return this->_normal;
}

RayTracer::Plane::~Plane()
{
}
