#pragma once

#include <optional>

#include "type.hh"
#include "texture.hh"

struct Ray
{
    Point3 origin;
    Vector3 u;

    Ray() = default;
    Ray(Point3 origin, Vector3 u) : origin(origin), u(u) { }
};

class Object
{
    public:
        virtual std::optional<Point3> cross_ray(Ray ray) const = 0;
        virtual Vector3 get_normal(Point3 hit) const = 0;
        virtual texture get_tex(Point3 point) const = 0;
};

class Sphere : public Object
{
    public:
        Sphere(Point3 origin, float radius, Uniform_Texture tex)
            : origin_(origin), radius_(radius), tex_(tex)
        { }

        std::optional<Point3> cross_ray(Ray ray) const;
        Vector3 get_normal(Point3 hit) const;
        texture get_tex(Point3 point) const;

    private:
        Point3 origin_;
        float radius_;

        Uniform_Texture tex_;
};

class Plane : public Object
{
    public:
        Plane(Point3 origin, Vector3 n, Uniform_Texture tex)
            : origin_(origin), n_(n), tex_(tex)
        { }

        std::optional<Point3> cross_ray(Ray ray) const;
        Vector3 get_normal(Point3 hit) const;
        texture get_tex(Point3 point) const;

    private:
        Point3 origin_;
        Vector3 n_;

        Uniform_Texture tex_;
};

class Triangle : public Object
{
    public:
        Triangle(Point3 p1, Point3 p2, Point3 p3, Uniform_Texture tex)
            : p1_(p1), p2_(p2), p3_(p3), tex_(tex)
        { }

        std::optional<Point3> cross_ray(Ray ray) const;
        Vector3 get_normal(Point3 hit) const;
        texture get_tex(Point3 point) const;

    private:
        Point3 p1_;
        Point3 p2_;
        Point3 p3_;

        Uniform_Texture tex_;
};
