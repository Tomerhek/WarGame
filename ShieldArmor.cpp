//
// Created by user on 22/12/2017.
//

#include "ShieldArmor.h"
using namespace std;

ShieldArmor::ShieldArmor(const ShieldArmor &b) {
    level = b.level;

}

void ShieldArmor::toString(ostream& out)const {
    out<<"level: " + to_string(level);
}

ShieldArmor::ShieldArmor() {
    level =1.0;
}
/*
bool Soldier::operator==(const Soldier &other) {
    return id==other.id;
}
 */

ostream& operator<<(ostream& out, const ShieldArmor& s)
{
    s.toString(out) ;
    return out;
}
ShieldArmor::~ShieldArmor(){

}