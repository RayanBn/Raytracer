/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Vector3D
*/

#ifndef  VECTOR3D_HPP_
    #define VECTOR3D_HPP_

    #include <cmath>

namespace Math {

    class Point3D;

    inline static double random_double()
    {
        return rand() / (RAND_MAX + 1.0);
    }

    class Vector3D {
        public:
            double X;
            double Y;
            double Z;

            Vector3D();
            Vector3D(double x, double y, double z);
            Vector3D(const Vector3D &other) = default;
            Vector3D(Vector3D &&other) = default;
            Vector3D(const Point3D &point);
            Vector3D &operator=(const Vector3D &other);
            Vector3D &operator=(Vector3D &&other) = default;

            double length(void) const;
            double dot(const Vector3D &other) const;
            Vector3D normalize(void) const;
            Vector3D random(void) const;
            Vector3D random(double min, double max) const;
            Vector3D &operator+=(Vector3D &other);
            Vector3D &operator-=(Vector3D &other);
            Vector3D &operator*=(const Vector3D &other);
            Vector3D &operator/=(const Vector3D &other);
            Vector3D &operator*=(double value);
            Vector3D &operator/=(double value);

            Vector3D operator+(const Vector3D &other) const;
            Vector3D operator-(const Vector3D &other) const;
            Vector3D operator*(const Vector3D &other) const;
            Vector3D operator/(const Vector3D &other) const;
            Vector3D operator*(double value) const;
            Vector3D operator/(double value) const;
            Vector3D operator-(double value) const;
            Vector3D operator+(double value) const;

            Vector3D operator-(const Point3D &other) const;

            ~Vector3D();
    };
}

#endif /* !VECTOR3D_HPP_ */
