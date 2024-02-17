#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include "Vec3i.hpp"

class drone
{
protected:
    Vec3i pose;
    std::string status;

public:
    // Constructor
    drone();

    // Destructor
    ~drone();

    // Getter methods
    Vec3i getPose() const;
    std::string getStatus() const;

    // Methods
    void transform(Vec3i displacement);
    void updateStatus();
};

#endif