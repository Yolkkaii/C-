#include <iostream>
#include "circle.h"
//task 8
// Implementation of Circle class

Circle::Circle(double radius, int locX, int locY) 
    : Shape(locX, locY), radius(radius) {};

double Circle::getArea() const {
    return PI * (radius * radius);
}

std::string Circle::getInfo() const {
    return "Circle with radius " + std::to_string(radius) + ", area " + std::to_string(getArea()) + shapeLocation.getLocationString() + "\n";
}