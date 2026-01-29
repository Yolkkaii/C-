#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
const double PI {3.14159};
//task 3
//Definition of Circle class
class Circle : public Shape {
protected:
    double radius;
public:
    Circle(double radius, int locX, int locY);
    double getArea() const;
    std::string getInfo() const override;
};

#endif