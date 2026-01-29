#ifndef SPHERE_H
#define SPHERE_H
#include "circle.h"
//task 5
//Definition of Sphere class
class Sphere : public Circle {
public:
    Sphere(double radius, int locX, int locY);
    double getVolume();
    double getArea();
    std::string getInfo();
};

#endif 