/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** raytracer
*/

#ifndef RAYTRACER_HPP_
    #define RAYTRACER_HPP_

    #define SUCCESS 0
    #define FAILURE 84
    #define HELP "USAGE: ./raytracer <SCENE_FILE>\n\
    SCENE_FILE: scene configuration\n"

    #include <iostream>
    #include "Point3D.hpp"
    #include "Vector3D.hpp"

namespace RayTracer
{
    class Ray {
        public:
            Math::Point3D origin;
            Math::Vector3D direction;

            Ray();
            Ray(const Math::Point3D &origin, const Math::Vector3D &direction);
            Ray(const Ray &other) = default;
            Ray(Ray &&other) = default;
            Ray &operator=(const Ray &other) = default;
            Ray &operator=(Ray &&other) = default;

            Math::Point3D at(double distance) const;

            ~Ray();
    };
};

#endif /* !RAYTRACER_HPP_ */
