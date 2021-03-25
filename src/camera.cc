#include <math.h>

#include "camera.hh"
#include "object.hh"

float Camera::image_plane_len(bool x_y) const
{
    Vector3 vec_dir = (p - center).normalize();
    Plane image_plane = Plane(Point3(0, 0, z_min), (center - p).normalize(),
            Uniform_Texture(color(0, 0, 0), 0, 0, 0));

    Vector3 vec_rot;

    if (x_y)
    {
        vec_rot = Vector3(
                std::cos(alpha) * vec_dir.u + std::sin(alpha) * vec_dir.w,
                vec_dir.v,
                std::cos(alpha) * vec_dir.w - std::sin(alpha) * vec_dir.u);
    }
    else
    {
        vec_rot = Vector3(
                vec_dir.u,
                std::cos(beta) * vec_dir.v - std::sin(beta) * vec_dir.w,
                std::sin(beta) * vec_dir.v + std::cos(beta) * vec_dir.w);
    }

    std::optional<Point3> opt = image_plane.cross_ray(Ray(center, vec_rot));

    if (!opt.has_value()) 
    {
        std::cout << "Coucou\n";
        return 0;
    }

    Point3 hit = opt.value(); 

    return hit.dist(center) * 2;
}

std::vector<std::vector<Vector3>> Camera::get_rays(unsigned pix_x,
        unsigned pix_y) const
{
    float x_size = image_plane_len(true);
    Vector3 pix_size_x(x_size / pix_x, 0, 0);

    float y_size = image_plane_len(false);
    Vector3 pix_size_y(0, -y_size / pix_y, 0);

    Vector3 top_left(center.x - x_size / 2, center.y + y_size / 2, z_min);
    Vector3 pixel = (top_left + (pix_size_x + pix_size_y) / 2) - center.vect();
    std::vector<std::vector<Vector3>> rays(pix_y, std::vector<Vector3>(pix_x));

    for(unsigned i = 0; i < pix_y; ++i)
    {
        for(unsigned j = 0; j < pix_x; ++j)
        {
             rays[i][j] = (pixel + (pix_size_x * j)
                     + (pix_size_y * i)).normalize();
        }
    }

    return rays;
}
