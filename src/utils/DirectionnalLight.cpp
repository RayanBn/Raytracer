/*
** EPITECH PROJECT, 2023
** rayan
** File description:
** DirectionnalLight
*/

#include "DirectionnalLight.hpp"

RayTracer::DirectionnalLight::DirectionnalLight() :
    Light(),
    _direction(Math::Vector3D(0, 0, 0))
{
}

RayTracer::DirectionnalLight::DirectionnalLight(const Math::Vector3D &direction) :
    Light(),
    _direction(direction)
{
}

RayTracer::DirectionnalLight::~DirectionnalLight()
{
}
