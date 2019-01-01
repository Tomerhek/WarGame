//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_ROCK_H
#define WARGAME_ROCK_H


#include "Point2d.h"
#include "Obstacle.h"

class Tree : public Obstacle
{
protected:

    virtual void toString(std:: ostream& out)const;



public:
    Tree (Point2d p1,double orech,double rohav) : Obstacle(p1,orech,rohav){};
    Tree(const Tree &t);

    Tree();


    //bool operator==(const Soldier& other) ;
    friend std:: ostream& operator<<(std:: ostream& out, const Tree& s);
    virtual ~Tree();

};


#endif //WARGAME_ROCK_H
