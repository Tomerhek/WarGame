//
// Created by user on 27/12/2017.
//

#ifndef WARGAME_COMPUTER_H
#define WARGAME_COMPUTER_H


#include "Strategy.h"

class Computer : public Strategy
{
public:
    //std::map<Soldier*, std::vector<Point2d>> getMoves(std::map<Point2d *, Soldier *> soldiers);
    Computer(){};
    Point2d* getMove(int id,double x,double y);
    Soldier* getAttacks(std::vector<Soldier*> enemies);
    Soldier* getPatient(std::vector<Soldier*> patients);
    std::string getName();
};


#endif //WARGAME_COMPUTER_H
