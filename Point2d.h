//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_POINT2D_H
#define WARGAME_POINT2D_H


#include <ostream>

class Point2d
{
protected:
    double x;
    double y;
    virtual void toString(std:: ostream& out)const;



public:
    Point2d (double x,double y) : x(x),y(y){};
    Point2d(const Point2d &p);

    Point2d();


    bool operator==(const Point2d& other) ;
    friend std:: ostream& operator<<(std:: ostream& out, const Point2d& p);
    virtual ~Point2d();
    double Distance (Point2d p2);

    double getX() const;

    double getY() const;

    void setX(double x);

    void setY(double y);
    double Ratio (Point2d p2);

};


#endif //WARGAME_POINT2D_H
