//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_PROTECTION_H
#define WARGAME_PROTECTION_H


#include <ostream>
#include "Point2d.h"
#include "Collectable.h"

class Protection : public Collectable
{

protected:
    Point2d p;
    double level;

    virtual void toString(std:: ostream& out)const=0;



public:
    Protection (Point2d p,double level) : p(p), level (level){};
    Protection(const Protection &s);

    Protection();

    Point2d* getP() ;

    double getLevel() const;

    //bool operator==(const Soldier& other) ;
    friend std:: ostream& operator<<(std:: ostream& out, const Protection& s);
    virtual ~Protection();

    void setP(const Point2d &p);

};


#endif //WARGAME_PROTECTION_H
