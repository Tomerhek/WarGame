//
// Created by user on 27/12/2017.
//

#ifndef WARGAME_PLAYER_H
#define WARGAME_PLAYER_H


#include "Strategy.h"
#include "Human.h"
#include "Computer.h"
#include "Medic.h"

class Player
{
protected:
    int player;
    Strategy* strategy;
    std::map <Point2d*,Soldier*> soldiers;

public:
    Player (int player, Strategy* strategy, std::map <Point2d*,Soldier*> soldiers):
    player(player), strategy(strategy), soldiers(soldiers){};

    virtual ~Player() { }
    void markAsMine();
    std:: map<Soldier*,Soldier*> findShootTargets(std:: vector<Soldier*> enemies);
    std::map<Soldier*,Point2d*> moveSoldiers(double x,double y);
    std:: map<Medic*,Soldier*> findCureTargets(std:: vector<Soldier*> patients);

    int getPlayer() const;

    const std::map<Point2d *, Soldier *> &getSoldiers() const;
    void addSoldier(Point2d *p, Soldier *s);
    Strategy *getStrategy() const;

};


#endif //WARGAME_PLAYER_H
