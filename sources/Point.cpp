#include "Point.hpp"
#include <cmath>
using namespace ariel;
using namespace std;

Point::Point(double x, double y): x(x), y(y) {}

double Point::distance(const Point& other) {
    return sqrt(pow(other.x - this->x, 2) + pow(other.y - this->y, 2) * 1.0);
}

string Point::print() {
    string str = "(" + to_string(this->x) + "," + to_string(this->y) + ")";
    return str;
}

Point Point::moveTowards(const Point& src, const Point& dest, double distance) {
    cout << "move toward" << endl;
    return Point(0,0);
}

