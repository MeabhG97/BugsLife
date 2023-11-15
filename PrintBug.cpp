#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <utility>

#include "PrintBug.h"
#include "Direction.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Jitter.h"
#include "SuperBug.h"
#include "DirectionToString.h"
#include "PathToString.h"

const std::string BUG_ID = "ID";
const std::string BUG_TYPE = "Type";
const std::string BUG_LOCAION = "Location";
const std::string BUG_SIZE = "Size";
const std::string BUG_DIRECTION = "Direction";
const std::string BUG_STATUS = "Status";
const std::string BUG_HOP = "Hop Length";

const int ID_WIDTH = 5;
const int TYPE_WIDTH = 10;
const int LOCATION_WIDTH = 10;
const int SIZE_WIDTH = 5;
const int DIRECTION_WIDTH = 10;
const int STATUS_WIDTH = 8;
const int HOP_WIDTH = 12;

using namespace std;

void PrintBug::printHeadings(){
    cout << setw(ID_WIDTH) << left << BUG_ID
        << setw(TYPE_WIDTH) << left << BUG_TYPE
        << setw(LOCATION_WIDTH) << left << BUG_LOCAION
        << setw(SIZE_WIDTH) << left << BUG_SIZE
        << setw(DIRECTION_WIDTH) << left << BUG_DIRECTION
        << setw(STATUS_WIDTH) << left << BUG_STATUS
        << setw(HOP_WIDTH) << left << BUG_HOP 
    << endl;
}

void PrintBug::printBug(Bug* bug){
    cout << setw(ID_WIDTH) << left << bug->getId()
        << setw(TYPE_WIDTH) << left;

    if(dynamic_cast<Crawler*>(bug)){
        cout << "Crawler";
    } else if(dynamic_cast<Hopper*>(bug)){
        cout << "Hopper";
    } else if(dynamic_cast<Jitter*>(bug)){
        cout << "Jitter";
    } else if(dynamic_cast<SuperBug*>(bug)){
        cout << "Super";
    }

    cout << setw(LOCATION_WIDTH) << left;

    if(bug->getPosition().first == -1 || bug->getPosition().second == -1){
        cout << "-----";
    } else{
        cout <<"(" + to_string(bug->getPosition().first) + "," + to_string(bug->getPosition().second) + ")";
    }
    
    cout << setw(SIZE_WIDTH) << left << bug->getSize()
        << setw(DIRECTION_WIDTH) << left << DirectionToString::toString(bug->getDirection())
        << setw(STATUS_WIDTH) << left;
    
    if(bug->isAlive()){
        cout << "Alive";
    } else {
        cout << "Dead";
    }

    cout << setw(HOP_WIDTH) << left;

    if(dynamic_cast<Hopper*>(bug)){
        Hopper* hop = dynamic_cast<Hopper*>(bug);
        cout << hop->getHopLength();
    } else{
        cout << "-----";
    }

    cout << endl;
}

void PrintBug::printHistory(Bug* bug){
    cout << setw(ID_WIDTH) << left << bug->getId()
        << setw(TYPE_WIDTH) << left;

    if(dynamic_cast<Crawler*>(bug)){
        cout << "Crawler";
    } else if(dynamic_cast<Hopper*>(bug)){
        cout << "Hopper";
    } else if(dynamic_cast<Jitter*>(bug)){
        cout << "Jitter";
    } else if(dynamic_cast<SuperBug*>(bug)){
        cout << "Super";
    }
    std::list<std::pair<int, int>> path = bug->getPath();
    cout << PathToString::toString(&path);

    if(bug->isAlive()){
        cout << "Alive";
    } else {
        cout << "Eaten by " << to_string(bug->getEatenBy()->getId());
    }

    cout << endl;
}
