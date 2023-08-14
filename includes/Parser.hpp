/*
** EPITECH PROJECT, 2023
** rayantracer
** File description:
** parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

    #include <libconfig.h++>
    #include <memory>
    #include "Camera.hpp"
    #include "Hittable.hpp"
    #include "Light.hpp"
    #include "Scene.hpp"
    #include "DirectionnalLight.hpp"

namespace RayTracer {
    class Parser {
        libconfig::Config _config;
        Scene _scene;

        public:
            Parser(const std::string &path, Scene &scene);

            Camera getCamera();
            std::vector<std::shared_ptr<Hittable>> getPrimitive();
            std::pair<int, int> getResolution();
            Light getAmbiantLight();
            DirectionnalLight getDirectionnalLight();

            ~Parser();
    };
};

#endif /* !PARSER_HPP_ */
