/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Scene
*/

#include "Scene.hpp"

RayTracer::Scene::Scene() :
    Hittable(RayTracer::AMaterial(color(0, 0, 0)))
{
}

RayTracer::Scene RayTracer::Scene::AddObject(std::shared_ptr<Hittable> object)
{
    this->objects.push_back(object);
    return (*this);
}

std::vector<std::shared_ptr<RayTracer::Hittable>> RayTracer::Scene::getObjects() const
{
    return (this->objects);
}

double RayTracer::Scene::hits(const Ray &ray) const
{
    return 0.0;
}

Math::Vector3D RayTracer::Scene::normal(const Math::Point3D &point) const
{
    return Math::Vector3D();
}

RayTracer::Scene::~Scene()
{
}
