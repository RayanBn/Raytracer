/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
    #define POINT3D_HPP_

namespace Math {

    class Vector3D;

    class Point3D {
        public:
            double X;
            double Y;
            double Z;

            Point3D();
            Point3D(double x, double y, double z);
            Point3D(const Point3D &other) = default;
            Point3D(Point3D &&other) = default;
            Point3D(const Vector3D &vector);
            Point3D &operator=(const Point3D &other) = default;
            Point3D &operator=(Point3D &&other) = default;

            Point3D operator-(const Point3D &point) const;
            Point3D operator+(const Point3D &point);
            Point3D operator*(const Point3D &point) const;
            Point3D operator/(const Point3D &point) const;
            Point3D operator+(const Vector3D &vector) const;
            Point3D operator-(double value) const;
            Point3D operator*(double value) const;

            ~Point3D();
    };
}

#endif /* !POINT3D_HPP_ */
