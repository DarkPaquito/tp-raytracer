#pragma once

#include "type.hh"
#include "image.hh"

class Camera
{
    public:
        Point3 center;
        Point3 p;
        Vector3 up;

        float alpha;
        float beta;
        float z_min;

        Camera(Point3 center, Point3 p, Vector3 up, float alpha,
                float beta, float z_min)
            : center(center), p(p), up(up), alpha(alpha),
            beta(beta), z_min(z_min)
        { }

        float image_plane_len(bool x_y) const;
        std::vector<std::vector<Vector3>> get_rays(unsigned pix_x,
                unsigned pix_y) const;
};
