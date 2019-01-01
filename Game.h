//
// Created by Shahar on 26/12/2017.
//

#ifndef WARGAME_GAME_H
#define WARGAME_GAME_H

#include <memory>
#include <map>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "Point2d.h"
#include "Collectable.h"
#include "Soldier.h"
#include "Obstacle.h"
#include "Tree.h"
#include "fileParsing.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "M16.h"
#include "UZI.h"
#include "Missile.h"
#include "BodyArmor.h"
#include "ShieldArmor.h"
#include "Trooper.h"
#include "Medic.h"
#include "Sniper.h"
#include "FileControl.h"


class Game
{
private:
    double X;
    double Y;
protected:
    std::map <Point2d*,Soldier*> soldiers;
    std::map <Point2d*,Collectable*> collectables;
    std::map <Point2d*,Obstacle*> obstacles;
    std::vector<Player*> players;
    std::vector<std::string> paths_files_players_move;

public:
    //Game (std::map <Point2d*,Soldier*> soldiers, std::map <Point2d*,Collectable *> collectables, std::map <Point2d*,Obstacle*> obstacles,const double X,const double Y ) : soldiers(soldiers),collectables(collectables),obstacles(obstacles),X(X),Y(Y){};

    Game();

    void initialize();
    std::vector<std::string> split(std::string s_it, char c);
    Point2d* pointGenerator(std::string s);

    void print ();
    virtual ~Game();
    void attack (Soldier* attacker,Soldier* defender);
    void move (Soldier* soldier,Point2d* target);
    void cure (Medic* medic,Soldier* patient);
    Point2d* cleanLine (Point2d* start, Point2d* target);
    void addObstacle (Obstacle* o);

    void startGame(int turns);

    double getX() const;

    double getY() const;

    const std::map<Point2d *, Soldier *> &getSoldiers() const;

    const std::map<Point2d *, Collectable *> &getCollectables() const;

    const std::map<Point2d *, Obstacle *> &getObstacles() const;

    const std::vector<Player *> &getPlayers() const;

    const std::vector<std::string> &getPaths_files_players_move() const;
};


#endif //WARGAME_GAME_H
