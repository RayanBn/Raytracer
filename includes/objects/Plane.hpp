/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Plane
*/

#ifndef PLANE_HPP_
    #define PLANE_HPP_

    #include "Point3D.hpp"
    #include "Raytracer.hpp"
    #include "Hittable.hpp"

namespace RayTracer {
    // class Mate;

    class Plane : public Hittable {
        public:
            Math::Point3D _point;
            Math::Vector3D _normal;

            Plane(const std::string &axe, const double &value, const AMaterial &material);

            virtual double hits(const RayTracer::Ray &ray) const override;
            virtual Math::Vector3D normal(const Math::Point3D &point) const override;

            ~Plane();
    };
}

#endif /* !PLANE_HPP_ */
