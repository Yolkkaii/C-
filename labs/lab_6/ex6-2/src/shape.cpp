#include "shape.h"
#include "location.h"
//task 7
// Implementation of Shape class
Shape::Shape(int locX, int locY) : shapeLocation(locX, locY) {}

Location& Shape::getLocation(){
    return shapeLocation;    
}

Location Shape::getLocation() const{
    return shapeLocation;
}

void Shape::setLocation(int x, int y) {
    shapeLocation.setLocation(x, y);
}