#include "Vec3i.hpp"

bool Vec3i::operator==(const Vec3i& coordinate_)
{
    return (x == coordinate_.x && y == coordinate_.y && z == coordinate_.z);
}

Vec3i Vec3i::operator+(const Vec3i& coordinate_)
{
    return {x + coordinate_.x, y + coordinate_.y, z + coordinate_.z};
}

void Vec3i::operator+=(const Vec3i& coordinate_)
{
    x += coordinate_.x;
    y += coordinate_.y;
    z += coordinate_.z;
}

Vec3i Vec3i::operator-(const Vec3i& coordinate_)
{
    return {x - coordinate_.x, y - coordinate_.y, z - coordinate_.z};
}

void Vec3i::operator-=(const Vec3i& coordinate_)
{
    x -= coordinate_.x;
    y -= coordinate_.y;
    z -= coordinate_.z;
}