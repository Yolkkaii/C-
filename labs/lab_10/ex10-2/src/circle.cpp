#include <iostream>
#include "circle.h" 
#include "shape.h"
#include "location.h"
using namespace std;
//task 4: implement the member functions of Circle class, 
//including the constructor, setRadius(), getRadius(), getArea(), and getInfo() functions
//Note: getInfo() should return a string containing the radius, area, 
//and location of the circle
//see the lab instructions for the format of the info string
Circle::Circle(double aRadius, int locX, int locY) : radius(aRadius), Shape(locX, locY) {};

void Circle::setRadius(double aRadius) {
    radius = aRadius;
}

double Circle::getRadius() const{
    return radius;
}

double Circle::getArea() const {
    return PI * (radius * radius);
}

std::string Circle::getInfo() const {
    return "Circle with radius " + std::to_string(radius) + ", area " + std::to_string(getArea()) + ", located at " + getLocation().getLocationString();
}

