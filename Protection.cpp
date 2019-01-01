//
// Created by user on 22/12/2017.
//

#include "Protection.h"
using namespace std;

Protection::Protection(const Protection &p) {
    level = p.level;

}

void Protection::toString(ostream& out)const {
    out<<"level: " + to_string(level);
}


Protection::Protection() {
    level =1.0;
}
/*
bool Soldier::operator==(const Soldier &other) {
    return id==other.id;
}
 */

ostream& operator<<(ostream& out, const Protection& s)
{
    //out<<"level: " + to_string(s.level);
    s.toString(out) ;
    return out;
}
Protection::~Protection(){

}

Point2d* Protection::getP()  {
    return &p;
}

double Protection::getLevel() const {
    return level;
}

void Protection::setP(const Point2d &p) {
    Protection::p = p;
}
