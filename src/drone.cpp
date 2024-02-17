#include <iostream>
#include "drone.hpp"
#include "Vec3i.hpp"

drone::drone()
{
    this->pose = {0, 0, 0};
    this->status = "land";
}

drone::~drone()
{   
}

Vec3i drone::getPose() const {return this->pose;}
std::string drone::getStatus() const {return this->status;}

void drone::transform(Vec3i displacement) 
{
    this->pose += displacement;
    this->updateStatus();
}

void drone::updateStatus()
{
    if (this->pose.z == 0)
    {
        this->status = "land";
    }
    if (0 < this->pose.z < 10)
    {
        this->status = "takeoff";
    }
    if (this->pose.z == 10)
    {
        this->status = "fly";
    }
    // std::cout << this->pose.x << " " << this->pose.y << " " << this->pose.z << " " << this->status << std::endl;
}