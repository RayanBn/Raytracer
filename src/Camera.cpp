/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Camera
*/

#include "Camera.hpp"

RayTracer::Camera::Camera() : _position(Math::Point3D()),
                              _rotation(Math::Point3D()),
                              _direction(Math::Vector3D(1, 1, 1)),
                              _resolution(std::make_pair(250, 250)),
                              _fov(70)
{
}

RayTracer::Camera::Camera(const Math::Point3D &position, const Math::Point3D &rotation, const Math::Vector3D &direction, const std::pair<int, int> &resolution, const std::size_t &fov) :
    _position(position),
    _rotation(rotation),
    _direction(direction),
    _resolution(resolution),
    _fov(fov)
{
    double fovRatio = tan(this->_fov / 2 * M_PI / 180);
    double aspectRatio = static_cast<double>(this->_resolution.first) / static_cast<double>(this->_resolution.second);
    double screenDistance = 1 / (2 * fovRatio);
    Math::Vector3D screenOrigin(this->_position.X, this->_position.Y, this->_position.Z + screenDistance);
    Math::Vector3D bottomLeft(-aspectRatio, -1, screenOrigin.Z);
    Math::Vector3D topRight(aspectRatio, 1, screenOrigin.Z);

    this->_screenBottomLeft = bottomLeft;
    this->_screenTopRight = topRight;
    this->_screenOrigin = screenOrigin;
}

Math::Point3D RayTracer::Camera::getScreenPointAt(double u, double v) const
{
    Math::Vector3D point;

    point.X = (1 - (u * 2) + this->_position.X) * static_cast<double>(this->_resolution.first) / static_cast<double>(this->_resolution.second);
    point.Y = 1 - (v * 2) + this->_position.Y;
    point.Z = this->_screenOrigin.Z + this->_position.Z;
    return point;
}

RayTracer::Ray RayTracer::Camera::getRay(double x, double y)
{
    Math::Point3D point = getScreenPointAt(x, y);

    Math::Vector3D direction = this->_position - point;
    direction = direction.normalize();
    return RayTracer::Ray(this->_position, direction);
}

RayTracer::Camera::~Camera()
{
}
