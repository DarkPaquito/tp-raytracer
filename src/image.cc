#include "image.hh"

Image::Image(unsigned height, unsigned width)
{
    this->height = height;
    this->width = width;

    pixels.assign(height, std::vector<color>(width));
}

Image::Image(std::string filename)
{
    std::ifstream file = std::ifstream(filename, std::ios::binary);

    if (!file.is_open())
    {
        std::cout << "Could not access '" << filename << "'\n";
        return;
    }

    std::string file_type;
    file >> file_type;

    if (file_type != "P6")
    {
        std::cout << "'" << filename << "' has wrong file type\n";
        return;
    }

    file >> width;
    file >> height;

    unsigned char max;
    file >> max;

    pixels = std::vector<std::vector<color>>();
    pixels.assign(height, std::vector<color>(width));

    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            char r;
            char g;
            char b;

            file.read(&r, 1);
            file.read(&g, 1);
            file.read(&b, 1);

            pixels[i][j] = color(r, g, b);
        }
    }

    file.clear();
    file.close();
}

void Image::save_image(std::string filename)
{
    std::ofstream file = std::ofstream(filename, std::ios::binary);

    if (!file.is_open())
    {
        std::cout << "Could not access '" << filename << "'\n";
        return;
    }

    file << "P6\n";
    file << width << " ";
    file << height << "\n";
    file << "255\n";

    for (size_t i = 0; i < height; ++i)
    {
        for (size_t j = 0; j < width; ++j)
        {
            char r = pixels[i][j].r;
            char g = pixels[i][j].g;
            char b = pixels[i][j].b;

            file.write(&r, 1);
            file.write(&g, 1);
            file.write(&b, 1);
        }
    }

    file.clear();
    file.close();
}
