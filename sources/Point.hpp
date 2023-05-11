#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace ariel {

    class Point {
        
        double x;
        double y;

        public:
            Point(double x = 0, double y = 0);
            double distance(const Point& other);
            string print();
            Point moveTowards(const Point& srce, const Point& dest, double distance);

    };
}