#pragma once

#include "type.hh"

class Light
{
    public:
        virtual Point3 get_origin() const = 0;
        virtual float get_intensity() const = 0;
};

class Point_Light : public Light
{
    public:
        Point_Light(Point3 origin, float i) : origin_(origin), i_(i) { }

        Point3 get_origin() const;
        float get_intensity() const;

    private:
        Point3 origin_;
        float i_;
};
