//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_MEDIC_H
#define WARGAME_MEDIC_H

#include "Soldier.h"
class Medic : public Soldier
{
private:
    //double MAXHP=120.0;
protected:

public:
    Medic (Point2d p,int player,int id) : Soldier(120.0,4.0,player,p,id){};
    Medic(const Medic &t);
    void attack (Soldier* defender);
    void cure (Soldier* patient);
    void toString(std::ostream& out)const;
    double getMAXHP() ;
    //void move (Point2d* target);
    Medic();


};


#endif //WARGAME_MEDIC_H
