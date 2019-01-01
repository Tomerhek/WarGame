//
// Created by user on 22/12/2017.
//

#include <iostream>
#include "M16.h"
using namespace std;

M16::M16( M16 &m) {
    p = m.p;
    damage = m.damage;
    type= m.type;

}
void M16::print() {
    cout<<p<<" damage: "+to_string(damage)+" type: "+to_string(type)<<endl;
}
ostream& operator<<(ostream& out, const M16& s)
{
    s.toString(out) ;
    return out;
}

//void M16::toString(ostream& out)const {
//    out<<"";
//} it might be it might not.....