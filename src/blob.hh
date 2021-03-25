#pragma once

class Blob
{
    public:
        Blob(Point3 origin, float threshold, Uniform_Texture tex)
            : origin_(origin), threshold_(threshold), tex_(tex)
        { }

        texture get_tex(Point3 point) const;

    private:
        Point3 origin_;
        float threshold_;

        Uniform_Texture tex_;
};
