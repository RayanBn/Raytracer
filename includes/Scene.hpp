/*
** EPITECH PROJECT, 2023
** rayanTracer
** File description:
** Scene
*/

#ifndef SCENE_HPP_
    #define SCENE_HPP_

    #include "Hittable.hpp"
    #include <memory>

namespace RayTracer
{
    class Scene : public Hittable {
        std::vector<std::shared_ptr<Hittable>> objects;
        int image_width = 256;
        int image_height = 256;
        int samples_per_pixel = 5;

        public:
            Scene();

            Scene AddObject(std::shared_ptr<Hittable> object);
            std::vector<std::shared_ptr<Hittable>> getObjects() const;

            virtual double hits(const Ray &ray) const override;
            virtual Math::Vector3D normal(const Math::Point3D &point) const override;

            ~Scene();
    };
};

#endif /* !SCENE_HPP_ */
