//
// Created by user on 22/12/2017.
//

#include "Tree.h"
using namespace std;

Tree::Tree(const Tree &t) {
    p1 = t.p1;
    orech=t.orech;
    rohav= t.rohav;

}
void Tree::toString(ostream& out)const {
    out<<"p1: " <<p1 <<" orech: "+to_string(orech)+" rohav: "+to_string(rohav);
}

Tree::Tree() {
    Point2d p1 (0.0,0.0);
    orech=2.0;
    rohav=2.0;
}
/*
bool Soldier::operator==(const Soldier &other) {
    return id==other.id;
}
 */

ostream& operator<<(ostream& out, const Tree& s)
{
    s.toString(out) ;
    return out;
}
Tree::~Tree(){

}