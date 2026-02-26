#include "rectangle.h"
#include "location.h"
#include <iostream>
using namespace std;
//task 5: implement the member functions of Rectangle class,
//including the constructor, setWidth(), setHeight(), getWidth(), getHeight(), 
//getArea(), and getInfo() functions
//Note: getInfo() should return a string containing the width, height, area,
//and location of the rectangle
//see the lab instructions for the format of the info string
Rectangle::Rectangle(double aWidth, double aHeight, int locX, int locY) : Shape(locX, locY), width(aWidth), height(aHeight) {};

void Rectangle::setWidth(double aWidth) {
    width = aWidth;
}

void Rectangle::setHeight(double aHeight) {
    height = aHeight;
}
double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

double Rectangle::getArea() const {
    return width * height;
}

std::string Rectangle::getInfo() const {
    return "Rectangle with width " + std::to_string(width) + ", height " + std::to_string(height) + ", area " + std::to_string(getArea()) + ", located at " + getLocation().getLocationString();

}
