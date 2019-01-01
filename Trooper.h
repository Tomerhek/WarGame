//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_TROOPER_H
#define WARGAME_TROOPER_H


#include "Soldier.h"
#include "Weapon.h"

class Trooper : public Soldier
{
private:
    //double MAXHP=100.0;
protected:
Weapon* weapon;


public:
    Trooper (Point2d p,Weapon* weapon,int player,int id) : Soldier(100.0,2.0,player,p,id),weapon(weapon){};
    Trooper(const Trooper &t);
    void attack (Soldier* defender);
    void toString(std::ostream& out)const;
    void run(double ratio,int diraction);
    void move (Point2d* target);
    Trooper();

    double getMAXHP() ;

};


#endif //WARGAME_TROOPER_H
