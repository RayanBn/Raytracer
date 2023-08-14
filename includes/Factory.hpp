/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
    #define FACTORY_HPP_

    #include <libconfig.h++>
    #include <memory>
    #include "Hittable.hpp"

namespace RayTracer
{
    class Factory {
        public:
            Factory();

            static std::shared_ptr<RayTracer::Hittable> createSphere(libconfig::Setting &primitive);
            static std::shared_ptr<RayTracer::Hittable> createPlane(libconfig::Setting &primitive);
            static std::shared_ptr<RayTracer::Hittable> createCone(libconfig::Setting &primitive);

            ~Factory();
    };
}

#endif /* !FACTORY_HPP_ */
