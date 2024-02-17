#ifndef COMMANDER_H
#define COMMANDER_H

#include <iostream>
#include "drone.hpp"

class commander: public drone
{
public:
    commander();
    ~commander();

    void setStatus(std::string status);
    void land();
};

#endif