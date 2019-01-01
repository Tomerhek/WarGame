//
// Created by Shahar on 26/12/2017.
//

#ifndef WARGAME_COLLECTABLE_H
#define WARGAME_COLLECTABLE_H


#include "Point2d.h"

class Collectable {
protected:
    Point2d p1;
    virtual void toString(std:: ostream& out)const;

public:
    Collectable (Point2d p) : p1(p){};
    Collectable(const Collectable &s);

    Collectable();


    //bool operator==(const Soldier& other) ;
    friend std:: ostream& operator<<(std:: ostream& out, const Collectable& s);
    virtual ~Collectable();
};


#endif //WARGAME_COLLECTABLE_H
