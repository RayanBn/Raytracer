/*
** EPITECH PROJECT, 2023
** rayan
** File description:
** Light
*/

#ifndef Light_HPP_
    #define Light_HPP_

    #include "Vector3D.hpp"

namespace RayTracer {
    class Light {

        public:
            double _ambiantIntensity;
            double _diffuseIntensity;

            Light();
            Light(double ambiantIntensity, double diffuseIntensity);

            ~Light();
    };
}

#endif /* !Light_HPP_ */
