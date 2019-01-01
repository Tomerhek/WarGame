//
// Created by user on 22/12/2017.
//

#include "Obstacle.h"
using namespace std;

Obstacle::Obstacle(const Obstacle &t) {
    p1 = t.p1;
    orech=t.orech;
    rohav= t.rohav;

}
void Obstacle::toString(ostream& out)const {
    out<<"p1: " <<p1 <<" orech: "+to_string(orech)+" rohav: "+to_string(rohav);
}

Obstacle::Obstacle() {
    Point2d p1 (0.0,0.0);
    orech=2.0;
    rohav=2.0;
}
/*
bool Soldier::operator==(const Soldier &other) {
    return id==other.id;
}
 */

ostream& operator<<(ostream& out, const Obstacle& s)
{
    s.toString(out) ;
    return out;
}
Obstacle::~Obstacle(){

}

Point2d* Obstacle::getP1()  {
    return &p1;
}

const Point2d &Obstacle::getP2() const {
    return p2;
}

double Obstacle::getOrech() const {
    return orech;
}

double Obstacle::getRohav() const {
    return rohav;
}
