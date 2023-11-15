#include "PathToString.h"

std::string PathToString::toString(std::list<std::pair<int, int>>* path){
    std::string str = "";

    for(std::pair<int, int> pos : *path){
        str += "(";
        str += std::to_string(pos.first);
        str += ",";
        str += std::to_string(pos.second);
        str += "),";
    }
     
    return str;
}