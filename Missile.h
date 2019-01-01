//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_MISSILE_H
#define WARGAME_MISSILE_H


#include "Weapon.h"

class Missile : public Weapon
{
protected:
    //virtual void toString(std:: ostream& out)const;
public:
    Missile (double x,double y,double damage,int shotsPerTurn, int type) : Weapon(x,y,damage,shotsPerTurn,type){};
    Missile (Point2d p) :Weapon(p,100.0,1,1){};
    Missile(const Missile &m);
    friend std:: ostream& operator<<(std:: ostream& out, const Missile& s);
    Missile();
};


#endif //WARGAME_MISSILE_H
