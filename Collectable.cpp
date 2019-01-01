//
// Created by Shahar on 26/12/2017.
//

#include "Collectable.h"
using namespace std;

Collectable::Collectable(const Collectable &p) {
    p1 = p.p1;

}
void Collectable::toString(ostream& out)const {
    out<<"Collectable: " << p1;
}

Collectable::Collectable() {

}
/*
bool Soldier::operator==(const Soldier &other) {
    return id==other.id;
}
 */

ostream& operator<<(ostream& out, const Collectable& s)
{
    s.toString(out) ;
    return out;
}
Collectable::~Collectable(){

}
