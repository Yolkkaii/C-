#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
//task 4
//Definition of Rectangle class
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double width, double height, int locX, int locY);
    double getArea() const;
    std::string getInfo() const override;
};

#endif // RECTANGLE_H