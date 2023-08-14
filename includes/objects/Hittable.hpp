/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Hittable
*/

#ifndef HITTABLE_HPP_
    #define HITTABLE_HPP_

    #include "Raytracer.hpp"
    #include "AMaterial.hpp"
    #include "IPrimitive.hpp"

namespace RayTracer
{
    class Hittable : virtual public IPrimitive {
        public:
            AMaterial _material;

            Hittable(const AMaterial &material);

            virtual double hits(const Ray &ray) const = 0;
            virtual Math::Vector3D normal(const Math::Point3D &point) const = 0;

            ~Hittable();
    };
}

#endif /* !HITTABLE_HPP_ */
