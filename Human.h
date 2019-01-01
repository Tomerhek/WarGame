//
// Created by user on 27/12/2017.
//

#ifndef WARGAME_HUMEN_H
#define WARGAME_HUMEN_H

#include <vector>
#include "Strategy.h"

class Human: public Strategy// must implements getMoves
{
protected:
    std::map<int, std::vector<Point2d>> movesPerID;
public:
    Human(){};
    Point2d* getMove(int id,double x,double y);
    Soldier* getAttacks(std::vector<Soldier*> enemies);
    Soldier* getPatient(std::vector<Soldier*> patients);
    std::string getName();
    const std::map<int, std::vector<Point2d>> &getMovesPerID() const;
    void setMovesPerID(const std::map<int, std::vector<Point2d>> &movesPerID);

};


#endif //WARGAME_HUMEN_H
