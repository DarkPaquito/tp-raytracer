#include "image.hh"

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
            color pix;

            file.read(&pix.r, 1);
            file.read(&pix.g, 1);
            file.read(&pix.b, 1);

            pixels[i][j] = pix;
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
            file.write(&pixels[i][j].r, 1);
            file.write(&pixels[i][j].g, 1);
            file.write(&pixels[i][j].b, 1);
        }
    }

    file.clear();
    file.close();
}
