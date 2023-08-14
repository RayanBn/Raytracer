/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Standard
*/

#include "Standard.hpp"

RayTracer::Standard::Standard(const color &color) :
    AMaterial(color)
{
}

// color RayTracer::Standard::ray_color(const RayTracer::Ray &ray, std::vector<RayTracer::Hittable *> &objects, int depth)
// {
//     double lambda = 0;

//     if (depth <= 0)
//         return color(0,0,0);
//     for (auto &obj: objects) {
//         lambda = obj->hits(ray);
//         if (lambda > 0.0) {
//             Math::Vector3D tmp = obj->normal(ray.at(lambda));
//             tmp = tmp.normalize();
//             return color(tmp.X + 1, tmp.Y + 1, tmp.Z + 1) * 0.5;
//         }
//     }
//     Math::Vector3D unit_direction = ray.direction.normalize();
//     double t = 0.5 * (unit_direction.Y + 1.0);
//     return  color(1.0, 1.0, 1.0) * (1.0 - t) + color(0.5, 0.7, 1.0) * t;
// }

RayTracer::Standard::~Standard()
{
}
