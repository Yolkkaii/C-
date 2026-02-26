/*
ID:
Name: 
Lab No: 10
Question No: 2
Date: 26 Feb 2026
*/
#include <iostream>
#include <string>
#include "circle.h"
#include "sphere.h"
#include "rectangle.h"
#include "shape.h"
#include "location.h"
#include <memory>
using namespace std;

void printShapeInfo(const Shape& shape) {
    cout << shape.getInfo() << endl;
}

int main() {
    //task 7: define a unique_ptr for each shape type (Circle, Sphere, Rectangle),
    //initialize them with appropriate values, and call printShapeInfo() for each shape
    //Note: you should use make_unique to create the unique_ptr instances
    //the unique_ptr should be of type Shape, 
    //but should point to the appropriate derived class object (Circle, Sphere, Rectangle)
    // the location of each shape should be set to different values, 
    //and should be soecified in both the constructor and 
    //by using the getLocation() function to set the location after construction
    auto rect = make_unique<Rectangle>(8.0, 9.0, 11, 13);
    printShapeInfo(*rect);
    
    auto circle = make_unique<Circle>(7.0, 6, 7);
    circle->getLocation().setLocation(2, 3);
    printShapeInfo(*circle);

    auto sphere = make_unique<Sphere>(7.0, 5, 7);
    printShapeInfo(*sphere);
        
    return 0;
}
