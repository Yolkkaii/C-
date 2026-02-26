#include "location.h"
using namespace std;
// task 1: implement the member functions of Location class
Location::Location() : x(0), y(0) {}

Location::Location(int locX, int locY) : x(locX), y(locY) {}

void Location::setLocation(int locX, int locY) {
    x = locX;
    y = locY;
}

std::string Location::getLocationString() const {
    std::string locStr = "(" + std::to_string(x) + "," + std::to_string(y) +")";
    return locStr;
}

void Location::setX(int locX) {
    x = locX;
}

void Location::setY(int locY) {
    y = locY;
}

int Location::getX() const {
    return x;
}

int Location::getY() const {
    return y;
}
