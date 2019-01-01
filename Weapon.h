//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_WEAPON_H
#define WARGAME_WEAPON_H


#include "Point2d.h"
#include "Collectable.h"

class Weapon: public Collectable
{
protected:
    Point2d p;
    double damage;
    int shotsPerTurn;
    int type;//0-light,1-heavy

    virtual void toString(std:: ostream& out)const;



public:
    Weapon (double x,double y,double damage,int shotsPerTurn,int type) : p(x,y),damage (damage),shotsPerTurn(shotsPerTurn),type(type){};
    Weapon (Point2d p,double damage,int shotsPerTurn,int type) : p(p),damage (damage),shotsPerTurn(shotsPerTurn), type(type){};
    Weapon(const Weapon &w);
    Weapon();


    //bool operator==(const Soldier& other) ;
    friend std:: ostream& operator<<(std:: ostream& out, const Weapon* s);
    virtual ~Weapon();

    double getDamage() const;

    Point2d* getP() ;

    int getShotsPerTurn() const;

    int getType() const;
};


#endif //WARGAME_WEAPON_H
