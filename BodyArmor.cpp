//
// Created by user on 22/12/2017.
//

#include "BodyArmor.h"
using namespace std;

BodyArmor::BodyArmor(const BodyArmor &b) {
    level = b.level;

}
void BodyArmor::toString(ostream& out)const {
    out<<"level: " + to_string(level);
}

BodyArmor::BodyArmor() {
    level =1.0;
}
/*
bool Soldier::operator==(const Soldier &other) {
    return id==other.id;
}
 */

ostream& operator<<(ostream& out, const BodyArmor& s)
{
    s.toString(out) ;
    return out;
}
BodyArmor::~BodyArmor(){

}