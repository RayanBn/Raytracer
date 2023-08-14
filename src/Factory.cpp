/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cone.hpp"
#include "Mate.hpp"

RayTracer::Factory::Factory()
{
}

std::shared_ptr<RayTracer::Hittable> RayTracer::Factory::createSphere(libconfig::Setting &primitive)
{
     libconfig::Setting& center = primitive.lookup("center");
    double x = std::atof(center["x"]);
    double y = std::atof(center["y"]);
    double z = std::atof(center["z"]);
    double radius = std::atof(primitive.lookup("radius"));

    libconfig::Setting& material = primitive.lookup("material");
    std::string materialName = material.lookup("name");

    float r = std::atof(material.lookup("r"));
    float g = std::atof(material.lookup("g"));
    float b = std::atof(material.lookup("b"));

    color colo = Math::Vector3D(r, g, b);
    RayTracer::Mate Tmaterial(color(0, 0, 0));
    if (materialName == "matte")
        Tmaterial = RayTracer::Mate(colo);

    return std::make_shared<RayTracer::Sphere>(Math::Point3D(x, y, z), radius, Tmaterial);
}

std::shared_ptr<RayTracer::Hittable> RayTracer::Factory::createPlane(libconfig::Setting &primitive)
{
    int position = std::atoi(primitive.lookup("position"));
    std::string axe = primitive.lookup("axe");
    libconfig::Setting& material = primitive.lookup("material");
    std::string materialName = material.lookup("name");

    float r = std::atof(material.lookup("r"));
    float g = std::atof(material.lookup("g"));
    float b = std::atof(material.lookup("b"));

    color colo = Math::Vector3D(r, g, b);
    RayTracer::Mate Tmaterial(color(0, 0, 0));
    if (materialName == "matte")
        Tmaterial = RayTracer::Mate(colo);

    return std::make_shared<RayTracer::Plane>(axe, position, Tmaterial);
}

std::shared_ptr<RayTracer::Hittable> RayTracer::Factory::createCone(libconfig::Setting &primitive)
{
    static_cast<void>(primitive);

    return std::make_shared<RayTracer::Cone>(Math::Point3D(1, 2, -10), 0.95, 5.0, Math::Vector3D(0, -1, 0), RayTracer::Mate(color(0, 1, 0)));
}

RayTracer::Factory::~Factory()
{
}
