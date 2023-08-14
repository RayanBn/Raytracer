/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Hittable
*/

#include "Hittable.hpp"

RayTracer::Hittable::Hittable(const AMaterial &material) :
    _material(material)
{
}

RayTracer::Hittable::~Hittable()
{
}
