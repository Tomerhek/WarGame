//
// Created by user on 22/12/2017.
//

#include <iostream>
#include "Trooper.h"
#include <random>
using namespace std;
void Trooper:: attack (Soldier* defender) {
    double damage = Trooper::weapon->getDamage();
    double distance = p.Distance(defender->getP());

    for (int i = 0; i < Trooper::weapon->getShotsPerTurn(); i++)
    {
        random_device seeder;
        mt19937 engine(seeder());
        uniform_int_distribution<int> dist(0, distance-1);
        int rand = dist(engine);
        cout << "rand: " << rand << endl;
        if (rand == 0)
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
            cout << "defender.getHP: " << defender->getHP() << endl;
        }
    }

}

void Trooper::toString(ostream& out)const {
    out<<" <- Trooper with Weapon: "<<weapon;
}

double Trooper::getMAXHP() {
    return Soldier::maxHP;
}
void Trooper::run(double ratio,int direction)
{
    double x=1.0,y=1.0,n=0.0;
    y=ratio*x;
    double a= x+pow(y,2);
    double b= -2*x*Trooper::p.getX()-2*y*Trooper::p.getY();
    double c= pow(Trooper::p.getX(),2)+pow(Trooper::p.getY(),2)-(pow(maxSpeed*2,2));
    double delta= b*b - 4*a*c;
    if (delta > 0) {
        if(direction>0)
        {
            n = (-b + sqrt(delta)) / (2*a);

        } else{
            n = (-b - sqrt(delta)) / (2*a);

        }
    }
    else if (delta == 0) {
        n = (-b + sqrt(delta)) / (2*a);

    }
    Trooper::getP().setX(n);
    Trooper::getP().setY(ratio*n);
    Trooper::setHP(Trooper::getHP()-10.0);

}
void Trooper:: move (Point2d* target)
{
    if(Trooper::getP().Distance(*target)>=maxSpeed*4 && Trooper::getHP()>30.0)
    {
        if(Trooper::getP().getY()==target->getY())
        {
            Trooper::getP().setY(Trooper::getP().getY()+(maxSpeed*2));
        }
        else {
            Trooper::run(Trooper::getP().Ratio(*target), -1 * (int)(Trooper::getP().getY() - target->getY()));
        }
    }
    else
    {
       Soldier::move(target);
    }
    Soldier::update_Items();
    Trooper:: weapon->getP()->setX(Trooper:: getP().getX());
    Trooper:: weapon->getP()->setY(Trooper:: getP().getY());

}

