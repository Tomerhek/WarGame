//
// Created by user on 22/12/2017.
//

#include <random>
#include <iostream>
#include "Sniper.h"
using namespace std;

void Sniper:: attack (Soldier* defender) {
    double damage = Sniper::weapon->getDamage();
    double distance = p.Distance(defender->getP());

    for (int i = 0; i < Sniper::weapon->getShotsPerTurn(); i++)
    {
        random_device seeder;
        mt19937 engine(seeder());
        uniform_int_distribution<int> dist(0, distance-1);
        int rand = dist(engine);
        cout << "rand: " << rand << endl;
        if (rand != 0)
        {
            if(Sniper::weapon->getType()==0&&defender->getBodyArmor()!=nullptr)
            {
                damage=damage*defender->getBodyArmor()->getLevel();
                cout << "damage now: " << damage << endl;
            }
            if(defender->getShieldArmor()!=nullptr)
            {
                damage=damage*defender->getShieldArmor()->getLevel();
                cout << "damage now: " << damage << endl;
            }
            defender->setHP(defender->getHP() - damage);
            cout << "defender.getHP: " << defender->getHP() << endl;
        }
    }
}
void Sniper::toString(ostream& out)const {
    out<<" <- Sniper with Weapon: "<<weapon;
}

double Sniper::getMAXHP()  {
    return Soldier::maxHP;
}
void Sniper:: move (Point2d* target)
{
    Soldier::move(target);
    Soldier::update_Items();
    Sniper:: weapon->getP()->setX(Sniper:: getP().getX());
    Sniper:: weapon->getP()->setY(Sniper:: getP().getY());
}