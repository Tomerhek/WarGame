//
// Created by user on 22/12/2017.
//

#include "Weapon.h"
using namespace std;

Weapon::Weapon(const Weapon &w) {
     p= w.p;
    damage = w.damage;
    shotsPerTurn = w.shotsPerTurn;
    type=w.type;
}


Weapon::Weapon() {
    Point2d p(0.0,0.0);
    damage=0.0;
    shotsPerTurn = 0;
    type=0;
}
/*
bool Soldier::operator==(const Soldier &other) {
    return id==other.id;
}
 */

void Weapon::toString(std:: ostream& out)const
{
    out<<p<<" damage: "<<damage<<" type: "<<type;
}

ostream& operator<<(ostream& out, const Weapon* s)
{
    //out<<s->p<<" damage: "<<s->damage<<" type: "<<s->type;
    s->toString(out) ;
    return out;
}
Weapon::~Weapon(){

}

double Weapon::getDamage() const {
    return damage;
}

Point2d* Weapon::getP()  {
    return &p;
}

int Weapon::getType() const {
    return type;
}

int Weapon::getShotsPerTurn() const {
    return shotsPerTurn;
}
