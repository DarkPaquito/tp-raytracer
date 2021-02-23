#pragma once

#include <vector>
#include <string>

#include "type.hh"

// Image class represents an image as a height, a width and a table of pixels
class Image
{
    public:
        unsigned height;
        unsigned width;
        std::vector<std::vector<struct color>> pixels;

        Image(std::string filename);

        void save_image(std::string filename);
};
