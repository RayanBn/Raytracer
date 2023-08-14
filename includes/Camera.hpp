/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include "Point3D.hpp"
    #include "Raytracer.hpp"

namespace RayTracer
{
    class Camera {
        Math::Point3D _position;
        Math::Point3D _rotation;
        Math::Vector3D _direction;
        std::pair<int, int> _resolution;
        std::size_t _fov;
        Math::Vector3D _screenOrigin;
        Math::Vector3D _screenBottomLeft;
        Math::Vector3D _screenTopRight;

        Math::Point3D getScreenPointAt(double u, double v) const;

        public:
            Camera();
            Camera(const Math::Point3D &position, const Math::Point3D &rotation, const Math::Vector3D &direction, const std::pair<int, int> &resolution, const std::size_t &fov);
            RayTracer::Ray getRay(double x, double y);
            ~Camera();
    };
};

#endif /* !CAMERA_HPP_ */
