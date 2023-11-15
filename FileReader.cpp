#include <vector>
#include <string>
#include <fstream>

#include "FileReader.h"

std::vector<std::string>* FileReader::readFile(const std::string fileName){
    std::vector<std::string>* lines = new std::vector<std::string>();
    std::ifstream fileIn(fileName);
    
    if(fileIn){
        std::string line;
        while (std::getline(fileIn, line)){
            lines->push_back(line);
        }
        fileIn.close();    
    }

    return lines;
}