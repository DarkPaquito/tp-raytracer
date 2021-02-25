#include "object.hh"

std::optional<float> Sphere::cross_ray(ray ray)
{
    Point3 q = ray.origin - _origin;

    float a = ray.u.dot(ray.u);
    float b = 2 * ray.u.dot(q);
    float c = q.dot(q) - _radius * _radius;

    float d = b * b - 4 * a * c;

    return d >= 0;
}

float Sphere::get_normal(Point3 hit)
{
    return 0.0f;
}

texture Sphere::get_tex(Point3 point)
{
    return _tex.get_texture(point);
}
