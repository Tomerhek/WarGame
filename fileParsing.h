//
// Created by tomer on 28/12/17.
//

#ifndef WARGAME_FILEPARSING_H
#define WARGAME_FILEPARSING_H

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include "Point2d.h"


class fileParsing
{
private:
    std::string path;
    std::vector<std::string> file_v;
public:
    fileParsing(std::string path) : path(path){};
    void read();
    std::vector<std::string> getFile();
    virtual ~fileParsing();
};


#endif //WARGAME_FILEPARSING_H
