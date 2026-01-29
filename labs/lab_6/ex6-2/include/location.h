
#ifndef LOCATION_H
#define LOCATION_H
#include <string>
//task 1
//Definition of Location class
class Location {
private:
    int x;
    int y;

public:
    Location();
    Location(int locX, int locY);
    void setLocation(int locX, int locY);
    std::string getLocationString();
};

#endif