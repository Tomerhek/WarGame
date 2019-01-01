//
// Created by user on 21/12/2017.
//

#ifndef WARGAME_SOLDIER_H
#define WARGAME_SOLDIER_H


#include <ostream>
#include "Point2d.h"

#include "BodyArmor.h"
#include "ShieldArmor.h"

class Soldier
{
protected:
    int id;
    double HP;
    double maxHP;
    double maxSpeed;
    //double aim;
    int player;//between 1-4
    Point2d p;
    Point2d dest;
    BodyArmor* bodyArmor;
    ShieldArmor* shieldArmor;
    virtual void toString(std:: ostream& out)const=0;


public:
    Soldier (double HP,double maxSpeed,int player, Point2d p, int id) : HP(HP),maxHP(HP),maxSpeed(maxSpeed) ,player(player), p(p),bodyArmor(nullptr),shieldArmor(nullptr),id(id){};
    Soldier(const Soldier &s);

    Soldier();

    int getPlayer() const;

    //bool operator==(const Soldier& other) ;
    friend std:: ostream& operator<<(std:: ostream& out, const Soldier& s);
    virtual ~Soldier();
    virtual double getMAXHP()=0;
    virtual void attack (Soldier* defender)=0;
    virtual void move (Point2d* target);//=0?
    void setHP(double HP);
    virtual void update_Items();
    void setPlayer(int player);

    double getHP() const;

    Point2d &getP() ;

    BodyArmor *getBodyArmor() const;

    void setBodyArmor(BodyArmor *bodyArmor);

    ShieldArmor *getShieldArmor() const;

    void setShieldArmor(ShieldArmor *shieldArmor);

    void setP(const Point2d &p);

    const Point2d &getDest() const;

    void setDest(const Point2d &dest);

    int getId() const;

    void setId(int id);
};


#endif //WARGAME_SOLDIER_H
