#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <utility>
#include <fstream>

#include "FileWriter.h"
#include "Direction.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Jitter.h"
#include "SuperBug.h"
#include "DirectionToString.h"
#include "PathToString.h"
#include "Constants.h"

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

void FileWriter::writeHeadings(std::fstream& file){
    file << setw(ID_WIDTH) << left << BUG_ID
        << setw(TYPE_WIDTH) << left << BUG_TYPE
        << setw(LOCATION_WIDTH) << left << BUG_LOCAION
        << setw(SIZE_WIDTH) << left << BUG_SIZE
        << setw(DIRECTION_WIDTH) << left << BUG_DIRECTION
        << setw(STATUS_WIDTH) << left << BUG_STATUS
        << setw(HOP_WIDTH) << left << BUG_HOP 
    << endl;
}

void FileWriter::writeResults(std::vector<Bug*> bugs){
    std::fstream file;
    file.open(RESULTS_FILE, std::ios::out);
    writeHeadings(file);

    for(Bug* bug : bugs){
        file << setw(ID_WIDTH) << left << bug->getId()
            << setw(TYPE_WIDTH) << left;

        if(dynamic_cast<Crawler*>(bug)){
            file << "Crawler";
        } else if(dynamic_cast<Hopper*>(bug)){
            file << "Hopper";
        } else if(dynamic_cast<Jitter*>(bug)){
            file << "Jitter";
        } else if(dynamic_cast<SuperBug*>(bug)){
            file << "Super";
        }

        file << setw(LOCATION_WIDTH) << left;

        if(bug->getPosition().first == -1 || bug->getPosition().second == -1){
            file << "-----";
        } else{
            file <<"(" + to_string(bug->getPosition().first) + "," + to_string(bug->getPosition().second) + ")";
        }
        
        file << setw(SIZE_WIDTH) << left << bug->getSize()
            << setw(DIRECTION_WIDTH) << left << DirectionToString::toString(bug->getDirection())
            << setw(STATUS_WIDTH) << left;
        
        if(bug->isAlive()){
            file << "Alive";
        } else {
            file << "Dead";
        }

        file << setw(HOP_WIDTH) << left;

        if(dynamic_cast<Hopper*>(bug)){
            Hopper* hop = dynamic_cast<Hopper*>(bug);
            file << hop->getHopLength();
        } else{
            file << "-----";
        }

        file << endl;
    }
    file.close();
}

void FileWriter::writeHistory(std::vector<Bug*> bugs){
    std::fstream file;
    file.open(HISTORY_FILE, std::ios::out);

    for(Bug* bug : bugs){
        file << setw(ID_WIDTH) << left << bug->getId()
            << setw(TYPE_WIDTH) << left;

        if(dynamic_cast<Crawler*>(bug)){
            file << "Crawler";
        } else if(dynamic_cast<Hopper*>(bug)){
            file << "Hopper";
        } else if(dynamic_cast<Jitter*>(bug)){
            file << "Jitter";
        } else if(dynamic_cast<SuperBug*>(bug)){
            file << "Super";
        }
        
        std::list<std::pair<int, int>> path = bug->getPath();
        file << PathToString::toString(&path);

        if(bug->isAlive()){
            file << "Alive";
        } else {
            file << "Eaten by " << to_string(bug->getEatenBy()->getId());
        }

        file << endl;
    }
    file.close();
}
