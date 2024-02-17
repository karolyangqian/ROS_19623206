#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <iostream>
#include "drone.hpp"
#include "Vec3i.hpp"

class navigator : public drone
{
private:
    Vec3i lowerBound, upperBound;

public:
    navigator();
    ~navigator();

    void transform(Vec3i displacement);
    void setBounds(Vec3i lowerBound, Vec3i upperBound);
};

#endif
