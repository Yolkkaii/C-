#include "shape.h"
#include "location.h"
// task 3: implement the member functions of Shape class, 
// including the constructor and getLocation() functions

Shape::Shape(int locX, int locY) : location(std::make_unique<Location>(locX, locY)) {}

Location& Shape::getLocation() {
    return *location;
}

Location& Shape::getLocation() const {
    return *location;
}
