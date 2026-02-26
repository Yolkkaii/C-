#include "sphere.h"
#include "location.h"
#include <iostream>
using namespace std;
//task 6: implement the member functions of Sphere class, including the constructor, 
//getArea(), getVolume(), and getInfo() functions
//Note: getInfo() should return a string containing the radius, area, volume,
//and location of the sphere
//see the lab instructions for the format of the info string
Sphere::Sphere(double aRadius, int locX, int locY) : Circle(aRadius, locX, locY) {}; 

double Sphere::getArea() const {
    return 4.0 * PI * (radius * radius);
}

double Sphere::getVolume() const {
    return (4.0 / 3.0) * PI * (radius * radius * radius);
}

std::string Sphere::getInfo() const {
    return "Sphere with radius " + std::to_string(radius) + ", area " + std::to_string(getArea()) + ", volume " + std::to_string(getVolume()) + ", located at " + getLocation().getLocationString();
}
