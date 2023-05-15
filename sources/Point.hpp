#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ariel {

    class Point {
        
        double x;
        double y;

        public:
            Point(double xcor = 0, double ycor = 0);
            double getX();
            double getY();
            double distance(const Point& other);
            string print();
            static Point moveTowards(const Point& source, const Point& dest, double distance);

    };
}