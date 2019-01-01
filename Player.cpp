//
// Created by user on 27/12/2017.
//

#include "Player.h"
using namespace std;
void Player:: markAsMine()
{
    for(auto elem : soldiers)
    {
        elem.second->setPlayer(player);
    }

}
map<Medic*,Soldier*> Player:: findCureTargets(vector<Soldier*> patients)
{
    map<Medic*,Soldier*>cureTargets;
    for(auto elem : soldiers)
    {
        if(elem.second->getMAXHP()==120.0)//only medic....
        {
            cureTargets[(Medic*)elem.second]=Player::strategy->getPatient(patients);
        }

    }
    return cureTargets;

}

map<Soldier*,Soldier*> Player:: findShootTargets(vector<Soldier*> enemies)
{
    map<Soldier*,Soldier*>shootTargets;
    for(auto elem : soldiers)
    {
        shootTargets[elem.second]=Player::strategy->getAttacks(enemies);
    }
    return shootTargets;

}

map<Soldier*,Point2d*> Player:: moveSoldiers(double x,double y)
{
    map<Soldier*,Point2d*> targets;
    for(auto elem : soldiers)
    {
        targets[elem.second]=Player::strategy->getMove(elem.second->getId(),x,y);
        //elem.second->move(Player::strategy->getMove(elem.second->getId()));
    }
    return targets;
}

int Player::getPlayer() const {
    return player;
}

const map<Point2d *, Soldier *> &Player::getSoldiers() const {
    return soldiers;
}

void Player::addSoldier(Point2d *p, Soldier *s){
    Player::soldiers[p] = s;
}

Strategy *Player::getStrategy() const {
    return strategy;
}
