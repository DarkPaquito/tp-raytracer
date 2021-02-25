#include "type.hh"

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

Point3 Point3::operator-(const Point3 &point) const
{
    return Point3(x - point.x, y - point.y, z - point.z);
}

float Point3::dot(const Point3 &point) const
{
    return x * point.x + y * point.y + z * point.z;
}

Vector3 Vector3::operator*(const float &l) const
{
    return Vector3(u * l, v * l, w * l);
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

std::ostream& operator<<(std::ostream &out, const Vector3 &vect)
{
    out << "Vect:\n";
    out << "  U: " << vect.u << "\n";
    out << "  V: " << vect.v << "\n";
    out << "  W: " << vect.w << "\n\n";

    return out;
}
