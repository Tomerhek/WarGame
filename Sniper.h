//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_SNIPER_H
#define WARGAME_SNIPER_H

#include "Soldier.h"
#include "Weapon.h"

class Sniper : public Soldier
{
private:
    //double MAXHP=80.0;
protected:
    Weapon* weapon;

public:
    Sniper (Point2d p,Weapon* weapon,int player, int id) : Soldier(80.0,2.0,player,p,id),weapon(weapon){};
    Sniper(const Sniper &s);
    void attack (Soldier* defender);
    void toString(std::ostream& out)const;
    double getMAXHP() ;
    void move (Point2d* target);
    Sniper();


};


#endif //WARGAME_SNIPER_H
