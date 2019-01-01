#include <iostream>
#include <memory>
#include <map>
#include "Point2d.h"
#include "M16.h"
#include "Game.h"
#include "Trooper.h"
#include "Sniper.h"
#include "Medic.h"
#include "Tree.h"


using namespace std;
int main()
{
    std::cout << "Hello, World!" << std::endl;
    //map <Point2d*,void *> b;

    std::map <Point2d*,Soldier*> soldiers;
    std::map <Point2d*,Collectable*> collectables;
    std::map <Point2d*,Obstacle*> obstacles;

    Point2d *p1=new Point2d(1.0,4.0);
    Point2d *p2=new Point2d(2.0,2.0);

    M16 *m16=new M16(*p1);
    M16 *m2=new M16(*p2);
    Trooper *trooper1=new Trooper(*p1,m16,1,1);
    Trooper *trooper2=new Trooper(*p2,m16,2,1);
    cout<<*trooper2<<endl;
    trooper1->attack(trooper2);
    cout<<*trooper2<<endl;
    cout<<m16<<endl;
    cout<<m2<<endl;

    Sniper *sniper=new Sniper(*p1,m16,1,2);
    Sniper *sniper2=new Sniper(*p2,m16,2,2);
    cout<<*sniper2<<endl;
    sniper->attack(sniper2);
    cout<<*sniper2<<endl;
    BodyArmor *ba=new BodyArmor(*p1,0.75);
    sniper2->setBodyArmor(ba);
    cout<<*ba<<endl;
    cout<<*sniper2<<endl;
    sniper->attack(sniper2);
    cout<<*sniper2<<endl;
    Medic *medic=new Medic(*p1,2,3);
    medic->cure(sniper2);
  cout<<*sniper2<<endl;


  Point2d *p4=new Point2d(2.0,2.0);
  Point2d *p5=new Point2d(4.0,1.0);
  Tree *tree=new Tree (*p4,4,4);
  //obstacles[p1]=tree;
  //Game *game =new Game(soldiers,collectables,obstacles,100,100);
  Game *game =new Game();
  game->initialize();
  game->addObstacle(tree);
  Point2d *p3= new Point2d(*game->cleanLine(&sniper->getP(),p5));
  cout<<*p3<<endl;
  cout<<"sniper before move: "<<endl;
  cout<<sniper->getP()<<endl;
  sniper->move(p3);
  cout<<"sniper now here: "<<endl;
  cout<<sniper->getP()<<endl;
  /*collectables [&p2]=m2;
  collectables [p1]=m16;
  cout<<&collectables<<endl;
  Game *game =new Game(soldiers,collectables,obstacles);
  game->print();*/


  return 0;
}