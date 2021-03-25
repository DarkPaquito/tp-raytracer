#include <math.h>

#include "object.hh"

std::optional<Point3> Sphere::cross_ray(Ray ray) const
{
    Vector3 tmp = ray.origin - origin_;

    float a = ray.u.dot(ray.u);
    float b = 2 * ray.u.dot(tmp);
    float c = tmp.dot(tmp) - radius_ * radius_;

    float d = b * b - (4 * a * c);

    if (d < 0)
        return std::nullopt;

    float t0 = (-b - std::sqrt(d)) / (2 * a);
    float t1 = (-b + std::sqrt(d)) / (2 * a);
    float t = (t0 >= 0 && t0 < t1) ? t0 : t1;

    if (t < 0)
        return std::nullopt;

    Point3 hit = ray.origin + ray.u * t;

    return std::optional<Point3>(hit);
}

Vector3 Sphere::get_normal(Point3 hit) const
{
    return (hit - origin_).normalize();
}

texture Sphere::get_tex(Point3 point) const
{
    return tex_.get_texture(point);
}

std::optional<Point3> Plane::cross_ray(Ray ray) const
{
    float a = n_.dot(ray.u);

    if (a == 0)
        return std::nullopt;

    float d = origin_.vect().dot(n_);
    float t = (d - n_.dot(ray.origin.vect())) / a;

    if (t < 0)
        return std::nullopt;

    Point3 hit = ray.origin + ray.u * t;
    return std::optional<Point3>(hit);
}

Vector3 Plane::get_normal(Point3 hit) const
{
    return n_.normalize();
}

texture Plane::get_tex(Point3 point) const
{
    return tex_.get_texture(point);
}

std::optional<Point3> Triangle::cross_ray(Ray ray) const
{
    Vector3 normal = get_normal(Point3(0, 0, 0));

    float n_ray = normal.dot(ray.u);
    if (std::fabs(n_ray) < 0.0001)
        return std::nullopt;

    float d = normal.dot(p1_);
    float t = (normal.dot(ray.origin) + d) / n_ray;

    if (t < 0)
        return std::nullopt;

    Point3 hit = ray.origin + ray.u * t;

    Vector3 edge1 = p2_ - p1_;
    Vector3 v_hit1 = hit - p1_;
    if (normal.dot(edge1 * v_hit1) < 0)
        return std::nullopt;

    Vector3 edge2 = p3_ - p2_;
    Vector3 v_hit2 = hit - p2_;
    if (normal.dot(edge2 * v_hit2) < 0)
        return std::nullopt;

    Vector3 edge3 = p1_ - p3_;
    Vector3 v_hit3 = hit - p3_;
    if (normal.dot(edge3 * v_hit3) < 0)
        return std::nullopt;

    return std::optional<Point3>(hit);
}

Vector3 Triangle::get_normal(Point3 hit) const
{
    Vector3 vec1 = p2_ - p1_;
    Vector3 vec2 = p3_ - p1_;

    return (vec1 * vec2).normalize();
}

texture Triangle::get_tex(Point3 point) const
{
    return tex_.get_texture(point);
}
