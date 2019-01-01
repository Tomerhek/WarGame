//
// Created by Shahar on 26/12/2017.
//

#include <iostream>
#include "Game.h"
#include "Medic.h"
#include <cmath>
using namespace std;

Game:: Game(){}

void Game::initialize(){
    paths_files_players_move.push_back("player1_file_example.csv");
    fileParsing *fp = new fileParsing("init_file_example.csv");
    fp->read();
    vector<string> *file_v = new vector<string>(fp->getFile());

    int players_num;
    int soldiers_num;
    vector<string>::iterator it = file_v->begin();
    it++;
    string s = *it;
    vector<string> spliter = split(s,',');
    X = stod(spliter[1]);
    Y = stod(spliter[2]);
    it++;
    s = *it;
    spliter.clear();
    spliter = split(s,',');
    players_num = stod(spliter[1]);
    it++;
    s = *it;
    spliter.clear();
    spliter = split(s,',');
    soldiers_num = stod(spliter[1]);
    //cout << "x:" << X << " y:" << Y << " player n:" << players_num << " soldiers n:" << soldiers_num << endl;

    for(int i=0 ; i<players_num ; i++){
        //cout << "i: " << i << endl;
        it++;
        s = *it;
        spliter.clear();
        spliter = split(s,',');
        Strategy *strategy;
        if(spliter[1] == "human\r")
            strategy = new Human();
        else
            strategy = new Computer();

        map <Point2d*,Soldier*> *soldiers1 = new map<Point2d*,Soldier*>;
        Player *player = new Player(i+1, strategy, *soldiers1);
        players.push_back(player);
        //cout << "inside init first loop" << endl;
        for (int j = 0; j < soldiers_num; j++) {
            //cout << "j: " << j << endl;
            it++;
            s = *it;
            spliter.clear();
            spliter = split(s,',');
            Point2d *p = new Point2d(*pointGenerator(spliter[1]));

//            Weapon *weapon;
//            if(spliter.size() == 3)
//                weapon = (weaponGenerator(spliter[2], p));
            //Weapon *weapon;
            //to delete?
            Weapon *weapon;
            if(spliter.size() == 3) {
                if(spliter[2] == "M16\r")
                    weapon = new M16(*p);
                else if (spliter[2] == "UZI\r")
                    weapon = new UZI(*p);
                else if (spliter[2] == "Missile\r")
                    weapon = new Missile(*p);
            }

            Soldier *soldier;
            if(spliter[0] == "normal")
                soldier = new Trooper(*p, weapon, i+1,j+1);
            else if(spliter[0] == "paramedic")
                soldier = new Medic(*p, i+1,j+1);
            else if(spliter[0] == "sniper")
                soldier = new Sniper(*p, weapon,i+1,j+1);

            player->addSoldier(p, soldier);
            Game::soldiers[p] = soldier;
        }
    }

    it++; // pass over the line "Objects"

    //while(it < file_v->end()){
    for(; it != file_v->end() ; it++){
        //it++;
        s = *it;
        spliter.clear();
        spliter = split(s,',');

        if(spliter[0] == "weapon"){
            Point2d *p_ = new Point2d(*pointGenerator(spliter[2]));
            Weapon *weapon_;
            if(spliter[1] == "M16")
                weapon_ = new M16(*p_);
            else if (spliter[1] == "UZI")
                weapon_ = new UZI(*p_);
            else if (spliter[1] == "Missile")
                weapon_ = new Missile(*p_);
            Game::collectables[p_] = weapon_;
        }

        else if(spliter[0] == "Armor"){
            Point2d *p_ = new Point2d(*pointGenerator(spliter[3]));
            Protection *protection;
            if(spliter[1] == "BodyArmor")
                protection = new BodyArmor(*p_,atof(spliter[2].c_str()));
            else if(spliter[1] == "ShieldArmor")
                protection = new ShieldArmor(*p_,atof(spliter[2].c_str()));
            Game::collectables[p_] = protection;
        }

        else if(spliter[0] == "solid"){
            Point2d *p_ = new Point2d(*pointGenerator(spliter[4]));
            Obstacle *obstacle;
            if(spliter[1] == "Tree")
                obstacle = new Tree(*p_, atof(spliter[2].c_str()), atof(spliter[3].c_str()));
            Game::obstacles[p_] = obstacle;
        }
    }

    //initialize human players moves
    vector<string>::iterator iter = paths_files_players_move.begin();
    for(auto p:Game::players){
        cout<< "p->getStrategy()->getName(): " << p->getStrategy()->getName() << endl;
        if(p->getStrategy()->getName() == "Human"){
            cout << "!!!!!!!!!!!" << endl;
            FileControl *fc = new FileControl(*iter);
            fc->read();
            dynamic_cast<Human*>(p->getStrategy())->setMovesPerID(fc->getMoves());

            //test
            for(auto x:dynamic_cast<Human*>(p->getStrategy())->getMovesPerID()) {
                cout << "x:" + to_string(x.first) + "\n" << endl;
                for(auto y:x.second)
                    cout << y << endl;
            }
        }
    }

    for(auto s:soldiers)
        cout << *s.second << endl;
    for(auto s:collectables)
        cout << *s.second << endl;
    for(auto s:obstacles)
        cout << *s.second << endl;
}

