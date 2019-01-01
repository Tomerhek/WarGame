//
// Created by user on 27/12/2017.
//

#ifndef WARGAME_STRATEGY_H
#define WARGAME_STRATEGY_H

#include <map>
#include <vector>
#include "Point2d.h"
#include "Soldier.h"


class Strategy {
    public:
    virtual Point2d* getMove(int id,double x,double y)=0;
    virtual Soldier* getAttacks(std::vector<Soldier*> enemies)=0;
    virtual Soldier* getPatient(std::vector<Soldier*> patients)=0;
    virtual std::string getName()=0;

};


#endif //WARGAME_STRATEGY_H
