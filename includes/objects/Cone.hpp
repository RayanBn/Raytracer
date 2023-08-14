/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Cone
*/

#ifndef CONE_HPP_
    #define CONE_HPP_

    #include "Point3D.hpp"
    #include "Raytracer.hpp"
    #include "Hittable.hpp"

namespace RayTracer {
    class Cone : public Hittable {
        public:
            Math::Point3D center;
            double radius;
            double height;
            Math::Vector3D direction;

            Cone();
            Cone(const Math::Point3D &center, const double &radius, const double &height, const Math::Vector3D &direction, const AMaterial &material);

            virtual double hits(const RayTracer::Ray &ray) const override;
            virtual Math::Vector3D normal(const Math::Point3D &point) const override;

            ~Cone();
    };
}

#endif /* !PLANE_HPP_ */
