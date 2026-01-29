/*
ID: 68011278
Name: Ananda Stallard
Lab No: 6
Question No: 1
Date: 29 Jan 2026
*/
#include <iostream>
#include <string>
#include "circle.h"
#include "sphere.h"
#include "rectangle.h"
#include "shape.h"
using namespace std;


void printShapeInfo(const Shape& shape) {
    //task 11
    // Print the information of the shape using polymorphism
    cout << shape.getInfo() << "\n";
}

int main() {
    //task 12
    // Create instances of Circle using Shape pointer,
    // the circle located at (2,3) with radius 7.0
    Shape* circlePtr = new Circle(7.0, 2, 3);

    //task 13
    // Create instances of Sphere using Shape pointers
    // the sphere located at (0,0) with radius 7.0
    // then set its location to (5,7)
    Sphere* spherePtr = new Sphere(7.0, 0, 0);
    spherePtr->setLocation(5, 7);

    //task 14
    // Create instances of Rectangle using Shape pointers
    // the rectangle located at (0,0) with width 8.0 and height 9.0
    // then set its location to (11,13)
    Shape* rectPtr = new Rectangle(8.0, 9.0, 0, 0);
    rectPtr->setLocation(11, 13);

    //task 15
    // Print information of all shapes using printShapeInfo function
    printShapeInfo(*rectPtr);
    printShapeInfo(*circlePtr);
    printShapeInfo(*spherePtr);

    //task 16
    // Clean up all dynamically allocated memory
    delete circlePtr;
    delete spherePtr;
    delete rectPtr;
    
    return 0;
}
