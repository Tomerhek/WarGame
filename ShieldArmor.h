//
// Created by user on 22/12/2017.
//

#ifndef WARGAME_SHIELDARMOR_H
#define WARGAME_SHIELDARMOR_H

#include "Protection.h"

class ShieldArmor : public Protection
{


protected:
    void toString(std:: ostream& out)const;// was virtual
public:
    ShieldArmor (Point2d p ,double level) : Protection(p,level){};
    ShieldArmor(const ShieldArmor &s);

    ShieldArmor();

    //void toString(std:: ostream& out)const;
    //bool operator==(const Soldier& other) ;
    friend std:: ostream& operator<<(std:: ostream& out, const ShieldArmor& s);
    virtual ~ShieldArmor();

};



#endif //WARGAME_SHIELDARMOR_H
