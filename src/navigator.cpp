#include "navigator.hpp"
#include "Vec3i.hpp"

navigator::navigator()
{
    this->lowerBound = {0, 0, 0};
    this->upperBound = {1000, 1000, 10};
}

navigator::~navigator()
{
}

void navigator::transform(Vec3i displacement)
{
    Vec3i temp = this->pose;
    temp += displacement;
    if (this->lowerBound.x <= temp.x && temp.x <= this->upperBound.x)
    {
        this->pose.x += displacement.x;
    }
    if (this->lowerBound.y <= temp.y && temp.y <= this->upperBound.y)
    {
        this->pose.y += displacement.y;
    }
    if (this->lowerBound.z <= temp.z && temp.z <= this->upperBound.z)
    {
        this->pose.z += displacement.z;
    }
    this->updateStatus();
}

void navigator::setBounds(Vec3i lowerBound, Vec3i upperBound)
{
    this->lowerBound = lowerBound;
    this->upperBound = upperBound;
}
