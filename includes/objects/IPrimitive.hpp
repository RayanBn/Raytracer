/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** IMaterial
*/

#ifndef IPRIMITIVE_HPP_
    #define IPRIMITIVE_HPP_

#include "Vector3D.hpp"

namespace RayTracer {
    class IPrimitive {
        public:
            virtual double hits(const Ray &ray) const = 0;
            virtual Math::Vector3D normal(const Math::Point3D &point) const = 0;
    };
}

#endif /* !IPRIMITIVE_HPP_ */
