#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

namespace ariel{
    class Point{
        double x_axis;
        double y_axis;

        public:
            Point(int x):x_axis(0.0),y_axis(0.0){}
            Point(double x_axis, double y_axis):x_axis(x_axis),y_axis(y_axis){}
            double distance(const Point &other);
            void print();
            double getX() const {return x_axis;}
            double getY() const {return y_axis;}

            bool operator==(const Point& other) const;

            static Point moveTowards(Point &source, Point &destination, double distance);
    };
};
#endif