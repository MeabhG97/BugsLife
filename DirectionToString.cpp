#include "DirectionToString.h"

std::string DirectionToString::toString(Direction* direction){
    std::string str = "";
    switch (*direction){
        case Direction::NORTH : {
            str = "North";
            break;
        }
        case Direction::EAST : {
            str = "East";
            break;
        }
        case Direction::SOUTH : {
            str = "South";
            break;
        }
        case Direction::WEST : {
            str = "West";
            break;
        }
    }
    return str;
}