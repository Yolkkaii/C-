#include "location.h"
//task 6
// Implementation of Location class

Location::Location() : x(0), y(0) {}
Location::Location(int locX, int locY) : x(locX), y(locY) {}

void Location::setLocation(int locX, int locY) {
    x = locX;
    y = locY;
}

std::string Location::getLocationString() {
    return std::to_string(x) + ", " + std::to_string(y);
}
