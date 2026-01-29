#include "rectangle.h"
#include <iostream>
//task 9
// Implementation of Rectangle class
Rectangle::Rectangle(double width, double height, int locX, int locY)
    : Shape(locX, locY), width(width), height(height) {};

double Rectangle::getArea() const {
    return width * height;
}

std::string Rectangle::getInfo() const {
    return "Rectangle with width " + std::to_string(width) + ", height " + std::to_string(height) + ", area " + std::to_string(getArea()) + shapeLocation.getLocationString() + "\n";
}
