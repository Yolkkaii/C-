#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
class Rectangle : public Shape {
    private:
        double width;
        double height;
    public:
        Rectangle(double aWidth =0, double aHeight =0, int locX =0, int locY =0);
        void setWidth(double aWidth);
        void setHeight(double aHeight);
        double getWidth() const;
        double getHeight() const;
        double getArea() const override;
        std::string getInfo() const override;
};
#endif // RECTANGLE_H