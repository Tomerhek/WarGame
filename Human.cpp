//
// Created by user on 27/12/2017.
//

#include "Human.h"
using namespace std;
Point2d* Human::getMove(int id,double x,double y)
{

}
void Human::setMovesPerID(const std::map<int, std::vector<Point2d>> &movesPerID) {
    Human::movesPerID = movesPerID;
}

const std::map<int, std::vector<Point2d>> &Human::getMovesPerID() const {
    return movesPerID;
}
Soldier* Human:: getAttacks(std::vector<Soldier*> enemies)
{

}

Soldier* Human:: getPatient(std::vector<Soldier*> patients)
{

}
string Human::getName(){
    return "Human";
}