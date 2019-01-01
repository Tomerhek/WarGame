//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_UZI_H
#define WARGAME_UZI_H


#include "Weapon.h"

class UZI : public Weapon
{
protected:
    //virtual void toString(std:: ostream& out)const;
public:
    UZI (double x,double y,double damage,int shotsPerTurn, int type) : Weapon(x,y,damage,shotsPerTurn, type){};
    UZI (Point2d p) :Weapon(p,40.0,3,0){};
    UZI(const UZI &u);
    friend std:: ostream& operator<<(std:: ostream& out, const UZI& s);
    UZI();
};



#endif //WARGAME_UZI_H
