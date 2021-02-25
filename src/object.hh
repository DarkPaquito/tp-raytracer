#pragma once

#include <optional>

#include "type.hh"
#include "texture.hh"

struct ray
{
    Point3 origin;
    Vector3 u;

    ray(Point3 origin, Vector3 u) : origin(origin), u(u) { }
};

class Object
{
    public:
        virtual std::optional<float> cross_ray(ray ray) = 0;
        virtual float get_normal(Point3 hit) = 0;
        virtual texture get_tex(Point3 point) = 0;
};

class Sphere : public Object
{
    public:
        Sphere(Point3 origin, float radius, Uniform_Texture tex)
            : _origin(origin), _radius(radius), _tex(tex)
        { }

        std::optional<float> cross_ray(ray ray);
        float get_normal(Point3 hit);
        texture get_tex(Point3 point);

    private:
        Uniform_Texture _tex;

        Point3 _origin;
        float _radius;
};
