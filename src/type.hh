#pragma once

#include <iostream>
#include <fstream>

// Color struct represents a RGB color
struct color
{
    char r;
    char g;
    char b;
};

// Point3 class represents a 3D euclidean point
class Point3
{
    public:
        float x;
        float y;
        float z;

        Point3(float x, float y, float z) : x(x), y(y), z(z) { }
};

// Vector3 class contains euclidean representation of a 3D vector
// Represented as three coordinates
class Vector3
{
    public:
        float u;
        float v;
        float w;

        Vector3(float u, float v, float w) : u(u), v(v), w(w) { }

        Vector3 operator*(const float &l) const;
        Vector3 operator+(const Vector3 &vect) const;
        Vector3 operator-(const Vector3 &vect) const;
};

std::ostream& operator<<(std::ostream &out, const color &color);
std::ostream& operator<<(std::ostream &out, const Point3 &point);
std::ostream& operator<<(std::ostream &out, const Vector3 &vect);
