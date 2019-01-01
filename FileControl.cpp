//
// Created by tomer on 29/12/17.
//

#include "FileControl.h"

using namespace std;

void FileControl::read(){
    ifstream file(FileControl::path);
    string line;
    getline(file, line, '\r');
    if(line != "Player")
        cout << "Bad moves file!" << endl;
    else {
        int id = 1;
        while (file.good()) {
            getline(file, line, '\r');
            vector<string> line_v = split(line, ',');
            vector<Point2d> points_to_move;
            for(auto v:line_v){
                Point2d *p = new Point2d(*pointGenerator(v));
                points_to_move.push_back(*p);
            }
            moves[id] = points_to_move;
            id++;
        }
    }
}

vector<string> FileControl::split(string s_it, char c){
    stringstream sm(s_it);
    string s;
    vector<string> spliter;
    while(getline(sm,s,c)){
        spliter.push_back(s);
    }
    return spliter;
}

Point2d* FileControl::pointGenerator(string s){
   //cout << "inside pointGene(fc), s:" << s << endl;
    int index_decrease = 2;
    int index_start = 1;
    if(s.back() == '\r') //if the point is the last in the raw
        index_decrease++;
    if(s[0] == '\n') //if the point is the first in the raw
        index_start = 2;
    s = s.substr(index_start,s.size()-index_decrease);//get the number without the []
    vector<string> spliter = split(s,' ');
    //cout << "inside pointGene, " << "s:" << s << " spliter[0]:" << spliter[0] << " spliter[1]:" << spliter[1] << endl;
    Point2d *p = new Point2d( atof(spliter[0].c_str()), atof(spliter[1].c_str()));
    return p;
}

FileControl::~FileControl(){}

const map<int, vector<Point2d>> &FileControl::getMoves() const {
    return moves;
}
