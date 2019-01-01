//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_BODYARMOR_H
#define WARGAME_BODYARMOR_H

#include "Protection.h"

class BodyArmor : public Protection
{


protected:
     void toString(std:: ostream& out)const;//TODO: check toString
public:
    BodyArmor (Point2d p,double level) : Protection(p,level){};
    BodyArmor(const BodyArmor &b);

    BodyArmor();

    //void toString(std:: ostream& out)const;
    //bool operator==(const Soldier& other) ;
    //friend std:: ostream& operator<<(std:: ostream& out, const BodyArmor& s);
    friend std:: ostream& operator<<(std:: ostream& out, const BodyArmor& s);
    virtual ~BodyArmor();

};




#endif //WARGAME_BODYARMOR_H