Point2d* Game::pointGenerator(string s){
    int index_decrease = 2;
    if(s.back() == '\r') //if the soldier is a paramedic or Objects, fix the line string
        index_decrease++;
    s = s.substr(1,s.size()-index_decrease);//get the number without the []
    vector<string> spliter = split(s,' ');
    //cout << "inside pointGene, " << "s:" << s << " spliter[0]:" << spliter[0] << " spliter[1]:" << spliter[1] << endl;
    Point2d *p = new Point2d( atof(spliter[0].c_str()), atof(spliter[1].c_str()));
    return p;
}

vector<string> Game::split(string s_it, char c){
    stringstream sm(s_it);
    string s;
    vector<string> spliter;
    while(getline(sm,s,c)){
        spliter.push_back(s);
    }
    return spliter;
}


void Game::print() {
    for(auto elem : soldiers)
    {
        cout <<"Point2d: " << *elem.first << " soldier: " <<*elem.second<< "\n";
    }
    for(auto elem : collectables)
    {
        cout <<"Point2d: " << *elem.first << " collectable: " <<*elem.second<< "\n";
    }
    for(auto elem : obstacles)
    {
        cout <<"Point2d: " << *elem.first << " obstacle: " <<*elem.second<< "\n";
    }
}
void Game:: cure (Medic* medic,Soldier* patient)
{
    medic->cure(patient);
}
void Game:: attack (Soldier* attacker,Soldier* defender)
{
    Point2d pTemp(*cleanLine (&attacker->getP(),&defender->getP()));
    if(pTemp.getX()==-1.0 && pTemp.getY()==-1.0)
    {
        attacker->attack(defender);
    }
}
void Game:: move (Soldier* soldier,Point2d* target)
{
    Point2d pTemp(*cleanLine (&soldier->getP(),target));
    if(pTemp.getX()==-1.0 && pTemp.getY()==-1.0)
    {
        soldier->move(target);
    }
    else
    {
        soldier->move(&pTemp);
    }
}

Game::~Game(){

}
Point2d* Game:: cleanLine (Point2d* start, Point2d* target)
{
    Point2d *mid= new Point2d((start->getX()+target->getX())/2,(start->getY()+target->getY())/2);
    while (start->Distance(*mid)>2.0)// min length of obstacle
    {
        for(auto o : obstacles)
        {
            if ((mid->getX()>=o.second->getP1()->getX()&& mid->getX()<=o.second->getP2().getX()) || (mid->getY()>=o.second->getP1()->getY()&& mid->getY()<=o.second->getP2().getY()))
            {
                while((mid->getX()>=o.second->getP1()->getX()&& mid->getX()<=o.second->getP2().getX()) && (mid->getY()>=o.second->getP1()->getY()&& mid->getY()<=o.second->getP2().getY()))
                {
                    mid->setX((start->getX()+mid->getX())/2);
                    mid->setY((start->getY()+mid->getY())/2);
                    cout<<"mid: "<<*mid<<endl;
                }
                return mid;
            }
        }
        mid->setX((start->getX()+mid->getX())/2);
        mid->setY((start->getY()+mid->getY())/2);
    }
    for(auto o : obstacles)
    {
        if ((mid->getX()>=o.second->getP1()->getX()&& mid->getX()<=o.second->getP2().getX()) || (mid->getY()>=o.second->getP1()->getY()&& mid->getY()<=o.second->getP2().getY()))
        {
            return mid;
        }
    }
    mid->setX(-1.0);//have cleanLine
    mid->setY(-1.0);//have cleanLine

}

void Game:: startGame(int turns)
{
    int turn=1;
    map<Soldier*,Point2d*> moveTargets;
    map<Soldier*,Soldier*> shootTargets;
    map<Medic*,Soldier*> cureTargets;
    vector<Soldier*> patients;
    vector<Soldier*>enemies;
    while(turn<turns)
    {
        for(auto p:Game::players)
        {
            moveTargets= p->moveSoldiers(Game::X,Game::Y);
            for(auto m: moveTargets)
            {
                m.first->move(m.second);
            }
            enemies.clear();
            patients.clear();
            for(auto soldier:Game::soldiers)
            {
                if(soldier.second->getPlayer()!=p->getPlayer())
                {
                    enemies.push_back(soldier.second);
                }
                else
                {
                    patients.push_back(soldier.second);
                }
            }
            shootTargets=p->findShootTargets(enemies);
            for(auto a: shootTargets)
            {
                a.first->attack(a.second);
            }
            cureTargets=p->findCureTargets(patients);
            for(auto a: cureTargets)
            {
                a.first->cure(a.second);
            }

        }
        turn++;
    }
}

double Game::getX() const {
    return X;
}

double Game::getY() const {
    return Y;
}

const map<Point2d *, Soldier *> &Game::getSoldiers() const {
    return soldiers;
}

const map<Point2d *, Collectable *> &Game::getCollectables() const {
    return collectables;
}

const map<Point2d *, Obstacle *> &Game::getObstacles() const {
    return obstacles;
}

const vector<Player *> &Game::getPlayers() const {
    return players;
}

const vector<string> &Game::getPaths_files_players_move() const {
    return paths_files_players_move;
}
void Game:: addObstacle (Obstacle* o)
{
    Game::obstacles[o->getP1()]=o;
}
