#ifndef LOCATION_H
#define LOCATION_H
#include <string>

class Location {
    private:
        int x;
        int y;
    public:
        Location(); 
        Location(int locX, int locY); 
        void setLocation(int locX, int locY); 
        std::string getLocationString() const; 
        void setX(int locX);
        void setY(int locY);
        int getX() const;
        int getY() const;

};
#endif