/*
** EPITECH PROJECT, 2023
** rayan
** File description:
** Light
*/

#include "Light.hpp"

RayTracer::Light::Light() :
    _ambiantIntensity(0),
    _diffuseIntensity(0)
{
}

RayTracer::Light::Light(double ambiantIntensity, double diffuseIntensity) :
    _ambiantIntensity(ambiantIntensity),
    _diffuseIntensity(diffuseIntensity)
{
}

RayTracer::Light::~Light()
{
}
