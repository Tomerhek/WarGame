//
// Created by user on 22/12/2017.
//

#include <iostream>
#include <random>
#include "Medic.h"
using namespace std;

void Medic:: attack (Soldier* defender) {
    double distance = p.Distance(defender->getP());
    double damage=10.0;
    if(distance<=1.0)// in the instruction not specified to which distance its should be so we decided....
    {
        if(defender->getBodyArmor()!=nullptr)
        {
            damage=damage*defender->getBodyArmor()->getLevel();
        }
        if(defender->getShieldArmor()!=nullptr)
        {
            damage=damage*defender->getShieldArmor()->getLevel();
        }
        defender->setHP(defender->getHP() - damage);
    }
    cout << "defender.getHP: " << defender->getHP() << endl;
}
void Medic::cure(Soldier *patient) {
    if(Medic::getId()!=patient->getId()) {
        double distance = p.Distance(patient->getP());
        if (patient->getPlayer() == Medic::getPlayer() && distance < 4.0) {
            patient->setHP(patient->getMAXHP());
        }
    }
}
void Medic::toString(ostream& out)const {
    out<<" <- Medic ";
}

double Medic::getMAXHP()  {
    return Soldier::maxHP;
}
/*void Medic:: move (Point2d* target)
{
}*/