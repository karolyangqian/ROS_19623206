#ifndef VEC3I_H
#define VEC3I_H

struct Vec3i
{
    float x, y, z;

    bool operator==(const Vec3i& coordinate_);
    Vec3i operator+(const Vec3i& coordinate_);
    void operator+=(const Vec3i& coordinate_);
    Vec3i operator-(const Vec3i& coordinate_);
    void operator-=(const Vec3i& coordinate_);
};

#endif