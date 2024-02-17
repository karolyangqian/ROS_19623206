#include "commander.hpp"

commander::commander(/* args */)
{
}

commander::~commander()
{
}

void commander::setStatus(std::string status) {this->status = status;}

void commander::land()
{
    while (this->pose.z > 0 && this->pose.z != 0)
    {
        this->transform({0, 0, -1});
        this->setStatus("landing");
    }
    this->setStatus("land");
}