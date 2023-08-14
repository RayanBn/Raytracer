/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** main
*/

#include "Raytracer.hpp"
#include "Vector3D.hpp"
#include "Sphere.hpp"
#include "Camera.hpp"
#include "Color.hpp"
#include "Mate.hpp"
#include "Standard.hpp"
#include "Parser.hpp"
#include "DirectionnalLight.hpp"
#include <fstream>
#include <limits>
#include <vector>

typedef struct hit_record {
    Math::Point3D intersectionPoint;
    std::shared_ptr<RayTracer::Hittable> obj;
    Math::Vector3D normal;
    double solution;
} hit_record;

hit_record get_closest_object(const RayTracer::Ray &ray, std::vector<std::shared_ptr<RayTracer::Hittable>> &objects)
{
    hit_record record;
    double min_lambda = -1;
    record.solution = std::numeric_limits<double>::max();
    record.obj = nullptr;
    record.intersectionPoint = Math::Point3D();
    record.normal = Math::Vector3D();

    for (auto &obj : objects) {
        min_lambda = obj->hits(ray);
        if (min_lambda > 0 && min_lambda < record.solution) {
            record.solution = min_lambda;
            record.obj = obj;
            record.intersectionPoint = ray.at(min_lambda);
            record.normal = obj->normal(record.intersectionPoint);
        }
    }
    return record;
}

color ray_color(const RayTracer::Ray &ray, std::vector<std::shared_ptr<RayTracer::Hittable>> &objects, RayTracer::Light &light, RayTracer::DirectionnalLight &directionnal_light)
{
    hit_record record = get_closest_object(ray, objects);
    color pixelColor;
    color shadeAttenuation = color(1, 1, 1);

    if (record.obj == nullptr)
        return color(0, 0, 0);
    pixelColor =  record.obj->_material._color * light._ambiantIntensity * light._diffuseIntensity;
    float lightAngle = record.normal.dot(directionnal_light._direction * -1);
    if (lightAngle > 0) {
        RayTracer::Ray shadowRay(record.normal * 0.000001 + record.intersectionPoint, directionnal_light._direction * -1);
        for (auto &obj : objects) {
            if (obj->hits(shadowRay) > 0) {
                shadeAttenuation = color(0, 0, 0);
                break;
            }
        }
        pixelColor = pixelColor +  record.obj->_material._color * lightAngle * light._ambiantIntensity * shadeAttenuation * light._diffuseIntensity;
    }
    return pixelColor;
}

int main(int ac, char **av)
{
    if (ac != 2 || std::ifstream(av[1]).good() == false)
        return 84;
    RayTracer::Scene scene;
    RayTracer::Parser parser(av[1], scene);
    RayTracer::Camera camera = parser.getCamera();
    const int image_width = parser.getResolution().first;
    const int image_height = parser.getResolution().second;
    RayTracer::Light light = parser.getAmbiantLight();
    RayTracer::DirectionnalLight directionnal_light = parser.getDirectionnalLight();
    color red = Math::Vector3D(0, 1, 0);
    RayTracer::Ray ray(Math::Point3D(0, 0, 0), Math::Vector3D(0, 0, 1));
    std::vector<std::shared_ptr<RayTracer::Hittable>> objects = parser.getPrimitive();
    color pixel_color;
    int samples_per_pixel = 10;

   std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            pixel_color = color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s) {
                double u = (i + Math::random_double()) / (image_width-1);
                double v = (j + Math::random_double()) / (image_height-1);
                ray = camera.getRay(u, v);
                pixel_color = pixel_color + ray_color(ray, objects, light, directionnal_light);
            }
            pixel_color = pixel_color / samples_per_pixel;
            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
}
