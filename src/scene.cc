#include <math.h>

#include "scene.hh"

color Scene::cast_ray(Ray ray, unsigned n) const
{
    float min_dist = std::numeric_limits<float>::max();
    std::optional<std::shared_ptr<Object>> min_obj;
    std::optional<Point3> min_point;

    for (auto obj : objects_)
    {
        auto hit = obj->cross_ray(ray);

        if (hit)
        {
            float dist = hit->dist(ray.origin);

            if (dist < min_dist && dist > 0.001)
            {
                min_dist = dist;
                min_obj = std::optional<std::shared_ptr<Object>>(obj);
                min_point = hit;
            }
        }
    }

    if (min_point)
    {
        Point3 hit = min_point.value();
        texture tex = min_obj.value()->get_tex(hit);

        float dot = 0;
        float pow = 0;
        float light_dist = 0;

        bool shadow = false;

        color blank(255, 255, 255);

        Ray light_ray;

        Vector3 normal = min_obj.value()->get_normal(hit);
        Vector3 in = ray.u.normalize();
        Vector3 reflected = in - normal * 2 * (normal.dot(in));

        color intens = color(0, 0, 0);
        color id(0, 0, 0);
        color is(0, 0, 0);

        for (auto &light : lights_)
        {
            light_ray = Ray(hit, (light->get_origin() - hit).normalize());
            /* light_dist = hit.dist(light->get_origin());

            for (auto obj : objects_)
            {
                auto light_hit = obj->cross_ray(light_ray);

                if (light_hit)
                {
                    float dist = light_hit->dist(light_ray.origin);

                    if (dist < light_dist && dist > 0.001)
                    {
                        shadow = true;
                        break;
                    }
                }
            }

            if (shadow)
                continue;*/

            dot = normal.dot(light_ray.u);
            dot = dot < 0 ? 0 : dot;

            id = tex.col * tex.kd * dot * light->get_intensity();

            dot = reflected.dot(light_ray.u);
            dot = dot < 0 ? 0 : dot;

            pow = std::pow(dot, tex.ns);

            is = blank * tex.ks * pow * light->get_intensity();

            intens = intens + id + is;
        }

        if (n > 0 && !shadow)
            intens = intens + cast_ray(Ray(hit, reflected), n - 1) * tex.ks;

        return intens;
    }
    
    return color(0, 0, 0);
}

Image Scene::render_scene(unsigned pix_x, unsigned pix_y) const
{
    auto vec_rays = camera_.get_rays(pix_x, pix_y);
    Image image(pix_x, pix_y);

    for (unsigned i = 0; i < pix_y; ++i)
    {
        for (unsigned j = 0; j < pix_x; ++j)
        {
            image.pixels[i][j] = cast_ray(Ray(camera_.center, vec_rays[i][j]),
                    5);
        }
    }

    return image;
}
