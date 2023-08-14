/*
** EPITECH PROJECT, 2023
** rayantracer
** File description:
** parser
*/

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Mate.hpp"
#include "Parser.hpp"
#include "AMaterial.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cone.hpp"
#include "Factory.hpp"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

RayTracer::Parser::Parser(const std::string &path, Scene &scene)
{
    this->_config.readFile(path.c_str());
    this->_scene = scene;
}

RayTracer::Camera RayTracer::Parser::getCamera()
{
    try {
        libconfig::Setting &position = this->_config.lookup("camera.position");
        libconfig::Setting &rotation = this->_config.lookup("camera.rotation");
        libconfig::Setting &direction = this->_config.lookup("camera.direction");
        libconfig::Setting &resolution = this->_config.lookup("camera.resolution");
        libconfig::Setting &fieldOfView = this->_config.lookup("camera.fov");
        Math::Point3D pos(std::atof(position["x"]), std::atof(position["y"]), std::atof(position["z"]));
        Math::Point3D rot(std::atof(rotation["x"]), std::atof(rotation["y"]), std::atof(rotation["z"]));
        Math::Vector3D dir(std::atof(direction["x"]), std::atof(direction["y"]), std::atof(direction["z"]));
        std::pair<int, int> res(std::atof(resolution["x"]), std::atof(resolution["y"]));
        std::size_t fov = std::atof(fieldOfView);
        return RayTracer::Camera(pos, rot, dir, res, fov);
    } catch (const libconfig::SettingNotFoundException &e) {
        return RayTracer::Camera();
    }
}

std::vector<std::shared_ptr<RayTracer::Hittable>> RayTracer::Parser::getPrimitive()
{
    try {
        std::vector<RayTracer::Hittable *> primitveVector;
        libconfig::Setting &primitives = this->_config.lookup("primitives");

        for (int i = 0; i < primitives.getLength(); i++) {
            libconfig::Setting &primitive = primitives[i];
            std::string type = primitive.lookup("type");

            std::unordered_map<std::string, std::function<std::shared_ptr<Hittable>(libconfig::Setting &material)>> createFunctions = {
                {"sphere", Factory::createSphere},
                {"plane", Factory::createPlane},
                {"cone", Factory::createCone},
            };

            auto createFunction = createFunctions.find(type);
            if (createFunction != createFunctions.end()) {
                std::shared_ptr<Hittable> primitiveObj = createFunction->second(primitive);
                this->_scene = this->_scene.AddObject(primitiveObj);
            }
        }
        return this->_scene.getObjects();
    } catch (const libconfig::SettingNotFoundException &e) {
        return std::vector<std::shared_ptr<RayTracer::Hittable>>();
    }
}

std::pair<int, int> RayTracer::Parser::getResolution()
{
    try {
        libconfig::Setting &resolution = this->_config.lookup("camera.resolution");
        std::pair<int, int> res(std::atof(resolution["x"]), std::atof(resolution["y"]));
        return res;
    } catch (const libconfig::SettingNotFoundException &e) {
        return std::pair<int, int>(500, 500);
    }
}

RayTracer::Light RayTracer::Parser::getAmbiantLight()
{
    try {
        libconfig::Setting &light = this->_config.lookup("lights");

        double ambiantIntensity = std::atof(light["ambiantIntensity"]);
        double diffuseIntensity = std::atof(light["diffuseIntensity"]);
        return RayTracer::Light(ambiantIntensity, diffuseIntensity);
    } catch (const libconfig::SettingNotFoundException &e) {
        return RayTracer::Light();
    }
}

RayTracer::DirectionnalLight RayTracer::Parser::getDirectionnalLight()
{
    try {
        libconfig::Setting &direction = this->_config.lookup("lights.direction");

        double x = std::atof(direction["x"]);
        double y = std::atof(direction["y"]);
        double z = std::atof(direction["z"]);
        Math::Vector3D dir(x, y, z);
        return RayTracer::DirectionnalLight(dir);
    } catch (const libconfig::SettingNotFoundException &e) {
        return RayTracer::DirectionnalLight();
    }
}

RayTracer::Parser::~Parser()
{
}
