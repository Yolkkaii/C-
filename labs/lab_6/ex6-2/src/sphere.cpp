#include "sphere.h"
#include <iostream>
//task 10
// Implementation of Sphere class
Sphere::Sphere(double radius, int locX, int locY) 
    : Circle(radius, locX, locY) {}

double Sphere::getVolume() const{
    return (4.0 * PI * (radius * radius * radius)) / 3.0;
}

double Sphere::getArea() const{
    return 4.0 * PI * (radius * radius);
}

std::string Sphere::getInfo() const {
    return "Sphere with radius " + std::to_string(radius) + ", area " + std::to_string(getArea()) + ", volume " + std::to_string(getVolume()) + shapeLocation.getLocationString() + "\n";
}