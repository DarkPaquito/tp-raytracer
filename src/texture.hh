#pragma once

#include "type.hh"

struct texture
{
    color col;

    texture(color col) : col(col) { }
};

class Texture_Material
{
    public:
        virtual texture get_texture(Point3 point) = 0; 
};

class Uniform_Texture : public Texture_Material
{
    public:
        Uniform_Texture(color col) : _tex(texture(col)) { }

        texture get_texture(Point3 point);

    private:
        texture _tex;
};
