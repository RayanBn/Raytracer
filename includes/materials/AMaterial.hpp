/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** IMaterial
*/

#ifndef IMATERIAL_HPP_
    #define IMATERIAL_HPP_

    #include "Color.hpp"
    #include "Raytracer.hpp"
    #include <vector>

namespace RayTracer {
    class AMaterial {

        public:
            color _color;

            AMaterial(const color &coloro);
            AMaterial &operator=(const AMaterial &material) = default;
            ~AMaterial();
    };
}

#endif /* !IMATERIAL_HPP_ */
