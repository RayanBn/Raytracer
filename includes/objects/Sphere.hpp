/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
    #define SPHERE_HPP_

    #include "Point3D.hpp"
    #include "Raytracer.hpp"
    #include "Hittable.hpp"

namespace RayTracer
{
    class Sphere : public Hittable {

        public:
            Math::Point3D center;
            double radius;

            Sphere();
            Sphere(const Math::Point3D &center, const double &radius, const AMaterial &material);

            virtual double hits(const RayTracer::Ray &ray) const override;
            virtual Math::Vector3D normal(const Math::Point3D &point) const override;

            ~Sphere();
    };
};

#endif /* !SPHERE_HPP_ */
