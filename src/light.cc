#include "light.hh"

Point3 Point_Light::get_origin() const
{
    return origin_;
}

float Point_Light::get_intensity() const
{
    return i_;
}
