//
// Created by user on 21/12/2017.
//
#include <iostream>
#include "Soldier.h"
#include <cmath>
using namespace std;

Soldier::Soldier(const Soldier &s) {
    HP = s.HP;
    maxSpeed = s.maxSpeed;
    maxHP=s.maxHP;
    player= s.player;
    p=s.p;
    bodyArmor= s.bodyArmor;
    shieldArmor= s.shieldArmor;
    dest=s.dest;
    id=s.id;
}
/*
void Soldier::toString(ostream& out)const {
    out<<"HP: "<<HP<< " maxSpeed: "<<maxSpeed<<" player: "<<player;
}
*/
Soldier::Soldier() {
    HP=100.0;
    maxHP=HP;
    maxSpeed=2.0;
    player=1;
}
/*
bool Soldier::operator==(const Soldier &other) {
    return id==other.id;
}
 */

ostream& operator<<(ostream& out, const Soldier& s)
{
    out<<"HP: " << s.HP << " maxSpeed: " <<s.maxSpeed <<" player: "<<s.player<<" bodyArmor: "<<s.bodyArmor<<" shieldArmor: "<<s.shieldArmor<<" location: "<<s.p;
    s.toString(out) ;
    return out;
}
Soldier::~Soldier(){

}

void Soldier::setPlayer(int player) {
    Soldier::player = player;
}

 Point2d &Soldier::getP()  {
    return p;
}

void Soldier::setHP(double HP) {
    Soldier::HP = HP;
}

double Soldier::getHP() const {
    return HP;
}

int Soldier::getPlayer() const {
    return player;
}

BodyArmor *Soldier::getBodyArmor() const {
    return bodyArmor;
}

void Soldier::setBodyArmor(BodyArmor *bodyArmor) {
    Soldier::bodyArmor = bodyArmor;
}

ShieldArmor *Soldier::getShieldArmor() const {
    return shieldArmor;
}

void Soldier::setShieldArmor(ShieldArmor *shieldArmor) {
    Soldier::shieldArmor = shieldArmor;
}

void Soldier::setP(const Point2d &p) {
    Soldier::p = p;
}

const Point2d &Soldier::getDest() const {
    return dest;
}

void Soldier::setDest(const Point2d &dest) {
    Soldier::dest = dest;
}

void Soldier::move(Point2d *target) {
    double speed;
    if(Soldier:: getHP()<30.0)
    {
        speed=maxSpeed/2;
    } else{
        speed=maxSpeed;
    }
cout<<"target: "<<*target<<" spped: "<< speed<<endl;
    if(Soldier::getP().Distance(*target)>=speed)
    {
        double x=1.0,n=0.0,ratio=Soldier::getP().Ratio(*target),y=ratio*x;
        int direction=-1 * (int)(Soldier::getP().getY() - target->getY());
        double a= x+pow(y,2);
        double b= -2*x*Soldier::p.getX()-2*y*Soldier::p.getY();
        double c= (pow(Soldier::p.getX(),2)+pow(Soldier::p.getY(),2))-(speed*speed);
        double delta= b*b - 4*a*c;
//        cout<<"a: "+to_string(a)<<endl;
//        cout<<"b: "+to_string(b)<<endl;
//        cout<<"c: "+to_string(c)<<endl;
//        cout<<"delta: "+to_string(delta)<<endl;
        if (delta > 0) {
            if(direction>0)
            {
                n = (-b + sqrt(delta)) / (2*a);
            } else{
                n = (-b - sqrt(delta)) / (2*a);
            }
        }
        else if (delta == 0) {
            n = (-b + sqrt(delta)) / (2*a);
        }
        Soldier::getP().setX(n);
        Soldier::getP().setY(ratio*n);
    }
    else
    {
        Soldier::getP().setX(target->getX());
        Soldier::getP().setY(target->getY());

    }
    cout<<"Soldier::getP(): "<<Soldier::getP()<<endl;

}
void Soldier:: update_Items()
{
    if(Soldier::shieldArmor!= nullptr)
    {
        Soldier:: shieldArmor->getP()->setX(Soldier:: getP().getX());
        Soldier:: shieldArmor->getP()->setY(Soldier:: getP().getY());
    }
    if(Soldier::bodyArmor!= nullptr)
    {
        Soldier:: bodyArmor->getP()->setX(Soldier:: getP().getX());
        Soldier:: bodyArmor->getP()->setY(Soldier:: getP().getY());
    }
}

int Soldier::getId() const {
    return id;
}

void Soldier::setId(int id) {
    Soldier::id = id;
}
