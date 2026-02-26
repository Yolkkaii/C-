#ifndef SPHERE_H
#define SPHERE_H
#include "circle.h"
class Sphere : public Circle {
        
    public:
        Sphere(double aRadius =0, int locX =0, int locY =0); 
        double getArea() const override;
        double getVolume() const;
        std::string getInfo() const override;
};
#endif