#include <string>
#include <sstream>

#include "LineParser.h"
#include "Crawler.h"
#include "Jitter.h"
#include "SuperBug.h"
#include "Direction.h"

const char LINE_TERMINATOR = ';';

Bug* LineParser::parseLine(std::string line){
    std::string temp;
    std::stringstream sStream(line);
    
    std::getline(sStream, temp, LINE_TERMINATOR);
    char c = temp[0];

    switch(c){
        case 'C':{
            Crawler* crawler = new Crawler();
            parseBugInfo(crawler, &sStream);
            return crawler;
            break;
        }
        case 'H':{
            Hopper* hopper = new Hopper();
            parseBugInfo(hopper, &sStream);
            parseHopLength(hopper, &sStream);
            return hopper;
            break;
        }
        case 'J':{
            Jitter* jitter = new Jitter();
            parseBugInfo(jitter, &sStream);
            return jitter;
            break;
        }
        case 'S':{
            SuperBug* super = new SuperBug();
            parseBugInfo(super, &sStream);
            return super;
            break;
        }
    }
    return nullptr;
}

void LineParser::parseBugInfo(Bug* bug, std::stringstream* sStream){
    std::string temp;

    //Bug ID
    std::getline(*sStream, temp, LINE_TERMINATOR);
    bug->setId(std::stoi(temp));

    //Bug Position
    std::getline(*sStream, temp, LINE_TERMINATOR);
    int x = std::stoi(temp);
    std::getline(*sStream, temp, LINE_TERMINATOR);
    int y = std::stoi(temp);
    bug->setPosition(std::pair<int, int>(x, y));

    //Bug Durection
    std::getline(*sStream, temp, LINE_TERMINATOR);
    int direction = std::stoi(temp);
    switch(direction){
        case 1:{
            bug->setDirection(Direction::NORTH);
            break;
        }
        case 2:{
            bug->setDirection(Direction::EAST);
            break;
        }
        case 3:{
            bug->setDirection(Direction::SOUTH);
            break;
        }
        case 4:{
            bug->setDirection(Direction::WEST);
            break;
        }
    }

    //Bug Size
    std::getline(*sStream, temp, LINE_TERMINATOR);
    bug->setSize(std::stoi(temp));
}

void LineParser::parseHopLength(Hopper* hopper, std::stringstream* sStream){
    std::string temp;

    std::getline(*sStream, temp, LINE_TERMINATOR);
    hopper->setHopLength(std::stoi(temp));
}