#include <cmath>

#include "type.hh"
#include "image.hh"
#include "texture.hh"
#include "object.hh"
#include "camera.hh"
#include "light.hh"
#include "scene.hh"

Scene create_scene1()
{
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<Light>> lights;

    auto light = std::make_shared<Point_Light>(Point3(-10, -10, 10), 0.8);
    lights.push_back(light);

    auto wall = std::make_shared<Plane>(Point3(0, 0, 50), Vector3(0, 0, -1),
            Uniform_Texture(color(0, 50, 150), 1, 0.4, 0.8));
    objects.push_back(wall);

    auto ball = std::make_shared<Sphere>(Point3(0, 0, 30), 10.,
            Uniform_Texture(color(180, 100, 0), 0.8, 0.5, 0.5));
    objects.push_back(ball);

    auto camera = Camera(Point3(0, 0, 0), Point3(0, 0, 1), Vector3(0, 2, 0),
            M_PI_4, M_PI_4, 40);
    return Scene(camera, objects, lights);
}

Scene create_scene2()
{
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<Light>> lights;

    auto light = std::make_shared<Point_Light>(Point3(0, 80, 15), 0.7);
    // auto light2 = std::make_shared<Point_Light>(Point3(10, 20, 10), 0.7);
    lights.push_back(light);
    // lights.push_back(light2);

    auto ground = std::make_shared<Plane>(Point3(0, -10, 0), Vector3(0, 1, 0),
            Uniform_Texture(color((char) 0, (char) 200, (char) 80), 1, 0.4, 0.8));
    objects.push_back(ground);

    auto wall = std::make_shared<Plane>(Point3(0, 0, 500), Vector3(0, 0, -1),
            Uniform_Texture(color((char) 150, (char) 150, (char) 150), 1, 0.1, 0.8));
    objects.push_back(wall);

    auto ball_1 = std::make_shared<Sphere>(Point3(-10, 20, 80), 30.,
            Uniform_Texture(color((char) 250, (char) 250, (char) 250), 1, 1, 1.4));
    objects.push_back(ball_1);

    auto ball_2 = std::make_shared<Sphere>(Point3(5, -5, 30), 5.,
            Uniform_Texture(color((char) 250, (char) 80, (char) 0), 0.8, 0.3, 0.5));
    objects.push_back(ball_2);

    auto camera = Camera(Point3(0, 0, 0), Point3(0, 0, 1), Vector3(0, 2, 0),
            M_PI_4, M_PI_4, 5);

     return Scene(camera, objects, lights);
}

Scene create_scene3()
{
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<Light>> lights;

    auto light = std::make_shared<Point_Light>(Point3(0, 20, 0), 0.7);
    lights.push_back(light);

    auto ground = std::make_shared<Plane>(Point3(0, -5, 0), Vector3(0, -1, 0),
            Uniform_Texture(color((char) 0, (char) 150, (char) 50), 0.8, 1, 0.2));
    objects.push_back(ground);

    auto wall = std::make_shared<Plane>(Point3(0, 0, 70), Vector3(0, 1, 1),
            Uniform_Texture(color((char) 50, (char) 50, (char) 50), 1, 0.4, 1));
    objects.push_back(wall);

    auto ball_1 = std::make_shared<Sphere>(Point3(-5, 5, 20), 10.,
            Uniform_Texture(color((char) 150, (char) 0, (char) 0), 0.8, 0.5, 0.5));
    objects.push_back(ball_1);

    auto ball_2 = std::make_shared<Sphere>(Point3(10, -2, 12), 3.,
            Uniform_Texture(color((char) 0, (char) 0, (char) 150), 0.8, 0.5, 0.5));
    objects.push_back(ball_2);

    auto camera = Camera(Point3(0, 0, 0), Point3(0, 0, 1), Vector3(0, 1, 0),
            M_PI_4, M_PI_4, 10);

     return Scene(camera, objects, lights);
}

Scene create_scene4()
{
    std::vector<std::shared_ptr<Object>> objects;
    std::vector<std::shared_ptr<Light>> lights;

    auto light = std::make_shared<Point_Light>(Point3(0, 20, 0), 0.7);
    lights.push_back(light);

    auto ground = std::make_shared<Plane>(Point3(0, -10, 0), Vector3(0, 1, 0),
            Uniform_Texture(color((char) 0, (char) 200, (char) 80), 1, 0.4, 0.8));
    objects.push_back(ground);

    auto wall = std::make_shared<Plane>(Point3(0, 0, 500), Vector3(0, 0, -1),
            Uniform_Texture(color((char) 150, (char) 150, (char) 150), 1, 0.1, 0.8));
    objects.push_back(wall);

    auto triangle = std::make_shared<Triangle>(Point3(0, 0, 10),
            Point3(-5, 5, 10), Point3(5, 5, 10),
            Uniform_Texture(color((char) 0, (char) 0, (char) 150), 0.8, 0.5, 0.5));
    objects.push_back(triangle);

    auto camera = Camera(Point3(0, 0, 0), Point3(0, 0, 1), Vector3(0, 1, 0),
            M_PI_4, M_PI_4, 10);

     return Scene(camera, objects, lights);
}

int main()
{
    Scene scene = create_scene4();

    auto image = scene.render_scene(1080, 1080);
    std::cout << "Width: " << image.width << "\n";
    std::cout << "Height: " << image.height << "\n";

    auto data = image.pixels;
    std::cout << "Random Pixel: " << data[10][10];

    image.save_image("../image_test/test.ppm");
}
