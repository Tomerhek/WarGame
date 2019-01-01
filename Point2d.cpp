//
// Created by user on 22/12/2017.
//
#include <cmath>
#include "Point2d.h"
using namespace std;
Point2d::Point2d(const Point2d &p) {
    x = p.x;
    y = p.y;
}
void Point2d::toString(ostream& out)const {
    out<<"x: " + to_string(x) + " y: " +to_string(y) ;
}

Point2d::Point2d() {
    x=0.0;
    y=0.0;

}

bool Point2d::operator==(const Point2d &other) {
    return x==other.x && y==other.y;
}


ostream& operator<<(ostream& out, const Point2d& p)
{
    p.toString(out) ;
    return out;
}
Point2d::~Point2d(){

}

double Point2d::Distance(Point2d p2)
{
    return sqrt(pow(x - p2.x, 2) + pow(y - p2.y, 2));
}

double Point2d::getX() const {
    return x;
}

double Point2d::getY() const {
    return y;
}

void Point2d::setX(double x) {
    Point2d::x = x;
}

void Point2d::setY(double y) {
    Point2d::y = y;
}
double Point2d:: Ratio (Point2d p2)
{
    return ((Point2d::getY()-p2.getY())/(Point2d::getX()-p2.getX()));

}
