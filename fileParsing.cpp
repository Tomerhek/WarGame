//
// Created by tomer on 28/12/17.
//

#include "fileParsing.h"

using namespace std;

void fileParsing::read(){
    ifstream file(fileParsing::path);
    string line;
    while (file.good()) {
        getline(file, line, '\n');
        file_v.push_back(line);
    }
}

std::vector<std::string> fileParsing::getFile(){
    return fileParsing::file_v;
}

fileParsing::~fileParsing(){}