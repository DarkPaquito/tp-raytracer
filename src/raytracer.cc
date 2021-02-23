#include "type.hh"
#include "image.hh"

int main()
{
    Vector3 vect(1.5f, 1.0f, 1.0f);
    std::cout << vect;

    std::cout << (vect - Vector3(1.0f, 1.0f, 1.0f));
    std::cout << (vect * 2.0f);
    
    Image image = Image("image_test/Baboon.512.ppm");
    std::cout << "Width: " << image.width << "\n";
    std::cout << "Height: " << image.height << "\n";

    std::cout << "Random Pixel: " << image.pixels[510][510];

    image.save_image("image_test/save_image.ppm");
}
