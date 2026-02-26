#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"

const double PI {3.14159};

class Circle: public Shape {
    private:
        
    protected:    
        double radius;
    public:
        Circle(double aRadius =0, int locX =0, int locY =0); 
        virtual ~Circle() = default;
        void setRadius(double aRadius); 
        double getRadius() const;
        virtual double getArea() const override;
        virtual std::string getInfo() const override;        
};
#endif