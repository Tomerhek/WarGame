//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_OBSTACLE_H
#define WARGAME_OBSTACLE_H


#include "Point2d.h"

class Obstacle
{
protected:
    Point2d p1,p2;
    double orech;
    double rohav;
    virtual void toString(std:: ostream& out)const;



public:
    Obstacle (Point2d p1,double orech,double rohav) : p1(p1),orech(orech),rohav(rohav),p2((p1.getX()+rohav),(p1.getY()+orech)){};
    Obstacle(const Obstacle &t);

    Obstacle();


    //bool operator==(const Soldier& other) ;
    friend std:: ostream& operator<<(std:: ostream& out, const Obstacle& s);
    virtual ~Obstacle();

    Point2d* getP1();

    const Point2d &getP2() const;

    double getOrech() const;

    double getRohav() const;
};


#endif //WARGAME_OBSTACLE_H
