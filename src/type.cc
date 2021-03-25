#include <math.h>

#include "type.hh"

color color::operator+(const color &col) const
{
    unsigned char new_r = r + col.r;
    unsigned char new_g = g + col.g;
    unsigned char new_b = b + col.b;

    if (r + col.r > 255)
        new_r = 255;
    if (g + col.g > 255)
        new_g = 255;
    if (b + col.b > 255)
        new_b = 255;

    return color(new_r, new_g, new_b);
}

color color::operator*(const float &l) const
{
    unsigned char new_r = r * l;
    unsigned char new_g = g * l;
    unsigned char new_b = b * l;

    if (r * l > 255)
        new_r = 255;
    if (g * l > 255)
        new_g = 255;
    if (b * l > 255)
        new_b = 255;

    return color(new_r, new_g, new_b);
}

std::ostream& operator<<(std::ostream &out, const color &color)
{
    out << "Pixel RGB:\n";
    out << "  R: " << (int) color.r << "\n";
    out << "  G: " << (int) color.g << "\n";
    out << "  B: " << (int) color.b << "\n\n";

    return out;
}

std::ostream& operator<<(std::ostream &out, const Point3 &point)
{
    out << "Point:\n";
    out << "  X: " << point.x << "\n";
    out << "  Y: " << point.y << "\n";
    out << "  Z: " << point.z << "\n\n";

    return out;
}

Point3 Point3::operator*(const float &l) const
{
    return Point3(x * l, y * l, z * l);
}

Point3 Point3::operator/(const float &l) const
{
    return Point3(x / l, y / l, z / l);
}

Point3 Point3::operator+(const Point3 &point) const
{
    return Point3(x + point.x, y + point.y, z + point.z);
}

float Point3::dist(const Point3 &point) const
{
    return (*this - point).norm();
}

Vector3 Point3::operator-(const Point3 &point) const
{
    return Vector3(x - point.x, y - point.y, z - point.z);
}

Point3 Point3::operator+(const Vector3 &vect) const
{
    return Point3(x + vect.u, y + vect.v, z + vect.w);
}

Point3 Point3::operator-(const Vector3 &vect) const
{
    return Point3(x - vect.u, y - vect.v, z - vect.w);
}

Vector3 Point3::vect() const
{
    return Vector3(x, y, z);
}

Vector3 Vector3::normalize() const
{
    return *this / this->norm();
}

float Vector3::norm() const
{
    return std::sqrt(u * u + v * v + w * w);
}

Vector3 Vector3::operator*(const float &l) const
{
    return Vector3(u * l, v * l, w * l);
}

Vector3 Vector3::operator/(const float &l) const
{
    return Vector3(u / l, v / l, w / l);
}

Vector3 Vector3::operator+(const Vector3 &vect) const
{
    return Vector3(u + vect.u, v + vect.v, w + vect.w);
}

Vector3 Vector3::operator-(const Vector3 &vect) const
{
    return Vector3(u - vect.u, v - vect.v, w - vect.w);
}

float Vector3::dot(const Point3 &point) const
{
    return u * point.x + v * point.y + w * point.z;
}

float Vector3::dot(const Vector3 &vect) const
{
    return u * vect.u + v * vect.v + w * vect.w;
}

Vector3 Vector3::operator*(Vector3 &vect) const
{
    return Vector3(v * vect.w - w * vect.v,
            w * vect.u - u * vect.w,
            u * vect.v - v * vect.u);
}

std::ostream& operator<<(std::ostream &out, const Vector3 &vect)
{
    out << "Vect:\n";
    out << "  U: " << vect.u << "\n";
    out << "  V: " << vect.v << "\n";
    out << "  W: " << vect.w << "\n\n";

    return out;
}
