#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <memory>
class Location; // Forward declaration of Location class 
class Shape {
    private:
        //task 2: add a proper smart pointer to manage the Location object in Shape class
        std::unique_ptr<Location> location;
public:
    Shape(int locX =0, int locY =0);
    virtual ~Shape() = default; // virtual destructor for proper cleanup of derived classes
    virtual double getArea() const = 0;
    virtual std::string getInfo() const = 0;
    Location& getLocation(); // non-const version, returns by reference, allows modification 
    Location& getLocation() const; // added const version, returns by reference, allows read-only access
};
#endif // SHAPE_H