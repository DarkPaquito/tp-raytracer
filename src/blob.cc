#include "bloc.hh"

texture Triangle::get_tex(Point3 point) const
{
    return tex_.get_texture(point);
}
