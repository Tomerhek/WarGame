//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_M16_H
#define WARGAME_M16_H


#include "Weapon.h"

class M16 : public Weapon
{
protected:
    //virtual void toString(std:: ostream& out)const;

public:
    M16 (double x,double y,int shotsPerTurnint,int type) : Weapon(x,y,50.0,shotsPerTurn,type){};
    M16 (Point2d p) :Weapon(p,50.0,1,0){};
    M16( M16 &m);

    M16();
    void print();
    friend std:: ostream& operator<<(std:: ostream& out, const M16& s);

};


#endif //WARGAME_M16_H
