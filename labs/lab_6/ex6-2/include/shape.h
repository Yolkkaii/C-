#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include "location.h"
//task 2
//Definition of Shape class
class Shape{
private:
    Location shapeLocation;

public:
    Shape(int locX, int locY);
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual std::string getInfo() const = 0;
    Location& getLocation();
    Location getLocation() const;
};

#endif // SHAPE_H