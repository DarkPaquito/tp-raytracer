cmake_minimum_required(VERSION 3.17)
project(raytracing)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 20)

add_executable(raytracing
    src/raytracer.cc
    src/image.cc
    src/type.cc
    src/object.cc
    src/texture.cc
    src/camera.cc
    src/scene.cc
    src/light.cc)
