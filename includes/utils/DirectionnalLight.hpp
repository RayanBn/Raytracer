/*
** EPITECH PROJECT, 2023
** rayan
** File description:
** DirectionnalLight
*/

#ifndef DIRECTIONNALLIGHT_HPP_
    #define DIRECTIONNALLIGHT_HPP_

    #include "Light.hpp"

namespace RayTracer {
    class DirectionnalLight : public Light {
        public:
            Math::Vector3D _direction;

            DirectionnalLight();
            DirectionnalLight(const Math::Vector3D &direction);
            ~DirectionnalLight();

        protected:
        private:
    };
}

#endif /* !DIRECTIONNALLIGHT_HPP_ */
