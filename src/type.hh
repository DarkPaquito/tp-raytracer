#pragma once

#include <iostream>
#include <fstream>

// Color struct represents a RGB color
struct color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;

    color(unsigned char r, unsigned char g, unsigned char b) 
        : r(r), g(g), b(b) 
    { }

    color() = default;

    color operator+(const color &col) const;
    color operator*(const float &l) const;
};

class Vector3;

// Point3 class represents a 3D euclidean point
class Point3
{
    public:
        float x;
        float y;
        float z;

        Point3() = default;
        Point3(float x, float y, float z) : x(x), y(y), z(z) { }

        Vector3 vect() const;
        float dist(const Point3 &point) const;
        Point3 operator*(const float &l) const;
        Point3 operator/(const float &l) const;
        Point3 operator+(const Point3 &point) const;
        Vector3 operator-(const Point3 &point) const;
        Point3 operator+(const Vector3 &vect) const;
        Point3 operator-(const Vector3 &vect) const;
};

// Vector3 class contains euclidean representation of a 3D vector
// Represented as three coordinates
class Vector3
{
    public:
        float u;
        float v;
        float w;

        Vector3() = default;
        Vector3(float u, float v, float w) : u(u), v(v), w(w) { }

        Vector3 normalize() const;
        float norm() const;
        Vector3 operator*(const float &l) const;
        Vector3 operator/(const float &l) const;
        Vector3 operator+(const Vector3 &vect) const;
        Vector3 operator-(const Vector3 &vect) const;
        float dot(const Point3 &point) const;
        float dot(const Vector3 &vect) const;
        Vector3 operator*(Vector3 &vect) const;
};

std::ostream& operator<<(std::ostream &out, const color &color);
std::ostream& operator<<(std::ostream &out, const Point3 &point);
std::ostream& operator<<(std::ostream &out, const Vector3 &vect);
