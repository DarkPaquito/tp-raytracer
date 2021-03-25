#pragma once

#include "type.hh"

struct texture
{
    color col;
    float kd;
    float ks;
    float ns;

    texture(color col, float kd, float ks, float ns)
        : col(col), kd(kd), ks(ks), ns(ns)
    { }
};

class Texture_Material
{
    public:
        virtual texture get_texture(Point3 point) const = 0; 
};

class Uniform_Texture : public Texture_Material
{
    public:
        Uniform_Texture(color col, float kd, float ks, float ns)
            : tex_(texture(col, kd, ks, ns))
        { }

        texture get_texture(Point3 point) const;

    private:
        texture tex_;
};
