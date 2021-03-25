#pragma once

#include <memory>

#include "object.hh"
#include "camera.hh"
#include "light.hh"
#include "image.hh"

class Scene
{
    public:
        Scene(Camera camera, std::vector<std::shared_ptr<Object>> objects,
                std::vector<std::shared_ptr<Light>> lights)
            : camera_(camera), objects_(objects), lights_(lights)
        { }

        color cast_ray(Ray ray, unsigned n) const;
        Image render_scene(unsigned pix_x, unsigned pix_y) const;

    private:
        Camera camera_;
        std::vector<std::shared_ptr<Object>> objects_;
        std::vector<std::shared_ptr<Light>> lights_;
};
