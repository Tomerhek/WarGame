//
// Created by tomer on 29/12/17.
//

#ifndef WARGAME_FILECONTROL_H
#define WARGAME_FILECONTROL_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

#include "Point2d.h"
#include "Soldier.h"

class FileControl {
private:
    std::string path;
    std::map<int, std::vector<Point2d>> moves;
public:
    FileControl(std::string path) : path(path){};
    void read();

    std::vector<std::string> split(std::string s_it, char c);
    Point2d* pointGenerator(std::string s);
    virtual ~FileControl();

    const std::map<int, std::vector<Point2d>> &getMoves() const;
};


#endif //WARGAME_FILECONTROL_H
