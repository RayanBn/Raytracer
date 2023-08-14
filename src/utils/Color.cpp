/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Color
*/

#include "Color.hpp"

double clamp(double x, double min, double max)
{
    if (x < min)
        return min;
    if (x > max)
        return max;
    return x;
}

void write_color(std::ostream &out, Math::Vector3D color)
{
    out << static_cast<int>(255.999 * clamp(color.X, 0.0, 0.999)) << ' '
        << static_cast<int>(255.999 * clamp(color.Y, 0.0, 0.999)) << ' '
        << static_cast<int>(255.999 * clamp(color.Z, 0.0, 0.999)) << '\n';
}
